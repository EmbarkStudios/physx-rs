#!/bin/bash

set -e

if [[ -n "$1" && -f ast-dump.json ]]; then
    rm ast-dump.json
fi

RUST_LOG=debug cargo run --release -p pxbind
cargo build -p physx-sys --features structgen
