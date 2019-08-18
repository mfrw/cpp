all: bench

bench: src/bench.cpp
	c++ --std=c++17 -L lib/ -I inc/ -pthread -lbenchmark src/bench.cpp -o bin/bench
.PHONY: clean
clean:
	rm -rf bin/bench
