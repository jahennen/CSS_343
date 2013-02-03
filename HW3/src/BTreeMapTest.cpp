#include <iostream>
#include "BTreeMap.h"

int main() {
	BTreeMap<string, int> m;
	string line;
	while (getline(cin, line)) {
		if(m.containsKey(line)) {
			int * count = m.get(line);
			*count += 1;
		} else {
			int i = 1;
			m.add(line, i);
		}
	}

	m.print();
	return 0;
}
