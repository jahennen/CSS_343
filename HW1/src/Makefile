# Makefile for wordcount

# default target
words: allocator.o list.o wordcount.o
	gcc -Wall -g -o words allocator.o list.o wordcount.o

# individual source files
allocator.o: allocator.c allocator.h
	gcc -Wall -g -c allocator.c

list.o: list.c list.h allocator.h
	gcc -Wall -g -c list.c

wordcount.o: wordcount.c 
	gcc -Wall -g -c wordcount.c