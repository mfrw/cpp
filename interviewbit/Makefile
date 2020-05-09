all=ib

OBJS=\
     array.o \
     ib.o

CXX=g++
CXXFLAGS= -g3 --std=gnu++2a
BIN=ib
BENCH=ibench

${BIN}: ${OBJS}
	${CXX} -g3 -o ${BIN} $^

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
