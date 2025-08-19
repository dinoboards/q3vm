#!/usr/bin/env bash

set +ex

export PATH="../bin/linux":${PATH}

full="${1#./}"

fname=$(basename $full)

expected=$(cat ./expected_results.json | jq -r ".\"${full}.c\".return_code")

trace=$(lcc ./${full}.c 2>&1)
q3asm -l -o $fname.qvm $fname.asm g_syscalls.asm
output=$(../q3vm $fname.qvm)
result=$(echo $?)

rm $fname.qvm $fname.asm

if [[ ${result} != ${expected} ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo "Expected ${expected} but got ${result} '${full}"
  echo "--------------"
  echo "${trace}"
else
  printf "%-80s .... %-40s\n" ${full}.c "Passed"
fi

