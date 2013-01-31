#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include "BTree.h"

#define OPT_LOC 0	//option index in input string
#define STR_LOC 2	//string begin index in input string

using namespace std;

int main() {
	BTree<string> set_tree;

	string line;
	while(getline(cin, line)) {
		if (!set_tree.lookup(&line)) {
			set_tree.insert(&line);
			cout << line << "\n";
		}
	}
	return 0;
}
