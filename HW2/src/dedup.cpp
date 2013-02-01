#include <iostream>
#include <cstring>
#include "BTree.h"

using namespace std;

// Function object to clean up after the BTree
class deleter {
public:
	void operator()(string * ptr) {
		delete ptr;
	}
};

int main() {
	BTree<string> set_tree;
	string line;
	while(getline(cin, line)) {
		string * word = new string(line);
		if (!set_tree.lookup(word)) {
			set_tree.insert(word);
			cout << line << "\n";
		} else {
			delete word;
		}
	}
	deleter d;
	set_tree.walk(d);

	return 0;
}
