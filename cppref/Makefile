all=stl

OBJS=\
     array.o \
     vector.o \
     deque.o \
     fwd_list.o \
     list.o \
     set.o \
     map.o \
     stack.o \
     sharedptr.o \
     multiset.o \
     iterators.o \
     async.o \
     mutex.o \
     allocator.o \
     fibo.o \
     thread.o \
     stl.o

CXX=g++
CXXFLAGS = --std=gnu++2a -flto=thin
BIN=stl
BENCH=stlbench
LDFLAGS=-flto=thin

${BIN}: ${OBJS}
	${CXX} -flto=thin -o ${BIN} $^

${BENCH}: stlbench.cpp stlbench.h
	${CXX} ${CXXFLAGS} -L benchmark/ -I benchmark/ -pthread -lbenchmark -o $@ $<

# Clean & Run
.PHONY: cr
cr: clean run

.PHONY: bench
bench: ${BENCH}
	./${BENCH}

.PHONY: clean
clean:
	rm -rf ${OBJS} ${BIN} ${BENCH}

.PHONY: run
run: ${BIN}
	./${BIN}
