CC   = gcc
OPTS = -Wall -g


main: main.o randomized-queue.o
	${CC} ${OPTS} -o main main.o randomized-queue.o

main.o: main.c randomized-queue.h
	${CC} ${OPTS} -c main.c

randomized-queue.o: randomized-queue.h randomized-queue.c
	${CC} ${OPTS} -c randomized-queue.c
