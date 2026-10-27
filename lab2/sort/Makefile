merge_sort_iterative: main.o work.o
	gcc main.o work.o -o merge_sort_iterative

main.o: main.c array.h utils.h cmath.h
	gcc main.c -c

work.o: work.c
	gcc work.c -c

run: merge_sort_iterative
	./merge_sort_iterative