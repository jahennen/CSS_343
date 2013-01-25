/*
 * BTree.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: jay
 */

#include "BTreeold.h"

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
T* BTree<T>::split_node(T* new_key, TreeNode * current) {
	T* m;
	T* l;
	T* r;
	if (new_key < current->key1) {
		m = current->key1;
		l = new_key;
		r = current->key2;
	} else if (current->key2 < new_key) {
		m = current->key2;
		l = current->key1;
		r = new_key;
	} else {
		m = new_key;
		l = current->key1;
		r = current->key2;
	}
}

template <class T>
BTree<T>::TreeNode* BTree<T>::recursive_insert(T* item, TreeNode* current) {
	//base case (leaf node)
	if (!current->left && !current->mid && !current->right) {
		//case 1 key space available
		if (current->key1 && !current->key2) {
			if (item < current->key1) {
				current->key2 = current->key1;
				current->key1 = item;
			//case 2 node is full, so split
			} else {
				current->left = new TreeNode;
				current->mid = new TreeNode;
				if (item < current->key1) {
					current->left->key1 = item;
					current->mid->key1 = current->key2;
					current->key2 = NULL;
					return current;
				} else if (current->key2 < item) {
					current->left->key1 = current->key1;
					current->mid->key1 = item;
					current->key1 = current->key2;
					current->key2 = NULL;
					return current;
				} else {
					current->left->key1 = current->key1;
					current->mid->key2 = current->key2;
					current->key2 = NULL;
					current->key1 = NULL;
					return current;
				}
			}
		}
	// Recursive case, choose a path
	} else {
		if (item < current->key1) { // Left path
			TreeNode * result = recursive_insert(item, current->left);
			if (result != NULL) { // Uh oh, need to split?
				if (current->key2) { //Node is full, split
					TreeNode * l = new TreeNode();
					TreeNode * r = new TreeNode();
					l->key1 = result->key1;
					r->key1 = current->key2;
					l->left = result->left;
					l->mid = result->mid;
					r->left = current->mid;
					r->mid = result->right;
					current->left = l;
					current->mid = r;
					current->right = NULL;
					return current;
				} else { // Node is not full
					current->key2 = current->key1;
					current->key1 = result->key1;
					current->right = current->mid;
					current->left = result->left;
					current->mid = result->mid;
				}
				return NULL;
			}
		} else if (current->key2 && current->key2 < item) { // right path
			TreeNode * result = recursive_insert(item, current->right);
			if (result != NULL) { // Uh oh, need to split?
				TreeNode * l = new TreeNode();
				TreeNode * r = new TreeNode();
				l->key1 = current->key1;
				r->key1 = result->key1;
				l->left = current->left;
				l->mid = current->mid;
				r->left = result->left;
				r->mid = result->mid;
				current->key1 = current->key2;
				current->left = l;
				current->mid = r;
				current->right = NULL;
				return current;
			}
			return NULL;
		} else { // mid path
			TreeNode * result = recursive_insert(item, current->middle);
			if (result != NULL) { // Uh oh, need to split?
				if (current->key2) { //Node is full, split
					TreeNode * l = new TreeNode();
					TreeNode * r = new TreeNode();
					l->key1 = current->key1;
					r->key1 = current->key2;
					l->left = current->left;
					l->middle = result->left;
					r->left = result->middle;
					r->middle = current->right;
					current->key1 = result->key1;
					current->left = l;
					current->middle = r;
					current->right = NULL;
					return current;
				} else { // Node is not full
					current->key2 = result->key1;
					current->right = result->middle;
					current->middle = result->left;
				}
				return NULL;
			}
		}
	}
}

template <class T>
T* BTree<T>::insert(T* item) {
	if (is_empty()) {
		root = new TreeNode;
		root->key1 = item;
	} else {
		recursive_insert(item, root);
	}
}

template <class T>
T* BTree<T>::re_lookup(T* item, TreeNode * current) {
	if (current == NULL)
		return NULL;
	if (!(item < current->key1)&&!(current->key1 < item))
		return current->key1;
	if (!(item < current->key2)&&!(current->key2 < item))
		return current->key2;
	if (item < current->key1)
		return re_lookup(item, current->left);
	else if (current->key2 < item)
		return re_lookup(item, current->right);
	else
		return re_lookup(item, current->mid);
}

template <class T>
T* BTree<T>::lookup(T* item) {
	return re_lookup(item, root);
}

