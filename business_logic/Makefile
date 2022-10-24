TARGET = ./build/YourCollection

.PHONY: all build rebuild run clean

all: build

clean:
	rm -rf build

build:
	set -e
	
	cd business_logic
	mkdir -p build
	cd build
	cmake "$@" ..
	cmake --build .

rebuild: clean build

run: ${TARGET}
	${TARGET}


