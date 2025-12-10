#!/bin/bash
# Create symlinks to folly .pxd files for Cython compilation
# This script is called by CMake at build time

FOLLY_INCLUDE_DIR="$1"
DEST_DIR="$2"

echo "Creating folly .pxd symlinks from ${FOLLY_INCLUDE_DIR}/folly/"
mkdir -p "${DEST_DIR}/folly"

for pxd in "${FOLLY_INCLUDE_DIR}/folly/"*.pxd; do
    if [ -f "$pxd" ]; then
        ln -sf "$pxd" "${DEST_DIR}/folly/$(basename "$pxd")"
    fi
done
