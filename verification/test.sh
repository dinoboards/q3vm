#!/usr/bin/env bash

set -e

cd ..
# make clean
# make

cd verification


all_dirs=$(find -iname "chapter_*" | sort)

for dir in $all_dirs; do
  dir="${dir#./}"

  all_files=$(cd ${dir} && find . -type f \( -name "*.c" \))

  for file in $all_files; do
    file="${file%.*}"
    file="${file#./}"
    ./execute-test.sh ${dir}/$file
  done

done

