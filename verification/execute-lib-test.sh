#!/usr/bin/env bash

set +ex

export PATH="../bin/linux":${PATH}

full="${1#./}"
lib="${2#./}"

fname=$(basename $full)
libname=$(basename $lib)

expected=$(cat ./expected_results.json | jq -r ".\"${lib}.c\".return_code")

trace=$(lcc ./${full}.c ${lib}.c 2>&1)
q3asm -l -o $fname.qvm $fname.asm ${libname}.asm
../q3vm $fname.qvm
result=$(echo $?)

rm $fname.qvm $fname.asm ${libname}.asm


if [[ ${result} != ${expected} ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo "Expected ${expected} but got ${result} '${full}"
  echo "--------------"
  echo "${trace}"
# else
#   printf "%-80s .... %-40s\n" ${full}.c "Passed"
fi

