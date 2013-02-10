/*
 * HuffTree.h
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#ifndef HUFFNODE_H_
#define HUFFNODE_H_

#include <iostream>

using namespace std;

class HuffNode {
public:
	HuffNode();
	HuffNode(int sum, HuffNode * l, HuffNode * r);
	HuffNode(int count, char character);
	~HuffNode();
	char getChar();
	int getCount();
	bool operator<(const HuffNode & rhs) const;
	char c;
	int count;
	HuffNode * left;
	HuffNode * right;
private:

};

#endif /* HUFFTREE_H_ */
