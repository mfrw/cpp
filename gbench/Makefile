all: bench

bench: src/bench.cpp
	c++ --std=c++2a -L lib/ -I inc/ -pthread -lbenchmark src/bench.cpp -o bin/bench
.PHONY: clean
clean:
	rm -rf bin/bench

.PHONY: run
run:
	bin/bench
