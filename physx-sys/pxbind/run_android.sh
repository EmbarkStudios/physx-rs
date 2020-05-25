cd ../src
export PHYSX_ROOT_DIR=../PhysX/physx
../pxbind/build/pxbind ../PhysX/physx/include/PxPhysicsAPI.h -- \
    -v \
    --target=aarch64-linux-android \
    -DNDEBUG=1 -x c++ \
    -DDISABLE_CUDA_PHYSX \
    -I../pxbind \
    -I../PhysX/physx/include \
    -I../PhysX/physx/../pxshared/include/ \
    -I/home/viktor/android-ndk-r21b/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/c++/v1 \
    --sysroot=/home/viktor/android-ndk-r21b/toolchains/llvm/prebuilt/linux-x86_64/sysroot \
    -fsigned-char