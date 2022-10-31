#!/usr/bin/env bash

set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

function check_log() {
    LOG=${1}
    echo "$LOG"
    if echo "$LOG" | grep -q -E "${2}"
    then
        exit 1
    fi
}
    if [ $STATUS -ne 0 ]
    then
        exit $STATUS
    fi


print_header "RUN cppcheck"
check_log "cppcheck src --enable=all --inconclusive --error-exitcode=1 -Isrc --suppress=missingIncludeSystem" "\(information\)"

print_header "RUN clang-tidy"
check_log "clang-tidy src/* src/* -warnings-as-errors=* -extra-arg=-std=c++11 -- -Isrc" "Error (?:reading|while processing)"

print_header "RUN cpplint"
check_log "cpplint --extensions=cpp src/* src/*" "Can't open for reading"

print_header "SUCCESS"