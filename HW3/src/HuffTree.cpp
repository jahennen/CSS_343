/*
 * HuffTree.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#include "HuffTree.h"

using namespace std;

// Constructs a HuffTree object from a vector of character counts.
HuffTree::HuffTree(vector<int>& types) {
	PQueue<HuffNode> queue;
	unsigned int k;
	for(k = 0; k < types.size(); k++) {
		if (types[k] != 0) {
			HuffNode newNode(types[k],k);
			queue.push(newNode);
		}
	}

	while (queue.size() > 1) {
		HuffNode * node1 = queue.top();
		queue.pop();
		HuffNode * node2 = queue.top();
		queue.pop();
		HuffNode newNode(node1->getCount()+node2->getCount(), node1, node2);
		queue.push(newNode);
	}
	root = queue.top();
	queue.pop();
}

// Traverses the tree using bits from a BitStream and writes the resulting
// discovered characters to the ostream.
void HuffTree::decode(BitStream & bits, ostream & out) {
	int maxChars = root->getCount();
	int k = 0;
	HuffNode * current = root;
	bool bit;
	while (k < maxChars) {
		bits.getBit(bit); // store bit value into bit
		char curChar = current->getChar();
		if (!current->left) { //leaf
			k++;
			out.put(curChar);
			current = root; //reset back to root
		}
		current = current->getChild(bit);
	}
}

HuffTree::~HuffTree() {
	clean_up(root);
	delete root;
}

void HuffTree::clean_up(HuffNode * current) {
	if (current->left) { // not leaf
		clean_up(current->left);
		delete current->left;
		clean_up(current->right);
		delete current->right;
	}
}

// Helper method to recursively traverse the tree, produce encodings, and add them
// to the passed collection.
void HuffTree::re_addEncodings(vector<string> & map, HuffNode * current, string & encoding) {
	if (!current->left) { // leaf node, there's an encoding here
		if (current == root) { // leaf and root (edge case where only 1 char is in tree)
			encoding.push_back('0');
			map.at(current->c) = encoding;
		}
		map.at(current->c) = encoding;
	} else {
		encoding.push_back('0');
		re_addEncodings(map, current->left, encoding);
		encoding.erase(encoding.length()-1);
		encoding.push_back('1');
		re_addEncodings(map, current->right, encoding);
		encoding.erase(encoding.length()-1);
	}
}

//Creates and adds all encodings in the tree to the passed collection.
void HuffTree::addEncodings(vector<string> & map) {
	string encoding = "";
	re_addEncodings(map, root, encoding);
}

HuffTree::HuffNode::HuffNode() {
	c = '\0';
	count = 0;
	left = NULL;
	right = NULL;
}

HuffTree::HuffNode::HuffNode(int sum, HuffNode * l, HuffNode * r) {
	c = '\0';
	count = sum;
	left = l;
	right = r;
}

HuffTree::HuffNode::HuffNode(int num, char character) {
	count = num;
	c = character;
	right = NULL;
	left = NULL;
}

HuffTree::HuffNode::~HuffNode() {
}

unsigned char HuffTree::HuffNode::getChar() {
	return c;
}

int HuffTree::HuffNode::getCount() {
	return count;
}

HuffTree::HuffNode * HuffTree::HuffNode::getChild(bool bit) {
	if (bit) {
		return right;
	} else {
		return left;
	}
}

bool HuffTree::HuffNode::operator<(const HuffNode & rhs) const {
	return count < rhs.count;
}

