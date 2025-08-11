#!/bin/bash

# Find all .c and .h files recursively
all_files=$(find . -type f \( -name "*.c" -o -name "*.h" \))

# Format the filtered files
for file in $all_files; do
    echo "formatting $file"
    clang-format-21 -i "$file"
done
