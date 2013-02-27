/*
 * Graph.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include "Graph.h"

using namespace std;

Graph::Graph(vector<string>& nodes, vector<pair<pair<string, string>, int> >& edges) {
	for (string& node: nodes) {
		Node * newNode = new Node(node, 0);
		if((nodes_.count(newNode))) {
			nodes_.insert(newNode);
		} else {
			delete newNode;
		}
	}

	for(vector<pair<pair<string, string>, int> >::iterator it = edges.begin(); it != edges.end(); it++) {
		Edge * newEdge = new Edge(it->first, it->second);
		if((edges_.count(newEdge))) {
			edges_.insert(newEdge);
		} else {
			delete newEdge;
		}
	}

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::dumpGraph() {
	for(Node* node: nodes_) {
		std::cout << node->toString() << endl;
		for(Edge* edge: edges_) {
			if (!(edge->getFrom() < *node) && !(*node < edge->getFrom())) {
				cout << "+---" << edge->toString();
			}
		}
	}
}
