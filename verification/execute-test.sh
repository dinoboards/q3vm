#!/usr/bin/env bash

set +ex

FADE="\e[2m"
NORMAL="\e[0m"

export PATH="../bin/linux":${PATH}

full="${1#./}"

fname=$(basename $full)

function cleanup_function() {
  rm $fname.asm
  mv $fname.qvm $(dirname $full)/
  mv $fname.lst $(dirname $full)/
}

trap cleanup_function EXIT

expected=$(cat ./expected_results.json | jq -r ".\"${full}.c\".return_code")

trace=$(lcc ./${full}.c  2>&1)
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


q3asm -l -o $fname.qvm $fname.asm g_syscalls.asm
output=$(../q3vm $fname.qvm)
result=$(echo $?)


if [[ ${result} != ${expected} ]]; then
  printf "%-80s .... %-40s\n" ${full}.c "Failed"
  echo "Expected ${expected} but got ${result} '${full}"
  echo -e ${FADE}
  echo "${trace}" | sed 's/^/  /'
  echo "  --------------"
  echo "${output}"
  echo "  --------------"
  echo -e ${NORMAL}
  echo
else

  if [[ ${trace} != "" ]]; then
    printf "%-80s .... %-40s\n" ${full}.c "Passed (with warnings)"
    # echo -e ${FADE}
    # echo "${trace}" | sed 's/^/  /'
    # echo -e ${NORMAL}
    # echo "  --------------"
    # echo
  fi

#   printf "%-80s .... %-40s\n" ${full}.c "Passed"
fi

