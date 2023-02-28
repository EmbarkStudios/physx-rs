#!/bin/bash
set -e

dir=$1
file="$(dirname "$0")/sources/$2"

printf "[\n" > "$file"

for entry in "$dir"/*.cpp
do
  printf "    \"%s\",\n" "$(echo "$entry" | sed -r "s/.+\/(.+)\..+/\1/")" >> "$file"
done

printf "]\n" >> "$file"
