#!/bin/bash
set -e

# This script finds all of the cpp files in a <directory> and generates a rust
# array of strings into physx-sys/sources/<name> that is used by the build script
# to compile all of the source files when compiling physx-sys
#
# usage: make-sources.sh <physx c++ source directory path> <name>
dir=$1
file="$(dirname "$0")/sources/$2"

printf "[\n" > "$file"

for entry in "$dir"/*.cpp
do
  printf "    \"%s\",\n" "$(echo "$entry" | sed -r "s/.+\/(.+)\..+/\1/")" >> "$file"
done

printf "]\n" >> "$file"
