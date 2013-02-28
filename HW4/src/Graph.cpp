/*
 * Graph.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include "Graph.h"

using namespace std;

// Graph takes two parameters. The first is a vector of names of nodes. The second is
// a vector of pairs of a pair of strings (from, to) and an int weight
Graph::Graph(vector<string>& nodes, vector<pair<pair<string, string>, int> >& edges) {
	for (string& node: nodes) {
		Node * newNode = new Node(node,0);
		if (!nodes_.insert(pair<string, Node>(node, *newNode)).second) { //if unsuccessful
			delete newNode;
		}
	}

	for(vector<pair<pair<string, string>, int> >::iterator it = edges.begin(); it != edges.end(); it++) {
		Node& from = getNode(it->first.first);
		Node& to = getNode(it->first.second);
		vector<Edge> newEdgeList;
		newEdgeList.push_back(Edge(from, to, it->second));
		//Edge * newEdgeList = new Edge(from, to, it->second);
		pair<map<Node, vector<Edge> >::iterator, bool> res =
				edges_.insert(pair<Node, vector<Edge> >(from, newEdgeList));
		if (!res.second) { //if unsuccessful
			vector<Edge>& e = res.first->second;
			e.push_back(Edge(from,to, it->second));
		}

	}

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

Graph::Node& Graph::getNode(std::string& str) {
	return nodes_.at(str);
}

void Graph::dumpGraph() {
	for(pair<string,Node> p: nodes_) {
		Node n = p.second;
		std::cout << n.toString() << endl;
		vector<Edge>& e = edges_[n];
		for (Edge i: e) {
			cout << "+===" << i.toString() << endl;;
		}
	}
}
