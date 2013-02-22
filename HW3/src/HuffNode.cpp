/*
 * HuffTree.cpp
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#include "HuffNode.h"

using namespace std;

HuffNode::HuffNode() {
	c = '\0';
	count = 0;
	left = NULL;
	right = NULL;
}

HuffNode::HuffNode(int sum, HuffNode * l, HuffNode * r) {
	c = '\0';
	count = sum;
	left = l;
	right = r;
}

HuffNode::HuffNode(int num, char character) {
	count = num;
	c = character;
	right = NULL;
	left = NULL;
}

HuffNode::~HuffNode() {

}

unsigned char HuffNode::getChar() {
	return c;
}

int HuffNode::getCount() {
	return count;
}

bool HuffNode::operator<(const HuffNode & rhs) const {
	return count < rhs.count;
}
