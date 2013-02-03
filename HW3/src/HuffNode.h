/*
 * HuffTree.h
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include <cstdlib>
#include <iostream>
#include "CharIntMap.h"

using namespace std;

class HuffNode {
public:
	HuffNode();
	HuffNode(int sum, HuffNode * l, HuffNode * r);
	HuffNode(CharIntMap * item);
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
