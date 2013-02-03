#include <iostream>
#include <cstdlib>
#include "PQueue.h"

#define SIZE 50

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

		vector<int> result;
		while(!q.isEmpty()) {
			result.push_back(q.pop());
		}
		unsigned int k;
		for (k = 0; k < result.size(); k++) {
			cout << " " << result[k];
		}
		cout << endl;
		delete[] a;
	return 0;
}
