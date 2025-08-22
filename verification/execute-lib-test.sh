#!/usr/bin/env bash

set +ex

FADE="\e[2m"
NORMAL="\e[0m"

export PATH="../bin/linux":${PATH}

full="${1#./}"
lib="${2#./}"

fname=$(basename $full)
libname=$(basename $lib)

function cleanup_function() {
  rm $fname.asm ${libname}.asm
  mv $fname.qvm $(dirname $full)/
}
trap cleanup_function EXIT


expected=$(cat ./expected_results.json | jq -r ".\"${lib}.c\".return_code")
expected_stdout=$(cat ./expected_results.json | jq -r ".\"${lib}.c\".stdout // empty")

trace=$(lcc ./${full}.c ${lib}.c 2>&1)
errored=$(echo $?)

if [[ ${errored} != "0" ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo -e ${FADE}
  echo "${trace}" | sed 's/^/  /'
  echo -e ${NORMAL}
  echo "  --------------"
  echo
  exit 1
fi

q3asm -l -o $fname.qvm $fname.asm ${libname}.asm g_syscalls.asm
actual_stdout=$(../q3vm $fname.qvm)
result=$(echo $?)

if [[ (${result} != ${expected}) || "$actual_stdout" != "${expected_stdout}" ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo "Expected ${expected} but got ${result} '${full}"
  echo "Expected stdout: ${expected_stdout} but got ${actual_stdout}"
  echo -e ${FADE}
  echo "${trace}" | sed 's/^/  /'
  echo -e ${NORMAL}
  echo "  --------------"
  echo
  exit 1
else
  if [[ ${trace} != "" ]]; then
    printf "%-80s .... %-40s\n" ${full}.c "Passed (with warnings)"
    # echo -e ${FADE}
    # echo "${trace}" | sed 's/^/  /'
    # echo -e ${NORMAL}
    # echo "  --------------"
    # echo
  fi

  # printf "%-80s .... %-40s\n" ${full}.c "Passed"
fi

