/*
 * CounterToHuffNodePQ.cpp
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#include "CounterToHuffNodePQ.h"

CounterToHuffNodePQ::CounterToHuffNodePQ(CharFreqCounter * counter, PQueue<HuffNode> * queue) {
	CharIntMapConverter converter(queue);
	counter->walk(converter);
}

CounterToHuffNodePQ::~CounterToHuffNodePQ() {
	// TODO Auto-generated destructor stub
}
