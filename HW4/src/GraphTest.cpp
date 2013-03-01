/*
 * GraphTest.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: jay
 */

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstdlib>

using namespace std;

int main() {
	ifstream in;
	in.open("../tests/airports.txt");
	string line;
	vector<string> nodes;
	vector<pair<pair<string, string>, int > > edges;
	Graph g;
	while (getline(in, line)) {
		stringstream strstr(line);
		istream_iterator<string> it(strstr);
		istream_iterator<string> end;
		vector<string> elem(it, end);
		g.insertEdge(elem[0], elem[1], atoi(elem[2].c_str()));
	}
	g.dumpGraph();
	cout << endl;
	cout << "From:";
	string f;
	cin >> f;
	cout << "To:";
	string t;
	cin >> t;
	cout << g.areDirectlyLinked(f, t) << endl;
	return 0;
}



