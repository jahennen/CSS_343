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
	while (getline(in, line)) {
		stringstream strstr(line);
		istream_iterator<string> it(strstr);
		istream_iterator<string> end;
		vector<string> elems(it, end);
		nodes.push_back(elems[0]);
		edges.push_back(pair<pair<string,string>,int>({elems[0], elems[1]}, atoi(elems[2].c_str())));
	}
	Graph g(nodes, edges);
	g.dumpGraph();
	return 0;
}



