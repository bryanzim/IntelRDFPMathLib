#!/usr/bin/env python3
"""Parallel IntelDFP translation-unit compile check (ClangCL / extra-strict).

Two engines:
  clang  - invoke clang-cl directly (safe for -j > 1; recommended)
  msbuild - cmake + SelectedFiles (serial only; shared .tlog breaks parallel)
"""

from __future__ import annotations

import argparse
import concurrent.futures
import os
import re
import shutil
import subprocess
import sys
from fnmatch import fnmatch
from pathlib import Path


def repo_root() -> Path:
    return Path(__file__).resolve().parents[1]


def list_sources(vcxproj: Path, pattern: str) -> list[Path]:
    text = vcxproj.read_text(encoding="utf-8", errors="replace")
    paths = [Path(m.group(1)) for m in re.finditer(r'ClCompile Include="([^"]+\.c)"', text)]
    if pattern != "*":
        paths = [p for p in paths if fnmatch(p.name, pattern)]
    return sorted(set(paths))


def find_clang_cl() -> Path:
    vswhere = Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")) / "Microsoft Visual Studio" / "Installer" / "vswhere.exe"
    if vswhere.is_file():
        proc = subprocess.run(
            [str(vswhere), "-latest", "-find", "**/x64/bin/clang-cl.exe"],
            capture_output=True,
            text=True,
            check=False,
        )
        for line in proc.stdout.splitlines():
            p = Path(line.strip())
            if p.is_file():
                return p
    found = shutil.which("clang-cl")
    if found:
        return Path(found)
    raise SystemExit("clang-cl not found (install LLVM ClangCL toolset in VS)")


def read_tlog_text(tlog: Path) -> str:
    raw = tlog.read_bytes()
    if raw.startswith(b"\xff\xfe"):
        return raw.decode("utf-16-le")
    if raw.startswith(b"\xfe\xff"):
        return raw.decode("utf-16-be")
    return raw.decode("utf-8", errors="replace")


def msbuild_cl_line_to_argv(line: str) -> list[str]:
    """Turn an MSBuild /c ... line into clang-cl argv (no source path)."""
    line = re.sub(
        r'/D\s+"CMAKE_INTDIR=\\"Debug\\""',
        "/D CMAKE_INTDIR=Debug",
        line,
        flags=re.I,
    )
    parts = line.strip().split()
    if not parts or parts[0] != "/c":
        raise ValueError("not a /c compile line")
    out: list[str] = ["/c"]
    i = 1
    while i < len(parts):
        p = parts[i]
        if p == "/D" and i + 1 < len(parts):
            out.append("/D" + parts[i + 1])
            i += 2
            continue
        if p.startswith("/Fo"):
            i += 1
            continue
        if re.search(r"\.c$", p, re.I):
            break
        out.append(p)
        i += 1
    return out


def load_clang_template(tlog: Path) -> list[str]:
    """Return clang-cl argv prefix (flags before source path) from a .tlog entry."""
    text = read_tlog_text(tlog)
    for line in text.splitlines():
        line = line.strip()
        if not line.startswith("/c "):
            continue
        try:
            return msbuild_cl_line_to_argv(line)
        except ValueError:
            continue
    raise SystemExit(f"Could not parse clang-cl flags from {tlog}")


def compile_clang(
    clang: Path,
    flag_prefix: list[str],
    int_dir: Path,
    obj_dir: Path,
    src: Path,
) -> tuple[Path, int, str]:
    obj = obj_dir / (src.stem + ".obj")
    # flag_prefix is MSBuild-style (/c /I...); clang-cl wants source last.
    cmd = [str(clang), *flag_prefix, f'/Fo{obj}', str(src)]
    proc = subprocess.run(cmd, cwd=int_dir, capture_output=True, text=True)
    out = (proc.stdout or "") + (proc.stderr or "")
    return src, proc.returncode, out


