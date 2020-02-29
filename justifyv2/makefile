CC   = gcc
OPTS = -Wall -g

justify: justify.o word.o line.o
	${CC} ${OPTS} -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	${CC} ${OPTS} -c justify.c

word.o: word.c word.h
	${CC} ${OPTS} -c word.c

line.o: line.c line.h
	${CC} ${OPTS} -c line.c
