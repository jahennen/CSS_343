/*
 * HuffTree.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#include "HuffTree.h"

using namespace std;

HuffTree::HuffTree(HuffNode * huffroot) {
	root = huffroot;

}

void HuffTree::cleanUp(HuffNode * current) {
	if (!current->left) {
		return;
	} else {
		cleanUp(current->left);
		delete current->left;
		cleanUp(current->right);
		delete current->right;
	}
}

HuffTree::~HuffTree() {
	cleanUp(root);
	delete root;
}

void HuffTree::re_addEncodings(vector<string> * map, HuffNode *current, string & encoding) {
	if (!current->left) { // leaf node, there's an encoding here
		if (current == root) { // leaf and root (edge case where only 1 char is in tree)
			encoding.push_back('0');
			map->at(current->c) = encoding;
		}
		map->at(current->c) = encoding;
	} else {
		encoding.push_back('0');
		re_addEncodings(map, current->left, encoding);
		encoding.erase(encoding.length()-1);
		encoding.push_back('1');
		re_addEncodings(map, current->right, encoding);
		encoding.erase(encoding.length()-1);
	}
}

void HuffTree::addEncodings(vector<string> * map) {
	string encoding = "";
	re_addEncodings(map, root, encoding);
}

//char HuffTree::re_findEncoding(string & encoding, HuffNode * current) {
//	if (!current->left) { // this is a leaf node
//		return current->c;
//	} else {
//		if (encoding[0] == '0') {
//			encoding.erase(0);
//			return re_findEncoding(encoding, current->left);
//		} else {
//			encoding.erase(0);
//			return re_findEncoding(encoding, current->right);
//		}
//	}
//}

HuffNode * HuffTree::returnRoot() {
	return root;
}

