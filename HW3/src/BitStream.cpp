/*
 * BitStream.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: jay
 */

#include "BitStream.h"

using namespace std;

BitStream::BitStream(istream & in): in(in), buffer(0), ticker(-1){
}

// Stores the next bit value into b. Gets a new byte if needed
bool BitStream::getBit(bool & b) {
	if (isGood()) {
		if (ticker == -1) {
			in.get(buffer);
			ticker = 7;
		}
		unsigned char q = 1;
		b = buffer & q<<ticker;
		ticker--;
		return true;
	} else {
		return false;
	}
}

bool BitStream::isGood() {
	return in.good();
}

BitStream::~BitStream() {
	// TODO Auto-generated destructor stub
}

