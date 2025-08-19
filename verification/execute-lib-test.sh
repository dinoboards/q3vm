#!/usr/bin/env bash

set +ex

export PATH="../bin/linux":${PATH}

full="${1#./}"
lib="${2#./}"

fname=$(basename $full)
libname=$(basename $lib)

expected=$(cat ./expected_results.json | jq -r ".\"${lib}.c\".return_code")
expected_stdout=$(cat ./expected_results.json | jq -r ".\"${lib}.c\".stdout // empty")

trace=$(lcc ./${full}.c ${lib}.c 2>&1)
q3asm -l -o $fname.qvm $fname.asm ${libname}.asm g_syscalls.asm
actual_stdout=$(../q3vm $fname.qvm)
result=$(echo $?)

rm $fname.qvm $fname.asm ${libname}.asm

if [[ (${result} != ${expected}) || "$actual_stdout" != "${expected_stdout}" ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo "Expected ${expected} but got ${result} '${full}"
  echo "Expected stdout: ${expected_stdout} but got ${actual_stdout}"
  echo "--------------"
  echo "${trace}"
else
  printf "%-80s .... %-40s\n" ${full}.c "Passed"
fi

