#!/usr/bin/env bash

set +e


make clean && make test ; (cd ./example && make && ../q3vm bytecode.qvm)
# make clean && make && (cd ./example && make && ../q3vm bytecode.qvm; echo $?)
