
#include "PQueue.h"
#include "HuffNode.h"
#include "CharFreqCounter.h"
#include "CounterToHuffNodePQ.h"
#include <iostream>

using namespace std;

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
	CounterToHuffNodePQ converter(&counts, &queue);

	while (!queue.isEmpty()) {
		HuffNode top = queue.pop();
		cout << top.getChar() << " " << top.getCount() << endl;
	}

	return 0;
}


