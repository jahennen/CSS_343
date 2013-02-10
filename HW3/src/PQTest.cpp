/*
 * PQTest.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: jay
 *
 *      This is a real simple test for the PQueue. Inset SIZE number of random
 *      integers, pop them all and test that they are sorted.
 */

#include <iostream>
#include <cstdlib>
#include "PQueue.h"

#define SIZE 5000

using namespace std;

int main() {
	PQueue<int> q;
	int* a = new int[SIZE];
		unsigned int i;
		// fill array with random integers
		for(i = 0; i < SIZE; i++) {
			a[i] = rand()%(SIZE*4);
		}

		int* p = a;
		// insert all items
		for( i = 0; i < SIZE; i++) {
			//cout << "Inserting: " << *(p+i) << "\n";
			q.push(*(p+i));
		}

		// add all elements to result array
		vector<int> result;
		while(!q.isEmpty()) {
			int * temp = q.pop();
			result.push_back(*temp);
			delete temp;
		}
//		unsigned int k;
//		for (k = 0; k < result.size(); k++) {
//			cout << " " << result[k];
//		}
//		cout << endl;

		// If result is not sorted, something went wrong
		// uncomment above code to view all elements inline
		unsigned int l;
		bool fail = false;
		for (l = 1; l < result.size() ; l++) {
			if (result[l-1] > result[l]) {
				cout << "LIST NOT SORTED, FAILURE" << endl;
				fail = true;
			}
		}
		if (!fail) {
			cout << "Test was successful, integers were sorted" << endl;
		}
		delete[] a;
	return 0;
}
