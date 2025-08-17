#!/usr/bin/env bash

set -e

cd ..
# make clean
# make

cd verification

IGNORESET=(
  parameter_shadows_function
  test_for_memory_leaks
  convert_function_arguments
  comparisons
  rewrite_large_multiply_regression
  logical
  large_constants
  truncate
  compound_bitshift
  compound_assign_to_long
  compound_assign_to_int
  bitwise_long_op
  bitshift
  switch_int
)

function skipped_function() {
  local needle="$1"
  shift
  for item in "${IGNORESET[@]}"; do
    if [[ "$item" == "$needle" ]]; then
      return 0 # Found
    fi
  done
  return 1 # Not found
}

jobs=""
all_dirs=$(find -iname "chapter_*" | sort -V)

for dir in $all_dirs; do
  dir="${dir#./}"

  all_files=$(cd ${dir} && find . -type f \( -name "*.c" \))

  for file in $all_files; do
    file="${file%.*}"
    file="${file#./}"

    name=$(basename $file)
    if  skipped_function $(basename $file); then
      printf "%-80s .... %-40s\n" ${dir}/${file}.c "Skipped"
    else
      jobs+="\"./execute-test.sh ${dir}/$file\" "$'\n'
    fi
  done

done

MAX_JOBS=16 # Set the maximum number of concurrent jobs


# # Execute commands from the file in parallel, with a limit
echo "$jobs" | xargs -P ${MAX_JOBS} -I{} bash -c '{}'

echo "Verification Run Completed."

