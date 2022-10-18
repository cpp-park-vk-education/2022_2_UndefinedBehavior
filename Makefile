TARGET = ./build/YourCollection

.PHONY: all build rebuild run clean

all: build

clean:
	rm -rf build

build:
	./build.sh -DBUILD_FOR_TEST=OFF

rebuild: clean build

run: ${TARGET}
	${TARGET}

test:
	./build.sh -DBUILD_FOR_TEST=ON -DWITH_MEMCHECK=OFF
	./run_tests.sh

memtest:
	./build.sh -DBUILD_FOR_TEST=ON -DWITH_MEMCHECK=ON
	./run_tests.sh

check: 
	./run_linters.sh
