CC   = gcc
OPTS = -Wall -g


main: main.o stack.o
	${CC} ${OPTS} -o main main.o stack.o

main.o: main.c stack.h
	${CC} ${OPTS} -c main.c

stack.o: stack.c stack.h
	${CC} ${OPTS} -c stack.c
