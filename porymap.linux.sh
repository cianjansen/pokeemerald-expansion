#!/bin/bash
# Launch Porymap on this project (native Ubuntu desktop).
#
# MUST run through XWayland, not native Wayland. On this box (GNOME Wayland +
# NVIDIA proprietary driver) Porymap's Qt6 QGraphicsView map editor drops to
# ~1 fps whenever the mouse is over it as a native Wayland client, because
# every hover repaint becomes a full-surface copy through the NVIDIA
# EGL-Wayland path. Forcing the xcb (XWayland) platform plugin fixes it
# completely. See the "Native Linux (Ubuntu 26.04)" toolchain notes in spec.md.
set -e

cd "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

export QT_QPA_PLATFORM=xcb

exec porymap "$(pwd)" "$@"
