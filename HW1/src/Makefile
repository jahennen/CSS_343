# Makefile for wordcount

# default target
words: allocator.o list.o wordcount.o
	g++ -Wall -g -o ./build/wordcount allocator.o list.o wordcount.o

# individual source files
allocator.o: allocator.cpp allocator.h
	g++ -Wall -g -c allocator.cpp

list.o: list.cpp list.h allocator.h
	g++ -Wall -g -c list.cpp

wordcount.o: wordcount.cpp
	g++ -Wall -g -c wordcount.cpp
