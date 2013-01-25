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
#include "TreeNode.h"

using namespace std;

template <typename T>
class BTree {
public:
	BTree();
	~BTree();
	T* insert(T* item);
	T* lookup(T* item);
	bool is_empty();
	void dump_tree();
	//void walk(F f);
private:
	TreeNode<T>* root;
	T* re_lookup(T* item, TreeNode<T> * current);
	TreeNode<T>* recursive_insert(T* item, TreeNode<T> * current);
};

template <class T>
BTree<T>::BTree() {
	root = NULL;
}

template <class T>
BTree<T>::~BTree() {
	// TODO Auto-generated destructor stub
}

template <class T>
bool BTree<T>::is_empty() {
	return root == NULL;
}

template <class T>
TreeNode<T>* BTree<T>::recursive_insert(T* item, TreeNode<T>* current) {
	//base case (leaf node)
	if (!current->left && !current->mid && !current->right) {
		//case 1 key space available
		if (current->key1 && !current->key2) {
			if (*item < *current->key1) {
				current->key2 = current->key1;
				current->key1 = item;
			} else {
				current->key2 = item;
			}
			return NULL;
			//case 2 node is full, so split
		} else {
			current->left = new TreeNode<T>;
			current->mid = new TreeNode<T>;
			if (*item < *current->key1) {
				current->left->key1 = item;
				current->mid->key1 = current->key2;
				current->key2 = NULL;
				return current;
			} else if (*current->key2 < *item) {
				current->left->key1 = current->key1;
				current->mid->key1 = item;
				current->key1 = current->key2;
				current->key2 = NULL;
				return current;
			} else {
				current->left->key1 = current->key1;
				current->mid->key1 = current->key2;
				current->key2 = NULL;
				current->key1 = item;
				return current;
			}
		}
		// Recursive case, choose a path
	} else {
		TreeNode<T> * l = new TreeNode<T>;
		TreeNode<T> * r = new TreeNode<T>;
		TreeNode<T> * result;
		if (*item < *current->key1) { // Left path
			result = recursive_insert(item, current->left);
			if (result != NULL) { // Uh oh, need to split?
				if (current->key2) { //Node is full, split
					l->key1 = result->key1;
					r->key1 = current->key2;
					l->left = result->left;
					l->mid = result->mid;
					r->left = current->mid;
					r->mid = result->right;
				} else { // Node is not full
					current->key2 = current->key1;
					current->key1 = result->key1;
					current->right = current->mid;
					current->left = result->left;
					current->mid = result->mid;
					return NULL;
				}
			}
		} else if (current->key2 && *current->key2 < *item) { // right path
			result = recursive_insert(item, current->right);
			if (result != NULL) { // Uh oh, need to split?
				l->key1 = current->key1;
				r->key1 = result->key1;
				l->left = current->left;
				l->mid = current->mid;
				r->left = result->left;
				r->mid = result->mid;
				current->key1 = current->key2;
			}
		} else { // mid path
			result = recursive_insert(item, current->mid);
			if (result != NULL) { // Uh oh, need to split?
				if (current->key2) { //Node is full, split
					l->key1 = current->key1;
					r->key1 = current->key2;
					l->left = current->left;
					l->mid = result->left;
					r->left = result->mid;
					r->mid = current->right;
					current->key1 = result->key1;
				} else { // Node is not full
					current->key2 = result->key1;
					current->right = result->mid;
					current->mid = result->left;
					return NULL;
				}
			}
		}
		if (result){
			current->key2 = NULL;
			current->left = l;
			current->mid = r;
			current->right = NULL;
			return current;
		} else {
			return NULL;
		}
	}
	return NULL; //SHOULD NOT REACH HERE
}

template <class T>
T* BTree<T>::insert(T* item) {
	T* res = lookup(item);
	if (!res) {
		if (is_empty()) {
			root = new TreeNode<T>;
			root->key1 = item;
		} else {
			recursive_insert(item, root);
		}
		return lookup(item);
	} else {
		return res;
	}
}

template <class T>
T* BTree<T>::re_lookup(T* item, TreeNode<T> * current) {
	if (current == NULL)
		return NULL;
	if (!(*item < *current->key1)&&!(*current->key1 < *item))
		return current->key1;
	if (current->key2 && !(*item < *current->key2)&&!(*current->key2 < *item))
		return current->key2;
	if (*item < *current->key1)
		return re_lookup(item, current->left);
	else if (current->key2 && *current->key2 < *item)
		return re_lookup(item, current->right);
	else
		return re_lookup(item, current->mid);
}

template <class T>
T* BTree<T>::lookup(T* item) {
	return re_lookup(item, root);
}

#endif /* BTREE_H_ */
