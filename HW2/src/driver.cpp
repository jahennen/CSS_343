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
//	a[0] = 10;
//	a[1] = 5;
//	a[2] = 1;
//	a[3] = 9;
//	a[4] = 6;
//	a[5] = 7;
//	a[6] = 8;


	int* p = a;
	// insert all items
	for( i = 0; i < SIZE; i++) {
		cout << "Inserting: " << *(p+i) << "\n";
		tree.insert(p+i);
	}

	cout << "SUCCESSFUL INSERT\n";

	// delete all items in reverse order
	for( i = SIZE-1; i >= 0; i--) {
		cout << "Deleting: " << *(p+i) << "\n";
			tree.remove(p+i);
	}

	cout << "SUCCESSFUL DELETE\n";

	Counter::dump(cout);
	delete[] a;
	return 0;
}

