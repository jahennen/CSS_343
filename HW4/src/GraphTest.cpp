/*
 * GraphTest.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: jay
 */

#include "Graph.h"


using namespace std;

int main() {
	vector<string> * nodes = new vector<string>(3);
	*nodes = {"Hello", "Goodbye", "Silly"};
	vector<pair<pair<string,string>, int > > * edges = new vector<pair<pair<string,string>, int> >(3);
	*edges = {{{"Hello", "Goodbye"}, 5}, {{"Silly", "Goodbye"}, 4}};
	Graph g(*nodes, *edges);
	g.dumpGraph();
	return 0;
}



