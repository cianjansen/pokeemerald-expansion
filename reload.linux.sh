#!/bin/bash
# Linux edit-build-play loop. Native-Ubuntu equivalent of the Mac `./reload`
# and the Windows `reload.ps1` — see the "Toolchain" section of spec.md.
# Any extra args are forwarded straight to `make` (e.g. ./reload.linux.sh OUDERKERK_DEBUG_BLAZIKEN=0).
set -e

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Native Ubuntu's arm-none-eabi-gcc ships newlib, so no devkitARM is needed
# here. Only export DEVKIT* if a devkitPro install actually exists (harmless
# on a box that doesn't have one).
if [ -d "${DEVKITPRO:-/opt/devkitpro}/devkitARM" ]; then
    export DEVKITPRO="${DEVKITPRO:-/opt/devkitpro}"
    export DEVKITARM="${DEVKITARM:-$DEVKITPRO/devkitARM}"
fi

# Porymap rewrites wild_encounters.json, every map.json, and a few other
# project files in full on every save, even when nothing actually changed
# (https://github.com/huderlem/porymap/issues/774). A diff=jsonsorted
# textconv driver is configured on those paths so `git diff` ignores
# reorder-only noise, but `git status`/`git diff --quiet` don't honor
# textconv, so check every modified tracked file's real (non-quiet) diff and
# drop any that come back empty before they can pollute the next commit.
while IFS= read -r f; do
    [ -z "$f" ] && continue
    if [ -z "$(git diff -- "$f" 2>/dev/null)" ]; then
        echo "Discarding no-op rewrite of $f (Porymap save noise)"
        git restore "$f"
    fi
done <<< "$(git diff --name-only)"

make -j"$(nproc)" "$@"

pkill -x mgba-qt 2>/dev/null || true
sleep 0.5
setsid mgba-qt "$(pwd)/pokeemerald.gba" > /dev/null 2>&1 &

echo ""
echo "git status:"
git status --short
