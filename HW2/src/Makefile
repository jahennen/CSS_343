# Makefile for assignment 2
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -g -o

# targets
wordcount: wordcount.cpp Strmap.cpp ./counter/counter.cc BTree.h
	g++ $(CFLAGS) ./build/wordcount wordcount.cpp Strmap.cpp ./counter/counter.cc

dedup: dedup.cpp ./counter/counter.cc BTree.h
	g++ $(CFLAGS) ./build/dedup dedup.cpp ./counter/counter.cc

btreetest: btreetest.cpp ./counter/counter.cc BTree.h
	g++ $(CFLAGS) ./build/btreetest btreetest.cpp ./counter/counter.cc 
