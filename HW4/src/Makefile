# Makefile for assignment 3
# Author: Jay Hennen
# Not very useful except to elimiate typing

CFLAGS = -Wall -g -o

SUPPORT_FILES = Graph.cpp
SUPPORT_CPP = Graph.cpp

gtest: GraphTest.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) gtest GraphTest.cpp $(SUPPORT_CPP)
	
network_cost: NetworkCost.cpp $(SUPPORT_FILES)
	g++ $(CFLAGS) network_cost NetworkCost.cpp $(SUPPORT_CPP)
