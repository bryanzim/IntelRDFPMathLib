#!/usr/bin/env python3
"""Probe IntelDFP TUs for diagnostics still disabled via -Wno in extra-strict tier."""

from __future__ import annotations

import concurrent.futures
import re
import subprocess
import sys
from fnmatch import fnmatch
from pathlib import Path

import importlib.util

_spec = importlib.util.spec_from_file_location(
    "check_inteldfp_tus",
    Path(__file__).resolve().parent / "check-inteldfp-tus.py",
)
assert _spec and _spec.loader
_mod = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(_mod)
compile_clang = _mod.compile_clang
find_clang_cl = _mod.find_clang_cl
list_sources = _mod.list_sources
load_clang_template = _mod.load_clang_template
repo_root = _mod.repo_root

PROBES = [
    ("shorten-64-to-32", "-Wno-shorten-64-to-32", "-Wshorten-64-to-32"),
    ("implicit-int-float-conversion", "-Wno-implicit-int-float-conversion", "-Wimplicit-int-float-conversion"),
    ("sign-compare", None, "-Wsign-compare"),
]


def patch_flags(prefix: list[str], drop: str | None, add: str) -> list[str]:
    out = [f for f in prefix if drop is None or f != drop]
    if add not in out:
        out.append(add)
    return out


def main() -> int:
    build_dir = repo_root() / "out" / "build" / "x64-Clang-Debug"
    vcxproj = build_dir / "LIBRARY" / "IntelDFP.vcxproj"
    sources = list_sources(vcxproj, "bid*.c")
    clang = find_clang_cl()
    tlog = (
        build_dir
        / "LIBRARY"
        / "IntelDFP.dir"
        / "Debug"
        / "IntelDFP.tlog"
        / "clang-cl.command.1.tlog"
    )
    base = load_clang_template(tlog)
    int_dir = build_dir / "LIBRARY" / "IntelDFP.dir" / "Debug"
    obj_dir = build_dir / "tu-probe-obj"
    obj_dir.mkdir(parents=True, exist_ok=True)

    for name, drop, add in PROBES:
        flags = patch_flags(base, drop, add)
        failed: list[tuple[str, int]] = []

        def work(src: Path) -> tuple[Path, int, str]:
            return compile_clang(clang, flags, int_dir, obj_dir, src)

        with concurrent.futures.ThreadPoolExecutor(max_workers=12) as ex:
            futs = {ex.submit(work, s): s for s in sources}
            for fut in concurrent.futures.as_completed(futs):
                src, code, out = fut.result()
                if code != 0 and "error :" in out:
                    n = len([ln for ln in out.splitlines() if "error :" in ln])
                    failed.append((src.name, n))

        print(f"\n=== probe {name} ({add}) ===")
        print(f"FAIL TUs: {len(failed)} / {len(sources)}")
        for fn, n in sorted(failed)[:15]:
            print(f"  {fn}: ~{n} error line(s)")
        if len(failed) > 15:
            print(f"  ... and {len(failed) - 15} more")

    return 0


if __name__ == "__main__":
    sys.exit(main())
