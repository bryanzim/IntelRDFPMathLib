#!/usr/bin/env python3
"""Add U / ULL to unsigned literals by value width (conservative, syntax-safe)."""

from __future__ import annotations

import re
import sys
from pathlib import Path


def repo_root() -> Path:
    return Path(__file__).resolve().parents[1]


def strip_line_comment(line: str) -> str:
    in_str = False
    quote = ""
    i = 0
    while i < len(line):
        c = line[i]
        if in_str:
            if c == "\\" and i + 1 < len(line):
                i += 2
                continue
            if c == quote:
                in_str = False
            i += 1
            continue
        if c in "\"'":
            in_str = True
            quote = c
            i += 1
            continue
        if c == "/" and i + 1 < len(line) and line[i + 1] == "/":
            return line[:i]
        i += 1
    return line


def hex_width_suffix(token: str) -> str:
    val = int(token[2:], 16)
    if val > 0xFFFFFFFF:
        return token + "ULL"
    return token + "U"


HEX_WIDE = re.compile(
    r"(?<![\w.])(0[xX][0-9a-fA-F]{9,})(?![uUlL0-9a-fA-F])"
)

LIMB_INDEX = re.compile(r"(\.w)\[([0-3])\](?!U\b)")

TABLE_ROW_INDEX = re.compile(
    r"(bid_[a-zA-Z0-9_]+\[)([0-9]{1,2})(\])(?!U)"
)

NR_DIGITS_MINUS_ONE = re.compile(
    r"(x_nr_bits\s*-\s*)1(\])"
)

FLOAT_EXP_HEX = re.compile(
    r"(?<![\w.])(0x7ff|0x3ff|0xff)(?![uUlL0-9a-fA-F])"
)

HEX32 = re.compile(
    r"(?<![\w.])(0[xX][0-9a-fA-F]{1,8})(?![uUlL0-9a-fA-F])"
)

CAST_SHIFT_MASK = re.compile(
    r"\(\(int\)\(([^>]+>>\s*\d+)\)\s*&\s*(0x[0-9a-fA-F]+U)\)"
)


def transform_code(code: str) -> str:
    out: list[str] = []
    in_define = False
    for line in code.splitlines(keepends=True):
        body = strip_line_comment(line)
        tail = line[len(body) :]
        s = body
        if re.match(r"\s*#\s*define\b", s):
            in_define = True
        skip = in_define
        if in_define and not body.rstrip().endswith("\\"):
            in_define = False

        if not skip:

            def hex32_repl(m: re.Match[str]) -> str:
                tok = m.group(1)
                end = m.end()
                if end + 1 < len(s) and s[end : end + 2] == ">>":
                    return tok
                if tok.lower() in ("0x7ff", "0x3ff", "0xff"):
                    return tok + "U"
                return hex_width_suffix(tok)

            s = HEX_WIDE.sub(lambda m: hex_width_suffix(m.group(1)), s)
            s = TABLE_ROW_INDEX.sub(
                lambda m: f"{m.group(1)}{m.group(2)}U{m.group(3)}", s
            )
            s = NR_DIGITS_MINUS_ONE.sub(r"\g<1>1U\2", s)
            s = FLOAT_EXP_HEX.sub(lambda m: m.group(1) + "U", s)
            s = HEX32.sub(hex32_repl, s)
            s = CAST_SHIFT_MASK.sub(r"((int)((\1) & \2))", s)
            s = LIMB_INDEX.sub(lambda m: f"{m.group(1)}[{m.group(2)}U]", s)

        out.append(s + tail)
    return "".join(out)


def targets(root: Path) -> list[Path]:
    src = root / "LIBRARY" / "src"
    globs = [
        "bid32_*.c",
        "bid64_*.c",
        "bid128_*.c",
        "bid_conf.h",
        "bid_inline_add.h",
        "bid_sqrt_macros.h",
        "bid_strtod.h",
        "bid_trans.h",
    ]
    paths: list[Path] = []
    for g in globs:
        paths.extend(src.glob(g))
    return sorted(set(paths))


def main() -> int:
    root = repo_root()
    changed = 0
    for path in targets(root):
        original = path.read_text(encoding="utf-8", errors="surrogateescape")
        updated = transform_code(original)
        if updated != original:
            path.write_text(updated, encoding="utf-8", newline="\n")
            changed += 1
            print(path.relative_to(root))
    print(f"Updated {changed} file(s).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
