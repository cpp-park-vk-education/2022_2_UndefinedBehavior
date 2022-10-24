TARGET = ./build/YourCollection

.PHONY: all build rebuild run clean

all: build

clean:
	rm -rf build

build:
	./scripts/build.sh -DBUILD_FOR_TEST=OFF

rebuild: clean build

run: ${TARGET}
	${TARGET}

test:
	./scripts/build.sh -DBUILD_FOR_TEST=ON -DWITH_MEMCHECK=OFF
	./scripts/run_tests.sh

memtest:
	./scripts/build.sh -DBUILD_FOR_TEST=ON -DWITH_MEMCHECK=ON
	./scripts/run_tests.sh

check: 
	./scripts/run_linters.sh

refactor:
	clang-format -i net/server/* net/client/* tests/*.cpp