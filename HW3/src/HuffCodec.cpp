#include "PQueue.h"
#include "HuffNode.h"
#include "HuffTree.h"
#include <iostream>
#include <fstream>

using namespace std;

void encode(ifstream & in, ofstream & out, vector<string> * encodings);

void decode(ifstream & in, ofstream & out, HuffTree & tree);

void printEncodings(vector<int> & counts, vector<string> & encodings);

int main(int argc, char* argv[]) {
	vector<int> types(256);
	char c;
	ifstream file;
	file.open(argv[1], ios::in);
	while (file.get(c)) {
		types[(unsigned char)c]++;
	}
	file.close();

	PQueue<HuffNode> queue;
	unsigned int k;
	for(k = 0; k < types.size(); k++) {
		if (types[k] != 0) {
			HuffNode newNode(types[k],k);
			queue.push(newNode);
		}
	}

	while (queue.size() > 1) {
		HuffNode * node1 = queue.pop();
		HuffNode * node2 = queue.pop();
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}

	HuffTree huff(queue.pop());
	vector<string> encodings(256);
	huff.addEncodings(&encodings);
	printEncodings(types, encodings);

	file.open(argv[1], ios::in); // reopen file
	ofstream out (argv[2]); // create output file

	encode(file, out, &encodings);

	out.close();
	file.close();
	file.open(argv[2]); // open coded file
	out.open(argv[3]);  // create decode file

	decode(file, out, huff);
	return 0;
}

void encode(ifstream & in, ofstream & out, vector<string> * encodings) {
	char c;
	unsigned char byte;
	string cmd;
	while (in.get(c)) {
		cmd.append(encodings->at((unsigned char)c)); // append encodings
		while (cmd.length() < 8 && !in.eof()) { // while cmd < 8 bits long and next char is not EOF
			in.get(c);
			cmd.append(encodings->at((unsigned char)c)); // append encodings
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
	out.put(byte); // this should be the last byte
}

void decode(ifstream & in, ofstream & out, HuffTree & tree) {
	char c;
	string buf;
	HuffNode * root = tree.returnRoot();
	HuffNode * current = root;
	int maxChars = root->getCount();
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
	if (current->getChar() != '\0')
		out.put(current->getChar()); // Last character
}

class outString {
public:
	int count;
	char c;
	string encoding;
	bool operator<(const outString & rhs) const {
		return count < rhs.count;
	}
};

void printEncodings(vector<int> & counts, vector<string> & encodings) {
	PQueue<outString> sorter;
	unsigned int i;
	for (i = 0; i < 256; i++) {
		if (counts[i] != 0) {
			outString o = {counts[i],(char)i,encodings[i]};
			sorter.push(o);
		}
	}
	while (!sorter.isEmpty()) {
		outString * out = sorter.pop();
		printf("0x%-2x  ", out->c);
		if (isprint(out->c)) {
			cout << "(" << out->c << ")";
		} else {
			cout << "( )";
		}
		printf("%8d  ", out->count);
		cout << "[" << out->encoding << "]" << endl;
		delete out;
	}
}
