#!/bin/bash
set -eu

separator="----8<----8<----8<----8<----"

function make_chunk {
    cd "$1"
    if ! git diff --exit-code  --ignore-submodules --quiet; then
        echo "${PWD#$root}/"
        git --no-pager diff --no-color --ignore-submodules
        echo "$separator"
    fi
}

case "$1" in
    "make" )
        root=$PWD
        make_chunk "$PWD"
        for module in $(git submodule  foreach --recursive 'echo $toplevel/$path' | grep -v Entering); do
            make_chunk "$module"
        done
    ;;
    "apply")
        root=$PWD
        while read -r pwd; do
            patch=""
            while read -r line; do
                if [ "$line" = "$separator" ]; then
                    break
                fi
                patch="$patch"$'\n'"$line"
            done
            echo Patching "$root$pwd"
            cd "$root$pwd"
            echo "$patch" | patch -p1 --forward --force || true
        done
    ;;
    *)
        echo "Unknown command"
        exit 1
        ;;
esac