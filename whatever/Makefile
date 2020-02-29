justify: dist/obj/justify.o dist/obj/word.o dist/obj/line.o
	gcc -o dist/justify dist/obj/justify.o dist/obj/word.o dist/obj/line.o

dist/obj/justify.o: src/justify.c src/word.h src/line.h
	gcc -c src/justify.c -o dist/obj/justify.o

dist/obj/word.o: src/word.c src/word.h
	gcc -c src/word.c -o dist/obj/word.o

dist/obj/line.o: src/line.c src/line.h
	gcc -c src/line.c -o dist/obj/line.o
