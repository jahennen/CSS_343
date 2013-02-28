# Makefile for assignment 3
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -std=c++0x -g -o

SUPPORT_FILES = src/Graph.cpp
SUPPORT_CPP = src/Graph.cpp

gtest: src/GraphTest.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) gtest src/GraphTest.cpp $(SUPPORT_CPP)
