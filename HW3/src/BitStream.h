/*
 * BitStream.h
 *
 *  Created on: Feb 24, 2013
 *      Author: jay
 */

#ifndef BITSTREAM_H_
#define BITSTREAM_H_

#include <iostream>

class BitStream {
public:
	BitStream(std::istream & in);
	virtual ~BitStream();
	bool getBit(bool & b);
	bool isGood();
private:
	std::istream& in;
	char buffer;
	int ticker;
};

#endif /* BITSTREAM_H_ */
