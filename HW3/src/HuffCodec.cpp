#include "PQueue.h"
#include "HuffNode.h"
#include "BTreeMap.h"
#include "HuffTree.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void encode(ifstream & in, ofstream & out, BTreeMap<char, string> * encodings);

void decode(ifstream & in, ofstream & out, HuffTree & tree);

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
	file.close();

	counts.print();

	PQueue<HuffNode> queue;
	while(types.size() > 0) {
		HuffNode newNode(counts.get(types.back()),&types.back());
		types.pop_back();
		queue.push(newNode);
	}

	while (queue.size() > 1) {
		HuffNode * node1 = queue.pop();
		HuffNode * node2 = queue.pop();
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}

	HuffTree huff(queue.pop());
	BTreeMap<char, string> * encodings = new BTreeMap<char,string>();
	huff.addEncodings(encodings);

	encodings->print();

	file.open(argv[1], ios::in);
	ofstream out (argv[2]);

	encode(file, out, encodings);

	out.close();
	file.close();
	file.open(argv[2]);
//	out.open(argv[3]);
//
//	decode(file, out, huff);


	return 0;
}

void encode(ifstream & in, ofstream & out, BTreeMap<char, string> * encodings) {
	string line;
	while (getline(in,line)) {
			unsigned int i;
			for (i = 0 ; i < line.size() ; i++) {
				char c = line[i];
				string * cmd = encodings->get(c);
				unsigned short i = '\0';
				unsigned int k;
				for (k = 0; k < cmd->length(); k++) {
					if ((*cmd)[k]=='0') {
						i = i<<1;
					} else {
						i++;
						i = i<<1;
					}
				}
				i = i>>1;
				out.put(i);
			}
		}
}


void decode(ifstream & in, ofstream & out, HuffTree & tree) {
	char c;
	while (in.get(c)) {
		unsigned int i = c;

	}
}
