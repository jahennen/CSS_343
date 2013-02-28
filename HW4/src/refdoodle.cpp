/*
 * refdoodle.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include <iostream>

using namespace std;

void funct(int & a, int b) {
	int * c = new int(70);
	a = b;
	a = c;
}

int main() {
	int a;
	int b = 5;
	funct(a, b);
	cout << a << endl;
}


