#include "PQueue.h"
#include "HuffNode.h"
#include "CharFreqCounter.h"
#include "CounterToHuffNodePQ.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	BTreeMap<char, int> counts;
	vector<char> types;
	string line;
	ifstream file;
	file.open(argv[1], ios::in);
	while (getline(file,line)) {
		unsigned int i;
		for (i = 0 ; i < line.size() ; i++) {
			char c = line[i];
			if (counts.containsKey(c)) {
				int * count = counts.get(c);
				*count += 1;
			} else {
				int i = 1;
				counts.add(c,i);
				types.push_back(c);
			}
		}
	}

	PQueue<HuffNode> queue;
	while(types.size() > 0) {
		HuffNode newNode(counts.get(types.back()),types.back());
		types.pop_back();
		queue.push(newNode);
	}

	while (queue.size() > 1) {
		HuffNode * node1 = new HuffNode(queue.pop());
		HuffNode * node2 = new HuffNode(queue.pop());
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}
	HuffNode root = queue.pop();

	BTreeMap<char, string> encodings;



	return 0;
}
