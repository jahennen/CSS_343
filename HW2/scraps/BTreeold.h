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
	};
public:
	BTree();
	~BTree();
	T* insert(T* item);
	T* lookup(T* item);
	bool is_empty();
	//void walk(F f);
private:
	TreeNode<T>* root;
	T* split_node(T* new_key, TreeNode * current);
	T* re_lookup(T* item, TreeNode * current);
	TreeNode<T>* recursive_insert(T* item, TreeNode * current);
};

#include "BTreeold.cpp.h"

#endif /* BTREE_H_ */
