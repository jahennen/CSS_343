# Makefile for assignment 2
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -g -o

SUPPORT_FILES = HuffNode.cpp HuffTree.cpp PQueue.h PQueue_impl.h BTree.h BTreeMap.h
SUPPORT_CPP = HuffNode.cpp HuffTree.cpp

# targets
pqtest: PQTest.cpp PQueue_impl.h PQueue.h
	g++ $(CFLAGS) ./build/pqtest PQTest.cpp

huffcodec: HuffCodec.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) ./build/huffcodec HuffCodec.cpp $(SUPPORT_CPP)
	
btreetest: BTreeTest.cpp BTree.h
	g++ $(CFLAGS) ./build/btreetest BTreeTest.cpp
	
btmaptest: BTreeMapTest.cpp BTree.h BTreeMap.h
	g++ $(CFLAGS) ./build/btmaptest BTreeMapTest.cpp
