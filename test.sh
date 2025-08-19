#!/usr/bin/env bash

set +e

./clang-format.sh

# make clean && make test
make clean && make test && (cd ./verification && ./test.sh) && (cd ./example && ../q3vm bytecode.qvm)
# make clean && make && (cd ./example && make && ../q3vm bytecode.qvm; echo $?)
#
