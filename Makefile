TARGET = ./build/YourCollection

.PHONY: all build rebuild run clean

all: build

clean:
	rm -rf build

build:
	./build.sh

rebuild: clean build

run: ${TARGET}
	${TARGET}

test:
	./build.sh -DWITH_MEMCHECK=OFF
	./run_tests.sh

memtest:
	./build.sh -DWITH_MEMCHECK=ON
	./run_tests.sh

check: 
	./run_linters.sh
