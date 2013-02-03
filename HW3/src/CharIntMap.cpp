/*
 * CharIntMap.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: jay
 */

#include "CharIntMap.h"

CharIntMap::CharIntMap(char newChar) {
	c = newChar;
	count = 1;
}

CharIntMap::~CharIntMap() {}

// Increments count by i
void CharIntMap::increment(int i) {
	count += i;
}

char CharIntMap::getChar() {
	return c;
}

int CharIntMap::getCount() {
	return count;
}

bool CharIntMap::operator<(const CharIntMap & rhs) const {
	return c < rhs.c;
}
