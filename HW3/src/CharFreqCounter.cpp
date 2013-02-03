/*
 * CharFreqCounter.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: jay
 */

#include "CharFreqCounter.h"


CharFreqCounter::CharFreqCounter() {}

CharFreqCounter::~CharFreqCounter() {
	deleter d;
	counts.walk(d);
}

void CharFreqCounter::addCount(char c) {
	CharIntMap * entry = new CharIntMap(c);
	if (!counts.lookup(entry)) { // if not present in counts set, add
		counts.insert(entry);
		return;
	}
	delete entry;
}

int CharFreqCounter::lookup(char c) {
	CharIntMap entry(c);
	CharIntMap * result = counts.lookup(&entry);
	if (result) {
		return result->getCount();
	} else {
		return 0;
	}
}

void CharFreqCounter::increment(char c) {
	CharIntMap entry(c);
	CharIntMap * result = counts.lookup(&entry);
	if (result) {
		result->increment(1);
	}
}

void CharFreqCounter::print() {
	printer p;
	walk(p);
}
