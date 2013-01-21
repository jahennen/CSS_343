/*
 * BTree.h
 *
 *  Created on: Jan 20, 2013
 *      Author: jay
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <cstdlib>
#include <iostream>

using namespace std;

class BTree {
public:
	BTree();
	T* insert(T* item);
	TreeNode* lookup(T* item);
	void walk(F f);
};

#endif /* BTREE_H_ */
