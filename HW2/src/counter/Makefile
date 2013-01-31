# Makefile
#
# Copyright 2013 Systems Deployment, LLC
# Author: Morris Bernstein

ALL = \
	README \
	Makefile \
	Run \
	counter.h \
	counter.cc \
	counter_test.cc \
	counter_test.baseline

OBJ = counter_test.o counter.o

all: $(OBJ)

test: counter_test

counter_test: $(OBJ)
	g++ -o $@ $(OBJ)

tar : $(ALL)
	mkdir -p counter
	cp -f $(ALL) counter/
	tar cfvz counter.tgz counter

clean:
	rm -f counter_test
	rm -f *.tgz
	rm -f *.out
	rm -f *.o
	rm -Rf counter/
