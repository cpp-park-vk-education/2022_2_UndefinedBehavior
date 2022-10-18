#!/usr/bin/env bash

set -e

cd build
ctest -VV

#lcov -t "tests/tests_fib" -o coverage.info -c -d fib_lib/
#lcov -t "tests/tests_net" -o coverage.info -c -d net/
#genhtml -o report coverage.info