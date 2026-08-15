#!/bin/bash
# One-shot bring-up for a fresh macOS machine: installs the build toolchain
# (devkitARM, which bundles the newlib that Homebrew's bare arm-none-eabi-gcc
# lacks), builds the ROM, and fetches Porymap for map editing.
set -e

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$REPO_DIR"

echo "==> Installing Homebrew dependencies..."
brew install libpng pkg-config
brew install --cask mgba-app

if [ ! -d /opt/devkitpro/devkitARM ]; then
    echo "==> devkitARM not found."
    echo "    Homebrew has no devkitPro tap, so this needs the official installer:"
    echo "      1. Download: https://github.com/devkitPro/pacman/releases/latest/download/devkitpro-pacman-installer.pkg"
    echo "      2. Open and run the .pkg installer"
    echo "      3. Run (needs your password):"
    echo "           sudo dkp-pacman -Sy"
    echo "           sudo dkp-pacman -S gba-dev devkitarm-rules"
    echo "    Then add to your shell profile:"
    echo "           export DEVKITPRO=/opt/devkitpro"
    echo "           export DEVKITARM=\$DEVKITPRO/devkitARM"
    echo "    Re-run this script once that's done."
    exit 1
fi

export DEVKITPRO=/opt/devkitpro
export DEVKITARM="$DEVKITPRO/devkitARM"

echo "==> Building pokeemerald.gba..."
make -j"$(sysctl -n hw.ncpu)"

echo "==> Installing Porymap..."
if [ ! -d /Applications/porymap.app ]; then
    PORYMAP_TMP="$(mktemp -d)"
    gh release download --repo huderlem/porymap --pattern 'porymap-macos-latest.zip' --dir "$PORYMAP_TMP" --clobber
    unzip -q "$PORYMAP_TMP"/porymap-macos-latest.zip -d "$PORYMAP_TMP/extracted"
    MOUNT_DIR="$(mktemp -d)"
    hdiutil attach "$PORYMAP_TMP"/extracted/porymap-macos-latest/porymap.dmg -nobrowse -mountpoint "$MOUNT_DIR"
    cp -R "$MOUNT_DIR"/porymap.app /Applications/
    hdiutil detach "$MOUNT_DIR"
    xattr -cr /Applications/porymap.app
    rm -rf "$PORYMAP_TMP" "$MOUNT_DIR"
else
    echo "    porymap.app already installed, skipping."
fi

echo ""
echo "Done. Point Porymap at $REPO_DIR to edit maps."
echo "Run ./reload after editing to rebuild and relaunch mGBA."
