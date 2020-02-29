CC = gcc
OPTS = -Wall -g

main: main.o stack.o
	${CC} ${OPTS} -o main main.o stack.o

main.o: main.c
	${CC} ${OPTS} -c main.c

linked-list.o: linked-list.h linked-list.c
	${CC} ${OPTS} -c linked-list.c

stack.o: stack.h stack.c linked-list.o
	${CC} ${OPTS} -c stack.c
