/*
 * BTree.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: jay
 */

#include "BTree.h"

template <class T>
BTree<T>::BTree() {
	root = NULL;
}

template <class T>
BTree<T>::~BTree() {
	// TODO Auto-generated destructor stub
}

template <class T>
bool BTree<T>::isEmpty() {
	return root == NULL;
}

template <class T>
T* BTree<T>::recursive_insert(T* item, TreeNode * current) {
	//base case (leaf node)
	if (!current->left && !current->mid && !current->right) {
		//case 1 key space available
		if (current->key1 && !current->key2) {
			if (item < current->key1) {
				current->key2 = current->key1;
				current->key1 = item;
			//case 2 key already exists in this node
			} else if (item == current->key1 || item == current->key2) {
				cout << "Key already exists";
				if (item == current->key1)
					return current->key1;
				else
					return current->key2;
			//case 3 node is full
			} else {
				current->split = true;
				return NULL;
			}
		}
	// Recursive case, choose a path
	} else {
		if (item < current->key1) {
			//Now, this can come back returning either NULL, or a T*
			//if it's a NULL, then reorganization needs to take place
			if (T* temp = recursive_insert(item, current->left) = NULL) {
				//child node is full and asks for split

			}
		}
	}
}

template <class T>
T* BTree<T>::insert(T* item) {
	if (isEmpty()) {
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
	if (item < current->key2 && current->key1 < item)
		return re_lookup(item, current->mid);
	if (current->key2 < item)
		return re_lookup(item, current->right);
}

template <class T>
T* BTree<T>::lookup(T* item) {
	return re_lookup(item, root);
}

