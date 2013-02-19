/*
 * shiftdoodle.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#include <iostream>;
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	char* mess = new char[5];

	string cmd = "01100001";
	unsigned short i = '\0';
	int k;
	for (k = 0; k < cmd.length(); k++) {
		if (cmd[k]=='0') {
			i = i<<1;
		} else {
			i++;
			i = i<<1;
		}
	}
	i = i>>1;
	printf("%c\n", i);
	printf("%d\n", i);
	cout << mess << endl;
	return 0;
}



