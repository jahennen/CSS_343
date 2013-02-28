/*
 * HuffCodec.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 *
 */

#include "HuffTree.h"
#include "BitStream.h"
#include "PQueue.h"
#include <iostream>
#include <fstream>

using namespace std;

void encode(istream & in, ostream & out, vector<string> & encodings);

void processCmd(string & cmd, unsigned char & byte, int & ticker, ostream & out);

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


	HuffTree huff(types);
	vector<string> encodings(256);
	huff.addEncodings(encodings);
	printEncodings(types, encodings);

	file.open(argv[1], ios::in); // reopen file
	ofstream out (argv[2]); // create output file

	encode(file, out, encodings);

	out.close();
	file.close();
	file.open(argv[2]); // open coded file
	out.open(argv[3]);  // create decode file

	BitStream bits(file);
	huff.decode(bits, out);
	return 0;
}

// Encodes all chars in the istream using the encodings and writes the encoded byte
// to the ostream.
void encode(istream & in, ostream & out, vector<string> & encodings) {
	char c;
	unsigned char byte;
	string cmd;
	int ticker = 0;
	while (in.get(c)) {
		cmd.append(encodings.at((unsigned char)c)); // append encodings
		processCmd(cmd, byte, ticker, out);
	}
	processCmd(cmd, byte, ticker, out);
	byte = byte>>1;
	int k;
	for (k = 0; k < 8-ticker; k++)
		byte = byte<<1;
	out.put(byte); // this should be the last byte
}

// processes one encoding string at a time, writing bytes as necessary.
void processCmd(string & cmd, unsigned char & byte, int & ticker, ostream & out) {
	unsigned int j;
	for (j = 0; j < cmd.length(); j++) { // write bits to the byte
		ticker++;
		if (cmd[j]=='1') {
			byte++;
		}
		if (ticker == 8) { //byte is done, write it
			out.put(byte);
			byte = 0; //reset byte
			ticker = 0;
		}
		byte = byte<<1;
	}
	cmd.clear(); // erase the command string
}

// Helper class to compile/retain information about a char and encoding. Also
// allows these entries to be sorted.
class outString {
public:
	int count;
	char c;
	string encoding;
	bool operator<(const outString & rhs) const {
		return count < rhs.count;
	}
};

// Produces the properly formatted output to cout.
void printEncodings(vector<int> & counts, vector<string> & encodings) {
	PQueue<outString> sorter;
	unsigned int i;
	for (i = 0; i < 256; i++) {
		if (counts[i] != 0) {
			outString o = {counts[i],(char)i,encodings[i]};
			sorter.push(o);
		}
	}
	while (!sorter.empty()) {
		outString * out = sorter.top();
		sorter.pop();
		printf("0x%-2x  ", out->c);
		if (isprint(out->c)) {
			cout << "(" << out->c << ")";
		} else {
			cout << "( )";
		}
		printf("%8d  ", out->count);
		cout << "[" << out->encoding << "] (" << out->encoding.length() << ")" << endl;
		delete out;
	}
}
