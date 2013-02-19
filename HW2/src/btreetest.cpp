/*
 * driver.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: jay
 */

#include <iostream>
#include "BTree.h"
#include "counter/counter.h"

#define SIZE 10000

int main() {
	BTree<int> tree;
	int* a = new int[SIZE];
	int i;
	// fill array with random integers
	for(i = 0; i < SIZE; i++) {
		a[i] = rand()%(SIZE*4);
	}

	int* p = a;
	// insert all items
	for( i = 0; i < SIZE; i++) {
		//cout << "Inserting: " << *(p+i) << "\n";
		tree.insert(p+i);
	}

	cout << "SUCCESSFUL INSERT\n";

	// delete all items in reverse order
	for( i = SIZE-1; i >= 0; i--) {
		//cout << "Deleting: " << *(p+i) << "\n";
		tree.remove(p+i);
	}

	if (tree.is_empty()) {
		cout << "SUCCESSFUL DELETE" << endl;
	} else {
		cout << "INCOMPLETE DELETION!!!!" << endl;
	}
	cout << endl;

	Counter::dump(cout);

	// Review the dump to ensure all paths were followed. There should be 15 deletion
	// statements and 7 insertion statements

	delete[] a;
	return 0;
}

