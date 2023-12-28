#!/bin/bash

set -e

compiler=gcc

# Get all C files
# ----------------------------
c_files=""

for file in ./src/*.c
do
    c_files+="$file "
done

for file in ./src/utils/*.c
do
    c_files+="$file "
done
# ----------------------------

output="-o gaybe.exe"

compile_command="$compiler $c_files $output"

echo "Building gaybe.exe..."
$compile_command