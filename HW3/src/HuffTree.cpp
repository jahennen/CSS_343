/*
 * HuffTree.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#include "HuffTree.h"

HuffTree::HuffTree(HuffNode * huffroot) {
	root = huffroot;

}

HuffTree::~HuffTree() {
	// TODO Auto-generated destructor stub
}

void HuffTree::re_addEncodings(BTreeMap<char, string> * map, HuffNode *current, string & encoding) {
	if (!current->left) { // leaf node, there's an encoding here
		if (current == root) { // leaf and root (edge case where only 1 char is in tree)
			encoding.push_back('0');
			map->add(current->c, encoding);
		}
		map->add(current->c, encoding);
	} else {
		encoding.push_back('0');
		re_addEncodings(map, current->left, encoding);
		encoding.erase(encoding.length()-1);
		encoding.push_back('1');
		re_addEncodings(map, current->right, encoding);
		encoding.erase(encoding.length()-1);
	}
}

void HuffTree::addEncodings(BTreeMap<char, string> * map) {
	string encoding = "";
	re_addEncodings(map, root, encoding);
}

