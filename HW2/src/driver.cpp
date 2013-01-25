/*
 * driver.cpp
 *
 *  Created on: Jan 24, 2013
 *      Author: jay
 */

#include <iostream>
#include "BTree.h"

#define SIZE 7

int main() {
	BTree<int> tree;
	int* a = new int[SIZE];
	int i;
//	for(i = 0; i < SIZE; i++) {
//		a[i] = rand()%(SIZE*4);
//	}
	a[0] = 10;
	a[1] = 5;
	a[2] = 1;
	a[3] = 9;
	a[4] = 6;
	a[5] = 7;
	a[6] = 8;


	int* p = a;
	for( i = 0; i < SIZE; i++) {
		tree.insert(p+i);
	}
	cout << *tree.lookup(p) << "\n";
}

