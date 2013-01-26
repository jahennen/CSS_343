/*
 * Strmap.cpp
 *
 *  Created on: Jan 26, 2013
 *      Author: jay
 */

#include "Strmap.h"

Strmap::Strmap(const char* s) {
	word = new char[strlen(s)];
	strcpy(word, s);
	count = 1;
}

Strmap::~Strmap() {
	delete word;
}

int Strmap::get_count() {
	return count;
}

void Strmap::set_count(int n) {
	count = n;
}

const char* Strmap::get_word() {
	return word;
}

bool Strmap::operator<(const Strmap & rhs) const {
	if (strcmp(word, rhs.word) >= 0) {
		return false;
	} else {
		return true;
	}
}
