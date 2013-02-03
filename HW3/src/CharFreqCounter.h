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

using namespace std;

class CharFreqCounter {
public:
	CharFreqCounter();
	virtual ~CharFreqCounter();
	void add(char c);
	void increment(char c);
private:
	vector<CharIntMap> data;
	BTree<CharIntMap> counts;
};
#endif /* CHARFREQCOUNTER_H_ */
