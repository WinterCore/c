CC = gcc
OPTS = -Wall -g

main: main.o union.o percolation.o
	${CC} ${OPTS} -lm -o main main.o union.o percolation.o

main.o: main.c
	${CC} ${OPTS} -c -o main.o main.c

union.o: union.h union.c
	${CC} ${OPTS} -c -o union.o union.c

percolation.o: percolation.h percolation.c union.h
	${CC} ${OPTS} -c -o percolation.o percolation.c
