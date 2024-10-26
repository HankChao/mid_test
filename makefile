all:
	gcc mid01.c -o mid01
	gcc mid02.c -o mid02
	gcc -c parallelogram.c -o parallelogram.o
	gcc mid03.c parallelogram.o -o mid03 -lm
