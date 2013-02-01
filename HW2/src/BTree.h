/*
 * BTree.h
 *
 *  Created on: Jan 20, 2013
 *      Author: Jay Hennen
 *
 *      This is an implementation of the 2-3 Tree data structure. It is important
 *      to note that this implementation does NOT directly own the *item objects
 *      assigned to it, and you WILL need to clean these objects up if no other reference
 *      to them exists before destroying the tree or you will suffer a memory leak
 */

#ifndef BTREE_H_
#define BTREE_H_

#include <cstdlib>
#include <iostream>
#include "counter/counter.h"

using namespace std;

template <typename T>
class BTree;

// TreeNode object used by the BTree
template <typename T>
class TreeNode {
	friend class BTree<T>;
public:
	TreeNode();
private:
	T* key1;
	T* key2;
	TreeNode* left; //pointer to left child node of node
	TreeNode* mid; //pointer to right child node of node
	TreeNode* right; //pointer to right child node of node
};

// TreeNode constructor
template <typename T>
TreeNode<T>::TreeNode()
{
	key1 = NULL;
	key2 = NULL;
	left = NULL;
	mid  = NULL;
	right = NULL;
}

// BTree class declaration.
template <typename T>
class BTree {
public:
	BTree();
	~BTree();
	T* insert(T* item);
	T* remove(T* item);
	T* lookup(T* item);
	bool is_empty();
	template <typename F>
	void walk(F f);
private:
	void clean_up(TreeNode<T> * current);
	TreeNode<T>* root;
	TreeNode<T>* re_lookup(T* item, TreeNode<T> * current);
	TreeNode<T>* recursive_insert(T* item, TreeNode<T> * current);
	TreeNode<T>* recursive_remove(T* item, TreeNode<T> * current);
	TreeNode<T>* find_parent(T* item, TreeNode<T> * current, TreeNode<T> * child);
	template <typename F>
	void re_walk(F f, TreeNode<T> * current);
	void fix(TreeNode<T>* item, TreeNode<T> * hole);
};

template <typename T>
BTree<T>::BTree() {
	root = NULL;
}

// Recursively cleans up the TreeNodes. DOES NOT FREE HELD KEYS FROM MEMORY
template <typename T>
void BTree<T>::clean_up(TreeNode<T> * current) {
	if (is_empty()) { // nothing to do
		return;
	}
	if (!current->left) { //Leaf
		current->key1 = NULL;
		if (current->key2)
			current->key2 = NULL;
	} else {
		clean_up(current->left);
		delete current->left;
		current->key1 = NULL;
		clean_up(current->mid);
		delete current->mid;
		if (current->key2) {
			current->key2 = NULL;
			clean_up(current->right);
			delete current->right;
		}
	}
}

template <typename T>
BTree<T>::~BTree() {
	clean_up(root);
	delete root;
}

template <typename T>
bool BTree<T>::is_empty() {
	return root == NULL;
}

// Recursive lookup helper. Finds the TreeNode where the item is held
template <typename T>
TreeNode<T>* BTree<T>::re_lookup(T* item, TreeNode<T> * current) {
	if (current == NULL)
		return NULL;
	if (!(*item < *current->key1)&&!(*current->key1 < *item))
		return current;
	if (current->key2 && !(*item < *current->key2)&&!(*current->key2 < *item))
		return current;
	if (*item < *current->key1)
		return re_lookup(item, current->left);
	else if (current->key2 && *current->key2 < *item)
		return re_lookup(item, current->right);
	else
		return re_lookup(item, current->mid);
}

// Checks the item against the keys in the node returned by re_lookup and returns
// the correct one
template <typename T>
T* BTree<T>::lookup(T* item) {
	TreeNode<T>* result = re_lookup(item, root);
	if (result) {
		if (!(*item < *result->key1)&&!(*result->key1 < *item))
			return result->key1;
		if (result->key2 && !(*item < *result->key2)&&!(*result->key2 < *item))
			return result->key2;
	}
	return NULL;
}

