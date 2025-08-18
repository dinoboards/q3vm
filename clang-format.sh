#!/bin/bash

# Find all .c and .h files recursively
all_files=$(find . -type f \( -name "*.c" -o -name "*.h" \))

jobs=""

# Format the filtered files
for file in $all_files; do

    jobs+="echo \"formatting $file\"; clang-format-21 -i \"$file\""$'\n'
done

MAX_JOBS=16 # Set the maximum number of concurrent jobs

echo "$jobs" | xargs -P ${MAX_JOBS} -I{} bash -c '{}'
