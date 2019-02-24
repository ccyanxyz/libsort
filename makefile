dynamic: ./src/sort.cc ./src/sort.h
	c++ -fPIC -shared -o ./lib/libsort.so ./src/sort.cc -std=c++11

static: ./src/sort.cc ./src/sort.h
	c++ -c -o sort.o ./src/sort.cc -std=c++11
	ar -crv ./lib/libsort.a sort.o
	rm sort.o

test_static: ./test.cc
	rm ./lib/libsort.so &
	c++ -c -o sort.o ./src/sort.cc -std=c++11
	ar -crv ./lib/libsort.a sort.o
	rm sort.o
	c++ -o test_static test.cc -I./src -L./lib -lsort

test_dynamic: ./test.cc
	export LD_LIBRARY_PATH=./lib
	c++ -fPIC -shared -o ./lib/libsort.so ./src/sort.cc -std=c++11
	c++ -o test_dynamic test.cc -I./src -L./lib -lsort

clean:
	rm -rf ./lib/libsort* ./test_static ./test_dynamic
