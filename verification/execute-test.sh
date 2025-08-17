#!/usr/bin/env bash

set +ex

export PATH="../bin/linux":${PATH}

full="${1#./}"

fname=$(basename $full)

expected=$(cat ./expected_results.json | jq -r ".\"${full}.c\".return_code")

trace=$(lcc ./${full}.c 2>&1)
q3asm -l -o $fname.qvm $fname.asm
../q3vm $fname.qvm
result=$(echo $?)

rm $fname.qvm $fname.asm


if [[ ${result} == ${expected} ]]; then
  printf "%-50s %-40s\n" ${full}..... "Passed"
else
  printf "%-50s %-40s\n" ${full}..... "Failed"
  echo "Expected ${expected} but got ${result}"
  echo "--------------"
  echo "${trace}"
fi

