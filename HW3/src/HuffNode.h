/*
 * HuffTree.h
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#ifndef HUFFNODE_H_
#define HUFFNODE_H_

#include <iostream>

class HuffNode {
public:
	HuffNode();
	HuffNode(int sum, HuffNode * l, HuffNode * r);
	HuffNode(int count, char character);
	~HuffNode();
	unsigned char getChar();
	int getCount();
	HuffNode * getChild(bool bit);
	bool operator<(const HuffNode & rhs) const;
private:
	unsigned char c;
	int count;
	HuffNode * left;
	HuffNode * right;
};

#endif /* HUFFTREE_H_ */
