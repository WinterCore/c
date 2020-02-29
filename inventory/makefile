CC = gcc
OPTS = -Wall -g

main: main.o readline.o
	${CC} ${OPTS} -o main main.o readline.o

main.o: main.c readline.h
	${CC} ${OPTS} -c main.c

readline.o: readline.c readline.h
	${CC} ${OPTS} -c readline.c