def compile_msbuild(build_dir: Path, config: str, src: Path) -> tuple[Path, int, str]:
    cmd = [
        "cmake",
        "--build",
        str(build_dir),
        "--target",
        "IntelDFP",
        "--config",
        config,
        "--",
        "/t:ClCompile",
        f"/p:SelectedFiles={src}",
        "/v:q",
        "/nologo",
    ]
    proc = subprocess.run(cmd, capture_output=True, text=True)
    out = (proc.stdout or "") + (proc.stderr or "")
    return src, proc.returncode, out


def is_signconv_error(out: str) -> bool:
    return "error :" in out and ("-Wsign-conversion" in out or "signedness" in out)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument(
        "--build-dir",
        type=Path,
        default=repo_root() / "out" / "build" / "x64-Clang-Debug",
    )
    ap.add_argument("--config", default="Debug")
    ap.add_argument("--filter", default="*", help="Glob on basename, e.g. bid128_*")
    ap.add_argument("-j", "--jobs", type=int, default=8)
    ap.add_argument(
        "--engine",
        choices=("clang", "msbuild"),
        default="clang",
        help="msbuild only supports -j 1",
    )
    args = ap.parse_args()

    if args.engine == "msbuild" and args.jobs > 1:
        print("Note: msbuild engine forces -j 1 (shared IntelDFP.tlog).", file=sys.stderr)
        args.jobs = 1

    vcxproj = args.build_dir / "LIBRARY" / "IntelDFP.vcxproj"
    if not vcxproj.is_file():
        print(f"Missing {vcxproj}; run: cmake --preset x64-Clang-Debug", file=sys.stderr)
        return 2

    all_src = list_sources(vcxproj, args.filter)
    if not all_src:
        print(f"No sources for filter {args.filter!r}", file=sys.stderr)
        return 2

    print(f"Checking {len(all_src)} file(s) engine={args.engine} jobs={args.jobs} ...")

    clang = flag_prefix = int_dir = obj_dir = None
    if args.engine == "clang":
        clang = find_clang_cl()
        tlog = args.build_dir / "LIBRARY" / "IntelDFP.dir" / "Debug" / "IntelDFP.tlog" / "clang-cl.command.1.tlog"
        if not tlog.is_file():
            print(f"Missing {tlog}; compile IntelDFP once to generate tlogs.", file=sys.stderr)
            return 2
        flag_prefix = load_clang_template(tlog)
        int_dir = args.build_dir / "LIBRARY" / "IntelDFP.dir" / "Debug"
        obj_dir = args.build_dir / "tu-check-obj"
        obj_dir.mkdir(parents=True, exist_ok=True)

    failed: list[tuple[Path, str]] = []

    def work(src: Path) -> tuple[Path, int, str]:
        if args.engine == "clang":
            assert clang and flag_prefix and int_dir and obj_dir
            return compile_clang(clang, flag_prefix, int_dir, obj_dir, src)
        return compile_msbuild(args.build_dir, args.config, src)

    with concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(work, s) for s in all_src]
        for fut in concurrent.futures.as_completed(futs):
            src, code, out = fut.result()
            if code != 0 or is_signconv_error(out) or (
                code != 0 and "error :" in out and args.engine == "msbuild"
            ):
                err_lines = [ln.strip() for ln in out.splitlines() if "error :" in ln]
                # Ignore MSBuild tracker noise when classifying
                err_lines = [
                    ln
                    for ln in err_lines
                    if "FTK1011" not in ln
                    and "MSB6003" not in ln
                    and "macro name must be an identifier" not in ln
                ]
                if not err_lines and code != 0:
                    err_lines = [out.strip()[:500]]
                if err_lines or code != 0:
                    summary = "\n".join(err_lines[:25])
                    if len(err_lines) > 25:
                        summary += f"\n... ({len(err_lines) - 25} more)"
                    failed.append((src, summary))

    if failed:
        print(f"\nFAILED ({len(failed)} file(s)):\n")
        for src, msg in sorted(failed, key=lambda x: x[0].name):
            print(f"=== {src.name} ===")
            print(msg)
            print()
        return 1

    print(f"OK: all {len(all_src)} translation unit(s) compile.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
