/*
 * CharIntMap.h
 *
 *  Created on: Feb 2, 2013
 *      Author: jay
 */

#ifndef CHARINTMAP_H_
#define CHARINTMAP_H_

class CharIntMap {
public:
	CharIntMap(char newChar);
	~CharIntMap();
	void increment(int i);
	char getChar();
	int getCount();
	void print();
	bool operator<(const CharIntMap & rhs) const;
private:
	char c;
	int count;
};

#endif

