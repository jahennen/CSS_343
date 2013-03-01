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
	string ttt = "test";
	g.insertNode(ttt);
	ttt = "teeessst";
	g.insertNode(ttt);
	g.dumpGraph();
	cout << endl;
	cout << "From:";
	string f;
	cin >> f;
	cout << "To:";
	string t;
	cin >> t;
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



