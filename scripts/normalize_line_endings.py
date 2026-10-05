#!/usr/bin/env python3
"""Normalize line endings for git-tracked text files (LF; CRLF for .bat/.cmd)."""

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path


def repo_root() -> Path:
    return Path(__file__).resolve().parents[1]


def tracked_files(root: Path) -> list[str]:
    out = subprocess.check_output(["git", "-C", str(root), "ls-files"], text=True)
    return [ln.strip() for ln in out.splitlines() if ln.strip()]


def is_binary(data: bytes) -> bool:
    return b"\x00" in data


def use_crlf(path: str) -> bool:
    lower = path.lower()
    return lower.endswith(".bat") or lower.endswith(".cmd")


def normalize_bytes(data: bytes, crlf: bool) -> bytes:
    text = data.decode("utf-8", errors="surrogateescape")
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    if crlf:
        text = text.replace("\n", "\r\n")
    return text.encode("utf-8")


def main() -> int:
    root = repo_root()
    changed = 0
    for rel in tracked_files(root):
        path = root / rel
        if not path.is_file():
            continue
        raw = path.read_bytes()
        if is_binary(raw):
            continue
        want_crlf = use_crlf(rel)
        new = normalize_bytes(raw, want_crlf)
        if new != raw:
            path.write_bytes(new)
            changed += 1
            print(rel)
    print(f"Normalized {changed} file(s).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
