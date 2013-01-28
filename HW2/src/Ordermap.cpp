/*
 * Ordermap.cpp
 *
 *  Created on: Jan 28, 2013
 *      Author: jay
 */

#include "Ordermap.h"

Ordermap::Ordermap(int pos, const char * s) {
	word = new char[strlen(s)];
	strcpy(word, s);
	position = pos;
}

Ordermap::~Ordermap() {
	delete word;
}

const char* Ordermap::get_word() {
	return word;
}

int Ordermap::get_pos() {
	return position;
}

bool Ordermap::operator<(const Ordermap & rhs) const {
	return position < rhs.position;
}


