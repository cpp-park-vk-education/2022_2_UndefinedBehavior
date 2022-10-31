#!/usr/bin/env bash

set -e

cd build
ctest -VV

apt-get --force-yes -y install lcov

lcov -t "tests/test" -o coverage.info -c -d net/
genhtml -o report coverage.info