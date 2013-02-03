/*
 * driver.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: jay
 */

#include <iostream>
#include <cassert>
#include "BTree.h"

#define SIZE 10000

int main() {
	BTree<int> tree;
	int a[SIZE];
	int i;
	// fill array with random integers
	for(i = 0; i < SIZE; i++) {
		a[i] = rand()%(SIZE*4);
	}

	// insert all items
	for( i = 0; i < SIZE; i++) {
		cout << "Inserting: " << a[i];
		if (tree.insert(a[i])) {
			cout << " Successful" << endl;
		} else {
			cout << " Failure (item already exists)" << endl;
		}
	}

	cout << "SUCCESSFUL INSERT\n";

	// delete all items in reverse order
	for( i = SIZE-1; i >= 0; i--) {
		cout << "Deleting: " << a[i];
		if (tree.remove(a[i])) {
			cout << " Successful" << endl;
		} else {
			cout << " Failure (no such item)" << endl;
		}
	}

	if (tree.is_empty()) {
		cout << "SUCCESSFUL DELETE" << endl;
	} else {
		cout << "INCOMPLETE DELETION!!!!" << endl;
	}
	cout << endl;

	// Review the dump to ensure all paths were followed. There should be 15 deletion
	// statements and 7 insertion statements

	return 0;
}

