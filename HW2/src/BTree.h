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

template <class T>
class BTree {
	class TreeNode {
		T* key1 = NULL;
		T* key2 = NULL;
		TreeNode * left = NULL;
		TreeNode * mid = NULL;
		TreeNode * right = NULL;
		bool split = false;
	};
public:
	BTree();
	~BTree();
	T* insert(T* item);
	T* lookup(T* item);
	bool isEmpty();
	//void walk(F f);
private:
	TreeNode* root;
	T* re_lookup(T* item, TreeNode * current);
	T* recursive_insert(T* item, TreeNode * current);
};

#include "BTree.cpp.h"

#endif /* BTREE_H_ */
