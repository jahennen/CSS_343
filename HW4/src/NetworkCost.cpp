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

void buildGraph(Graph& g);

int main(int argc, char* argv[]) {
	vector<string> nodes;
	if (argc < 3 || argc == 4) {
		cout << "Too few arguments" << endl;
		return 1;
	}
	string basename = "";
	bool isEmitting = 0;
	if (argc == 5 && string(argv[3]) == "-o") {
		basename = string(argv[4]);
		isEmitting = 1;
	}
	Graph g(basename, isEmitting);
	buildGraph(g);
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

void buildGraph(Graph& g) {
	string line;
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
}







