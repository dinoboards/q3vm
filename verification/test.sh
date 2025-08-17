#!/usr/bin/env bash

set -e

cd ..
# make clean
# make

cd verification


all_files=$(cd chapter_1 && find . -type f \( -name "*.c" \))

for file in $all_files; do
  file="${file%.*}"
  file="${file#./}"
  ./execute-test.sh ./chapter_1/$file
done


all_files=$(cd chapter_2 && find . -type f \( -name "*.c" \))

for file in $all_files; do
  file="${file%.*}"
  file="${file#./}"
  ./execute-test.sh ./chapter_2/$file
done


