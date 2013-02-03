/*
 * CounterToHuffNodePQ.h
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#ifndef COUNTERTOHUFFNODEPQ_H_
#define COUNTERTOHUFFNODEPQ_H_

#include "HuffNode.h"
#include "CharFreqCounter.h"
#include "PQueue.h"

// Converts a CharIntMap passed to it into a HuffNode and inserts it
// into a priorty queue passed to it
class CharIntMapConverter {
public:
	CharIntMapConverter(PQueue<HuffNode> * pq) {
		q = pq;
	}
	void operator()(CharIntMap * k) {
		HuffNode newNode(k);
		q->push(newNode);
	}
private:
	PQueue<HuffNode> * q;
};

class CounterToHuffNodePQ {
public:
	CounterToHuffNodePQ(CharFreqCounter * counter, PQueue<HuffNode> * queue);
	~CounterToHuffNodePQ();
};

#endif /* COUNTERTOHUFFNODEPQ_H_ */
