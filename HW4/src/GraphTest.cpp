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
	in.open("../tests/cities.txt");
	string line;
	vector<string> nodes;
	Graph g;
	while (getline(in, line)) {
		stringstream strstr(line);
		vector<string> elem(3);
		int i;
		for(i = 0; i < 3; i++) {
			(getline(strstr, elem[i], '\t'));
		}
		g.insertEdge(elem[0], elem[1], atoi(elem[2].c_str()));
	}
	g.dumpGraph();
	cout << endl;
	cout << "From:";
	string f;
	getline(cin, f, '\n');
	cout << "To:";
	string t;
	getline(cin, t, '\n');
	vector<string> path;
	g.getShortestPath(path, f, t);
	cout << endl;
	unsigned int i;
	for(i = 0; i < path.size(); i++) {
		cout << path[i] << endl;
	}

	g.dumpGraph();

	return 0;
}



