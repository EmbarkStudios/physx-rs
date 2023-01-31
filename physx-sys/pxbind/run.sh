#!/bin/bash
set -eu

cd ../src || exit 1

target=$1

additional=()

function add_default {
    declare -n arr=$1

    includes=$(c++ -xc++ /dev/null -E -Wp,-v 2>&1 | sed -n 's,^ ,,p')
    for inc in $includes; do arr+=(-isystem "$inc"); done

    includes=$(cc -xc /dev/null -E -Wp,-v 2>&1 | sed -n 's,^ ,,p')
    for inc in $includes; do arr+=(-isystem "$inc"); done
}

case $target in
    x86_64-unknown-linux-gnu)
        #add_default additional
        additional+=(-isystem "/usr/lib64/clang/15.0.7/include")
        ;;
    aarch64-unknown-linux-gnu)
        additional+=("-fsigned-char")
        add_default additional
        ;;
    aarch64-linux-android)
        additional=("-fsigned-char" --sysroot="$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot")
        ;;
    *)
        ;;
esac

../pxbind/build/pxbind "$PHYSX_ROOT_DIR/include/PxPhysicsAPI.h" -- \
    --target="$target" \
    -DNDEBUG=1 -xc++ \
    -DDISABLE_CUDA_PHYSX \
    -I../pxbind \
    -I"$PHYSX_ROOT_DIR/include" \
    -I"$PHYSX_ROOT_DIR/../pxshared/include/" \
    "${additional[@]}"
