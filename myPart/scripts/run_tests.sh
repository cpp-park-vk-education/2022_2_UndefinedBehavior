#!/usr/bin/env bash

set -e
set -o pipefail

cd build
ctest -VV
lcov -t "tests/tests_net" -o coverage.info -c -d net/
genhtml -o report coverage.info
