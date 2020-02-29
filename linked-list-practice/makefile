CC = gcc
OPTS = -Wall -g

main: main.o linked-list.o
	${CC} ${OPTS} -o main main.o linked-list.o

main.o: main.c
	${CC} ${OPTS} -c main.c

linked-list.o: linked-list.h linked-list.c
	${CC} ${OPTS} -c linked-list.c
