# Makefile for assignment 2
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -g -o

SUPPORT_FILES = HuffTree.cpp PQueue.h PQueue_impl.h BitStream.cpp
SUPPORT_CPP = HuffTree.cpp BitStream.cpp

# targets
pqtest: PQTest.cpp PQueue_impl.h PQueue.h
	g++ $(CFLAGS) ./build/pqtest PQTest.cpp

huffcodec: HuffCodec.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) ./build/huffcodec HuffCodec.cpp $(SUPPORT_CPP)
	
btreetest: BTreeTest.cpp BTree.h
	g++ $(CFLAGS) ./build/btreetest BTreeTest.cpp
	
btmaptest: BTreeMapTest.cpp BTree.h BTreeMap.h
	g++ $(CFLAGS) ./build/btmaptest BTreeMapTest.cpp
