#include <iostream>
#include "BTreeMap.h"

using namespace std;

int main() {
	BTreeMap<string, int> m;
	string line;
	while (getline(cin, line)) {
		if(m.containsKey(line)) {
			*(m.get(line)) += 1;
		} else {
			m.add(line, 1);
		}
	}

	//m.print();
	return 0;
}
