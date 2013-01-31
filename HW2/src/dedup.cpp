
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Strmap.h"
#include "BTree.h"

using namespace std;

class printer {
public:
	void operator()(string * s) {
		cout << *s << "\n";
	}
};

int main() {
	BTree<string> set;

	string line;
	while(getline(cin, line)) {
		string * word = new string(line);
		if(!set.lookup(word)) {
			set.insert(word);
			cout << line << "\n";
		}
	}
	cout << "\nInput done! Printing set\n\n";
	printer p;
	set.walk(p);
	//delete &set;
	return 0;
}
