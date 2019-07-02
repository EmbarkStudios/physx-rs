#!/bin/bash

rm -rf PhysX
mkdir PhysX

function fetch {
    svn export https://github.com/NVIDIAGameWorks/PhysX/trunk/$1 PhysX/$1
}

fetch README.md
fetch physx/include
fetch physx/source
fetch physx/compiler
fetch pxshared
fetch externals/cmakemodules

cd pxbind
./build.sh && ./run.sh
