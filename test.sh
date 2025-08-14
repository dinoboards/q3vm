#!/usr/bin/env bash

set -e


make clean && make test && (cd ./example && make && ../q3vm bytecode.qvm)