// Recursive insert helper
template <typename T>
TreeNode<T>* BTree<T>::recursive_insert(T* item, TreeNode<T>* current) {
	if (!current->left && !current->mid && !current->right) {	//base case (leaf node)
		// case 1 key space available
		if (current->key1 && !current->key2) {
			Counter::increment("Insert open leaf",1);
			if (*item < *current->key1) {
				current->key2 = current->key1;
				current->key1 = item;
			} else {
				current->key2 = item;
			}
			return NULL;
		} else { // case 2 node is full, so split
			Counter::increment("Insert full leaf",1);
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
	} else {	// Recursive case, choose a path
		TreeNode<T> * l;
		TreeNode<T> * r;
		TreeNode<T> * result;
		if (*item < *current->key1) { // Left path
			result = recursive_insert(item, current->left);
			if (result != NULL) { // Uh oh, need to split?
				if (current->key2) { //Node is full, split
					Counter::increment("Insert from left into full",1);
					l = new TreeNode<T>;
					r = new TreeNode<T>;
					l->key1 = result->key1;
					r->key1 = current->key2;
					l->left = result->left;
					l->mid = result->mid;
					r->left = current->mid;
					r->mid = current->right;
				} else { // Node is not full
					Counter::increment("Insert from left into open",1);
					current->key2 = current->key1;
					current->key1 = result->key1;
					current->right = current->mid;
					current->mid = result->mid;
					current->left = result->left;
					delete result; //result has been merged
					return NULL;
				}
			}
		} else if (current->key2 && *current->key2 < *item) { // right path
			result = recursive_insert(item, current->right);
			if (result != NULL) { // Uh oh, need to split?
				Counter::increment("Insert from right into full",1);
				l = new TreeNode<T>;
				r = new TreeNode<T>;
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
				if (current->key2) { // Node is full, split
					Counter::increment("Insert from mid into full",1);
					l = new TreeNode<T>;
					r = new TreeNode<T>;
					l->key1 = current->key1;
					r->key1 = current->key2;
					l->left = current->left;
					l->mid = result->left;
					r->left = result->mid;
					r->mid = current->right;
					current->key1 = result->key1;
				} else { // Node is not full
					Counter::increment("Insert from mid into open",1);
					current->key2 = result->key1;
					current->right = result->mid;
					current->mid = result->left;
					delete result; // result has been merged
					return NULL;
				}
			}
		}
		if (result){
			current->key2 = NULL;
			current->left = l;
			current->mid = r;
			current->right = NULL;
			delete result; // result has been merged
			return current;
		} else {
			return NULL;
		}
	}
	return NULL; // SHOULD NOT REACH HERE
}

// Inserts an item in to the tree if it does not already exist. Returns the item inserted.
template <typename T>
T* BTree<T>::insert(T* item) {
	T* res = lookup(item);
	if (!res) {
		if (is_empty()) {
			root = new TreeNode<T>;
			root->key1 = item;
			Counter::increment("Insert 1st element",1);
		} else {
			recursive_insert(item, root);
		}
		return lookup(item);
	} else {
		return res;
	}
}

// Finds the parent of the node 'child' starting from 'current' using the search key 'item'
template <typename T>
TreeNode<T>* BTree<T>::find_parent(T* item, TreeNode<T> * current, TreeNode<T> * child) {
	if (current == child) {
		return NULL;
	}
	if (current->left == child || current->mid == child ||
			(current->right && current->right == child)) {	// base case, this node is parent
		return current;
	} else { // use item to path down the tree
		if (*item < *current->key1)
			return find_parent(item, current->left, child);
		else if (current->key2 && *current->key2 < *item)
			return find_parent(item, current->right, child);
		else
			return find_parent(item, current->mid, child);
	}
}

// Fixes holes in the tree by merging nodes
template <typename T>
void BTree<T>::fix(TreeNode<T>* parent, TreeNode<T>* hole) {
	if (hole == root) {
		Counter::increment("Moved root from hole",1);
		root = hole->left; // TEMPORARY
		delete(hole);
	} else {
		TreeNode<T>* lc = parent->left;  // left child
		TreeNode<T>* mc = parent->mid;	 // mid child
		TreeNode<T>* rc = parent->right; // right child
		if (parent->key2) { // parent has 2 keys, therefore 3 children
			if(lc == hole) { // hole is left
				if (mc->key2) { // hole is left node, middle is full
					Counter::increment("Del parent full left hole mid full",1);
					// rearrange keys
					lc->key1 = parent->key1;
					parent->key1 = mc->key1;
					mc->key1 = mc->key2;
					mc->key2 = NULL;
					// shift ptrs
					lc->mid = mc->left;
					mc->left = mc->mid;
					mc->mid = mc->right;
					mc->right = NULL;
				} else if (rc->key2){ //hole is left, middle sibling has 1 key, right full
					Counter::increment("Del parent full left hole mid open right full",1);
					// rearrange keys
					lc->key1 = parent->key1;
					parent->key1 = mc->key1;
					mc->key1 = parent->key2;
					parent->key2 = rc->key1;
					rc->key1 = rc->key2;
					rc->key2 = NULL;
					// shift ptrs
					lc->mid = mc->left;
					mc->left = mc->mid;
					mc->mid = rc->left;
					rc->left = rc->mid;
					rc->mid = rc->right;
					rc->right = NULL;
				} else { // hole is left, mid, right have 1 key
					Counter::increment("Del parent full left hole mid open right open",1);
					// rearrange keys
					lc->key1 = parent->key1;
					lc->key2 = mc->key1;
					parent->key1 = parent->key2;
					parent->key2 = NULL;
					// shift ptrs
					lc->mid = mc->left;
					lc->right = mc->mid;
					delete(parent->mid);
					parent->mid = parent->right;
					parent->right = NULL;
				}
				return;
			} else if (mc == hole) { // hole is mid
				if (rc->key2) { // hole is mid, right full
					Counter::increment("Del parent full mid hole right full",1);
					// rearrange keys
					mc->key1 = parent->key2;
					parent->key2 = rc->key1;
					rc->key1 = rc->key2;
					rc->key2 = NULL;
					// shift ptrs
					mc->mid = rc->left;
					rc->left = rc->mid;
					rc->mid = rc->right;
					rc->right = NULL;
				} else if (lc->key2) { //hole is mid, left is full, right has 1
					Counter::increment("Del parent full mid hole left full right open",1);
					// rearrange keys
					mc->key1 = parent->key1;
					parent->key1 = lc->key2;
					lc->key2 = NULL;
					// shift ptrs
					mc->mid = mc->left;
					mc->left = lc->right;
					lc->right = NULL;
				} else { // hole is mid, left has 1, right has 1
					Counter::increment("Del parent full mid hole left open right open",1);
					// rearrange keys
					lc->key2 = parent->key1;
					parent->key1 = parent->key2;
					parent->key2 = NULL;
					// shift ptrs
					lc->right = mc->left;
					delete(parent->mid);
					parent->mid = parent->right;
					parent->right = NULL;
				}
				return;
			} else { // hole is right
				if (mc->key2) { // hole is right, mid is full
					Counter::increment("Del parent full right hole mid full",1);
					// rearrange keys
					rc->key1 = parent->key2;
					parent->key2 = mc->key2;
					mc->key2 = NULL;
					// shift ptrs
					rc->mid = rc->left;
					rc->left = mc->right;
					mc->right = NULL;
				} else { // hole is right, mid has 1
					Counter::increment("Del parent full right hole mid open",1);
					// rearrange keys
					mc->key2 = parent->key2;
					parent->key2 = NULL;
					// shift ptrs
					mc->right = rc->left;
					delete parent->right;
					parent->right = NULL;
				}
				return;
			}

		} else { // Parent has 1 key. Might need to push hole upwards
			if(lc == hole) { // hole is left
				if (mc->key2) { // hole is left, mid is full
					Counter::increment("Del parent open left hole mid full",1);
					// rearrange keys
					lc->key1 = parent->key1;
					parent->key1 = mc->key1;
					mc->key1 = mc->key2;
					mc->key2 = NULL;
					// shift ptrs
					lc->mid = mc->left;
					mc->left = mc->mid;
					mc->mid = mc->right;
					mc->right = NULL;
				} else { // hole is left, mid has 1
					Counter::increment("Del parent open left hole mid open",1);
					// rearrange keys
					lc->key1 = parent->key1;
					lc->key2 = mc->key1;
					parent->key1 = NULL;
					// shift ptrs
					lc->mid = mc->left;
					lc->right = mc->mid;
					delete(parent->mid);
					parent->mid = NULL; // Parent is new hole
					fix(find_parent(lc->key1,root,parent), parent);
				}
			} else if (mc == hole) {
				if (lc->key2) { // hole is mid, left is full
					Counter::increment("Del parent open mid hole left full",1);
					// rearrange keys
					mc->key1 = parent->key1;
					parent->key1 = lc->key2;
					lc->key2 = NULL;
					// shift ptrs
					mc->mid = mc->left;
					mc->left = lc->right;
					lc->right = NULL;
				} else { // hole is mid, left has 1
					Counter::increment("Del parent open mid hole left open",1);
					// rearrange keys
					lc->key2 = parent->key1;
					parent->key1 = NULL;
					// shift ptrs
					lc->right = mc->left;
					delete(parent->mid);
					parent->mid = NULL; // Parent is new hole
					fix(find_parent(lc->key1,root,parent), parent);
				}
			}
		}
	}
	return;
}

// Removes keys from the leaf nodes and potentially creates holes
template <typename T>
T* BTree<T>::remove(T* item) {
	if (!lookup(item)) {
		return NULL;
	}
	TreeNode<T>* hole = NULL;
	TreeNode<T>* parent;
	TreeNode<T>* location;
	int loc_replacee; // location key # to be replaced
		location = re_lookup(item, root); // find the location to remove
	if (location->left) {	// deleting from a branch node, find immediate predecessor
		Counter::increment("Deleting from branch node",1);
		TreeNode<T>* pred; // need the predecessor
		if (location->key2 && !(*item < *location->key2) && !(*location->key2 < *item) ) { // remove location->key2
			pred = location->mid;
			loc_replacee = 2;
		} else {	// remove location->key1
			pred = location->left;
			loc_replacee = 1;
		}
		while (pred->left != NULL) { // walk to find pred;
			if (pred->right) {
				pred = pred->right;
			} else {
				pred = pred->mid;
			}
		}
		parent = find_parent(pred->key1, root, pred);
		if (loc_replacee == 2) { // remove location->key2
			if (pred->key2) {
				location->key2 = pred->key2;
				pred->key2 = NULL;
			} else { // Removing will empty the leaf, creating a hole
				location->key2 = pred->key1;
				pred->key1 = NULL;
				hole = pred;
			}
		} else {	// remove location->key1
			if (pred->key2) {
				location->key1 = pred->key2;
				pred->key2 = NULL;
			} else { // Removing will empty t=he leaf, creating a hole
				location->key1 = pred->key1;
				pred->key1 = NULL;
				hole = pred;
			}
		}
	} else { // Removing from a leaf
		parent = find_parent(item, root, location);
		if (location->key2) {
			Counter::increment("Deleting from a full leaf",1);
			if (!(*item < *location->key2) && !(*location->key2 < *item) ){
				location->key2 = NULL;
			} else {
				location->key1 = location->key2;
				location->key2 = NULL;
			}
		} else { // Removing will empty the leaf, creating a hole
			Counter::increment("Deleting from an open leaf",1);
			location->key1 = NULL;
			hole = location;
		}
	}
	// Okay, item has been deleted, now deal with the hole, if one was created
	if (hole) {
		fix(parent, hole);
	}
	return item;
}

// Walk function that actually does all the work
template <typename T>
template <typename F>
void BTree<T>::re_walk(F f, TreeNode<T> * current) {
	if (!current->left) { // base case, leaf node
		f(current->key1);
		if (current->key2) {
			f(current->key2);
		}
	} else { // recursive case, process inorder
		re_walk(f, current->left);
		f(current->key1);
		re_walk(f, current->mid);
		if (current->key2) {
			f(current->key2);
			re_walk(f, current->right);
		}
	}
}

// Walks the tree in order and applies function object F to each key
template <typename T>
template <typename F>
void BTree<T>::walk(F f) { // does an inorder walk of the tree
	re_walk(f, root);
}

#endif /* BTREE_H_ */
