CC   = gcc
OPTS = -Wall -g


main: main.o stack.o queue.o
	${CC} ${OPTS} -o main main.o stack.o queue.o

main.o: main.c queue.h
	${CC} ${OPTS} -c main.c

stack.o: stack.c stack.h
	${CC} ${OPTS} -c stack.c

queue.o: queue.c queue.h stack.h
	${CC} ${OPTS} -c queue.c
