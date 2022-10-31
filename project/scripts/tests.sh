#!/usr/bin/env bash

set -e

cd build
ctest

lcov -t "tests/test" -o coverage.info -c -d src/
genhtml -o report coverage.info