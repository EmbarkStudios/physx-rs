#!/bin/bash
set -eux

export CFLAGS="-Wno-error=unused-command-line-argument -fuse-ld=lld-link /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/ucrt /imsvc/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/include /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/um /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/shared /link-L/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/lib/x64"
export TARGET_CXXFLAGS="-Wno-error=unused-command-line-argument -fms-compatibility -fms-compatibility-version=19 -fuse-ld=lld-link /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/ucrt /imsvc/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/include /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/um /imsvc/home/jake/xwin/winsdk/Include/10.0.17763.0/shared /imsvc/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/include"
export CC="clang-cl"
export CXX="clang-cl"
export TARGET="x86_64-pc-windows-msvc"
export TARGET_AR="llvm-lib"
export RUSTFLAGS="-L native=/home/jake/xwin/winsdk/Lib/10.0.17763.0/um/x64 -L native=/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/lib/x64"
export RUST_BACKTRACE=1
#export LIBRARY_PATH="/home/jake/xwin/vc/VC/Tools/MSVC/14.16.27023/lib/x64"

cargo build --target x86_64-pc-windows-msvc
