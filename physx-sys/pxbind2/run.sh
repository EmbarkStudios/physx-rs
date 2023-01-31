#!/bin/bash
set -e

autocxx-gen \
    --outdir pxbind-out \
    --gen-cpp \
    --gen-rs-include \
    -I physx-sys/physx/physx/include \
    -I physx-sys/pyhysx/physx/include/foundation \
    physx-sys/pxbind2/src/lib.rs \
    -- --target=x86_64-unknown-linux-gnu -DNDEBUG=1 -xc++ -DDISABLE_CUDA_PHYSX
