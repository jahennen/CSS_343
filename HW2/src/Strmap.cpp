/*
 * Strmap.cpp
 *
 *  Created on: Jan 26, 2013
 *      Author: jay
 */

#include "Strmap.h"

Strmap::Strmap(string s) {
	word = s;
	count = 1;
}

Strmap::~Strmap() {}

int Strmap::get_count() {
	return count;
}

void Strmap::set_count(int n) {
	count = n;
}

string Strmap::get_word() {
	return word;
}

bool Strmap::operator<(const Strmap & rhs) const {
	return word < rhs.word;
}
