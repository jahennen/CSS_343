#include "PQueue.h"
#include "HuffNode.h"
#include "BTreeMap.h"
#include "HuffTree.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <map>

using namespace std;

void encode(ifstream & in, ofstream & out, BTreeMap<char, string> * encodings);

void decode(ifstream & in, ofstream & out, HuffTree & tree, BTreeMap<char, int> & counts);

int main(int argc, char* argv[]) {
	BTreeMap<char, int> counts;
	vector<char> types;
//	string line;
//	ifstream file;
//	file.open(argv[1], ios::in);
//	while (getline(file,line)) {
//		line.push_back('\n');
//		unsigned int i;
//		for (i = 0 ; i < line.size() ; i++) {
//			char c = line[i];
//			if (counts.containsKey(c)) {
//				int * count = counts.get(c);
//				*count += 1;
//			} else {
//				int i = 1;
//				counts.add(c,i);
//				types.push_back(c);
//			}
//		}
//	}
	vector<char> types;
	char c;
	ifstream file;
	file.open(argv[1], ios::in);
	while (file.get(c)) {
		if (counts.containsKey(c)) {
			int * count = counts.get(c);
			*count += 1;
		} else {
			int i = 1;
			counts.add(c,i);
			types.push_back(c);
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
	out.open(argv[3]);

	decode(file, out, huff, counts);


	return 0;
}

void encode(ifstream & in, ofstream & out, BTreeMap<char, string> * encodings) {
	char c;
	unsigned char byte;
	string cmd;
	while (in.get(c)) {
		cmd.append(*encodings->get(c)); // append encodings
		while (cmd.length() < 8 && !in.eof()) { // while cmd < 8 bits long and next char is not EOF
			in.get(c);
			cmd.append(*encodings->get(c)); // append encodings
		}
		unsigned int byteLen = 8;
		if (cmd.length() >= byteLen) {
			unsigned int j;
			for (j = 0; j < byteLen-1; j++) { // write 8 bits to the byte
				if (cmd[j]=='0') {
					byte = byte<<1;
				} else {
					byte++;
					byte = byte<<1;
				}
			}
			if (cmd[j]=='1') {
				byte++;
			}
			cmd.erase(0,byteLen); // erase the characters which have been written
			out.put(byte);
			byte = 0; //reset byte
		} // if encodings of characters in line do not fill a byte, then just continue
	}
	unsigned int j;
	for (j = 0; j < cmd.length()-1; j++) { // write final bits to the byte
		if (cmd[j]=='0') {
			byte = byte<<1;
		} else {
			byte++;
			byte = byte<<1;
		}
	}
	unsigned int pad = 8 - cmd.length();
	for (j = 0; j < pad; j++) { // shift final byte to proper alignment
		byte = byte<<1;
	}
	cout << cmd << "  " << (int)byte << endl;
	out.put(byte); // this should be the last byte
}

void decode(ifstream & in, ofstream & out, HuffTree & tree, BTreeMap<char, int> & counts) {
	char c;
	string buf;
	HuffNode * root = tree.returnRoot();
	HuffNode * current = root;
	int maxChars = root->getCount();
	cout << "chars" << maxChars << endl;
	int k = 0;
	while (k < maxChars-1) {
		in.get(c); // store coded character into c
		int j;
		for (j = 7; j >= 0; j--) { // create the tree traversal string from c
			unsigned char q = 1;
			if (c & q<<j) {
				buf.push_back('1');
			} else {
				buf.push_back('0');
			}
		}
		while(buf.length() > 0) { // process 8 'directions' in batch
			char curChar = current->getChar();
			if (curChar != '\0') {
				k++;
				out.put(curChar);
				current = root;
			}
			if (buf[0] == '0') { // traverse the tree, then trim command string
				current = current->left;
			} else {
				current = current->right;
			}
			buf.erase(buf.begin());
		}
	}
	out.put(current->getChar()); // Last character
}
