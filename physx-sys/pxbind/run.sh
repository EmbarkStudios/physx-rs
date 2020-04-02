cd ../src
export PHYSX_ROOT_DIR=../PhysX/physx
../pxbind/build/pxbind $PHYSX_ROOT_DIR/include/PxPhysicsAPI.h -- \
    -v \
    -I/home/jasper/ndk/arm64/sysroot/usr/include/c++/v1 \
    --target=aarch64-linux-android \
    -DNDEBUG=1 -x c++ \
    -DDISABLE_CUDA_PHYSX \
    -I../pxbind \
    -I$PHYSX_ROOT_DIR/include \
    -I$PHYSX_ROOT_DIR/../pxshared/include/