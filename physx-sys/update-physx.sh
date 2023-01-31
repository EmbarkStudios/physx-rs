#!/bin/bash
set -e

PHYSX_ROOT_DIR=$(realpath physx-sys/physx/physx)
git submodule update --init --remote

cd "$(dirname "$0")"

pushd pxbind

if ! [ -d build ]; then
    mkdir build
fi

pushd build
cmake -G "Unix Makefiles" ..
make -j32
popd

export PHYSX_ROOT_DIR

./run.sh "$1"
