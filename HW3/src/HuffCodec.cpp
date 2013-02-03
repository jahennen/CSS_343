#include "PQueue.h"
#include "HuffNode.h"
#include "CharFreqCounter.h"
#include "CounterToHuffNodePQ.h"
#include <iostream>
#include <map>

using namespace std;

void preorderPrint(HuffNode * current, string encoding);

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
	// and i1nsert them into the queue
	CounterToHuffNodePQ converter(&counts, &queue);

	while (queue.size() > 1) {
		HuffNode * node1 = new HuffNode(queue.pop());
		HuffNode * node2 = new HuffNode(queue.pop());
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}
	HuffNode root = queue.pop();

	map<char, string> encodings;

	return 0;
}

void preorderPrint(HuffNode * current) {
	if(current) {
		if ( current->c != '\0') {
			cout << current->c << " " << current->count<< endl;
		}
		preorderPrint(current->left);
		preorderPrint(current->right);
	}
}
