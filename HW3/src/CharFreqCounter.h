/*
 * CharFreqCounter.h
 *
 *  Created on: Feb 2, 2013
 *      Author: jay
 */

#ifndef CHARFREQCOUNTER_H_
#define CHARFREQCOUNTER_H_

#include <vector>
#include "CharIntMap.h"
#include "BTree.h"

using namespace std;

class deleter{
public:
	void operator()(CharIntMap * k){
		delete k;
	}
};

class printer{
public:
	void operator()(CharIntMap * k){
		cout << k->getChar() << "  " << k->getCount() << endl;
	}
};

class CharFreqCounter {
public:
	CharFreqCounter();
	~CharFreqCounter();
	void addCount(char c);
	int lookup(char c);
	void increment(char c);
	void print();
	template <typename F>
	void walk(F f)  {
		counts.walk(f);
	}
private:
	BTree<CharIntMap> counts;
};
#endif /* CHARFREQCOUNTER_H_ */
