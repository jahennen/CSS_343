# Makefile for assignment 3
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -g -o

SUPPORT_FILES = HuffTree.cpp PQueue.h PQueue_impl.h BitStream.cpp
SUPPORT_CPP = HuffTree.cpp BitStream.cpp

huffcodec: HuffCodec.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) ./build/huffcodec HuffCodec.cpp $(SUPPORT_CPP)
