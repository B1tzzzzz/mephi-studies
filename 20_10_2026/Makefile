array: main.o work.o
	gcc main.o work.o -o array

main.o: main.c array.h
	gcc main.c -c

work.o: work.c
	gcc work.c -c

run: array
	./array

