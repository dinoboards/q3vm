#!/usr/bin/env bash

set -e

if [[ "$1" == "ez80" ]]; then
  UPDATE_EZ80_IMAGES=1
else
  UPDATE_EZ80_IMAGES=0
fi


IGNORESET=(
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

    if skipped_function $(basename $file); then
      printf "%-80s .... %-40s\n" ${dir}/${file}.c "Skipped"
    else
      if [[ "$file" =~ "/libraries/" ]]; then
        if [[ "$file" =~ _client$ ]]; then
          libFile=${file::-7}

          jobs+="\"./execute-lib-test.sh ${dir}/$file ${dir}/$libFile\" "$'\n'
        fi
      else
          jobs+="\"./execute-test.sh ${dir}/$file\" "$'\n'
      fi
    fi
  done

done

MAX_JOBS=16 # Set the maximum number of concurrent jobs

# # Execute commands from the file in parallel, with a limit
echo "$jobs" | xargs -P ${MAX_JOBS} -I{} bash -c '{}'

echo "Verification Run Completed."

if [[ $UPDATE_EZ80_IMAGES == 1 ]]; then

echo "Generating test images for eZ80 ..."

OUTPUT_FILE="./tests-byte-code"

cat <<EOT > "${OUTPUT_FILE}.h"
#ifndef __TESTS_BYTE_CODE
#define __TESTS_BYTE_CODE

#include <stdint.h>

typedef struct test_run_s {
  const char* const name;
  const uint8_t* const image;
  const uint24_t size;
  const uint8_t expected;
} test_run_t;

EOT

cat <<EOT > "${OUTPUT_FILE}.c"
#include <stdint.h>
#include "${OUTPUT_FILE}.h"

EOT

declare -a tests
Q3VM_VERIFICATION_SIZE=0

for dir in $all_dirs; do
  dir="${dir#./}"

  all_files=$(cd ${dir} && find . -type f \( -name "*.c" \))

  for file in $all_files; do
    printf "."
    file="${file%.*}"
    file="${file#./}"
    name=$(basename $file)

    if ! skipped_function $(basename $file); then
      if [[ "$file" =~ "/libraries/" ]]; then
        if [[ "$file" =~ _client$ ]]; then
          libFile=${file::-7}

          echo $'\n'"TODO :\"./execute-lib-test.sh ${dir}/$file ${dir}/$libFile\" "$'\n'
        fi
      else
        testname=$(./export-for-ez80-tests.sh ${dir}/${file}.qvm)
        # tests+=("${testname}")

        expected=$(cat ./expected_results.json | jq -r ".\"${dir}/$file.c\".return_code")

        test_line="{ \"${testname}\", ${testname}, ${testname^^}_SIZE, $expected },"
        tests+=("${test_line}")

        Q3VM_VERIFICATION_SIZE=$((Q3VM_VERIFICATION_SIZE+1))
      fi
    fi
  done

done

echo

cat <<EOT >> "${OUTPUT_FILE}.h"

#define Q3VM_VERIFICATION_SIZE ${Q3VM_VERIFICATION_SIZE}

extern test_run_t q3vm_verification[Q3VM_VERIFICATION_SIZE];

#endif
EOT

echo "test_run_t q3vm_verification[Q3VM_VERIFICATION_SIZE] = {" >> "${OUTPUT_FILE}.c"
echo ${tests[@]} >> "${OUTPUT_FILE}.c"


echo "};" >> "${OUTPUT_FILE}.c"

clang-format -i "${OUTPUT_FILE}.c" "${OUTPUT_FILE}.h"

fi;
