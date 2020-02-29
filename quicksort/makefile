CC   = gcc
OPTS = -Wall -g

quicksort: main.o quicksort.o
	${CC} ${OPTS} -o quicksort main.c quicksort.c

main.o: quicksort.h main.c
	${CC} ${OPTS} -c main.c

quicksort.o: quicksort.h quicksort.c
	${CC} ${OPTS} -c quicksort.c
