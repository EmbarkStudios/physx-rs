#!/bin/bash
set -e

# Regenerates the physx_generated.hpp and physx_generated.rs files, as well
# as compiling and running structgen to regenerate the POD layouts. This script
# is only intended to work on Linux

if [[ -n "$1" && -f ast-dump.json ]]; then
    rm ast-dump.json
fi

# note we use nightly as obtaining command output on linux is horrendously slow
# in stable, which is a problem given the size of the JSON AST output
RUST_LOG=debug cargo +nightly run --release -p pxbind

out=$(mktemp -d)

# Compile and run structgen for linux
clang++ -std=c++14 -fuse-ld=lld -w -o "$out/structgen" \
    -DPX_PHYSX_STATIC_LIB -DNDEBUG \
    -I physx-sys/physx/physx/include \
    physx-sys/src/structgen/structgen.cpp

(cd $out && ./structgen)

generated=physx-sys/src/generated

mv $out/structgen_out.hpp $generated/unix
mv $out/structgen_out.rs $generated/unix/structgen.rs

# Compile and run structgen for windows
# clang-cl -fuse-ld=lld-link --target=x86_64-pc-windows-msvc '/std:c++14' '/w' -o "$out/structgen.exe" \
#     -DPX_PHYSX_STATIC_LIB -DNDEBUG \
#     -I physx-sys/physx/physx/include \
#     physx-sys/src/structgen/structgen.cpp

# (cd $out && wine structgen.exe)

# generated=$generated/x86_64-pc-windows-msvc

# mv $out/structgen_out.hpp $generated
# mv $out/structgen_out.rs $generated/structgen.rs
