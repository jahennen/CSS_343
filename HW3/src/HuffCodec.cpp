#include "PQueue.h"
#include "HuffNode.h"
#include "CharFreqCounter.h"
#include "CounterToHuffNodePQ.h"
#include <iostream>

using namespace std;

void preorderPrint(HuffNode current);

int main() {
	CharFreqCounter counts;
	string line;
	while (getline(cin,line)) {
		unsigned int i;
		for (i = 0 ; i < line.size() ; i++) {
			char c = line[i];
			if (!counts.lookup(c)) {
				counts.addCount(c);
			} else {
				counts.increment(c);
			}
		}
	}
	counts.print();

	PQueue<HuffNode> queue;
	// Use conversion object to transform CharFreqCounter elements into HuffNodes,
	// and insert them into the queue
	CounterToHuffNodePQ converter(&counts, &queue);

	while (queue.size() > 1) {
		HuffNode * node1 = new HuffNode(queue.pop());
		HuffNode * node2 = new HuffNode(queue.pop());
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}
	HuffNode root = queue.pop();

	return 0;
}

void preorderPrint(HuffNode current) {
//	if (current) {
//		cout << current.g
//	}
}
