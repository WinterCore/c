CC   = gcc
OPTS = -Wall -g


main: main.o deque.o
	${CC} ${OPTS} -o main main.o deque.o

main.o: main.c deque.h
	${CC} ${OPTS} -c main.c

deque.o: deque.h deque.c
	${CC} ${OPTS} -c deque.c
