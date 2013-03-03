/*
 * NetworkCost.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include "Graph.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	string line;
	vector<string> nodes;
	Graph g;
	// Read file one line at a time
	while (getline(cin, line)) {
		stringstream strstr(line);
		vector<string> elem(3);
		int i;
		// Tokenize on '\t' delimiter
		for(i = 0; i < 3; i++) {
			(getline(strstr, elem[i], '\t'));
		}
		// Insert the edge
		g.insertEdge(elem[0], elem[1], atoi(elem[2].c_str()));
	}
	string f = string(argv[1]);
	string t = string(argv[2]);
	vector<string> path;
	// Get shortest path
	g.getShortestPath(path, f, t);
	unsigned int i;
	// Print shortest path to stdout
	for(i = 0; i < path.size(); i++) {
		cout << path[i] << endl;
	}
	return 0;
}







