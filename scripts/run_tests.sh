#!/usr/bin/env bash

set -e

cd build
ctest -VV

apt-get install lcov
lcov -t "tests/tests_net" -o coverage.info -c -d net/
genhtml -o report coverage.info
