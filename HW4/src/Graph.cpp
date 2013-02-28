/*
 * Graph.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include "Graph.h"

using namespace std;

Graph::Graph(vector<string>& nodes, vector<pair<pair<string, string>, int> >& edges) {
	cout << endl;
	set<Node*> nos = {new Node("time",0), new Node("fuck", 0)};
	Node * cock = new Node("suck", 0);
	Node * balls= new Node("fuck", 0);
	Node test("time", 0);
	cout << (cock < balls);
	cout << endl;
	cout << *nos.find(&test);
	cout << endl << endl;

	for (string& node: nodes) {
		Node * newNode = new Node(node, 0);
		if(!(nodes_.count(*newNode))) {
			nodes_.insert(*newNode);
		} else {
			delete newNode;
		}
	}

	for(vector<pair<pair<string, string>, int> >::iterator it = edges.begin(); it != edges.end(); it++) {
		Node& from = getNode(it->first.first);
		Node& to = getNode(it->first.second);
		Edge * newEdge = new Edge(from, to, it->second);
		if(!(edges_.count(*newEdge))) {
			edges_.insert(*newEdge);
		} else {
			delete newEdge;
		}
	}

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

Graph::Node& Graph::getNode(std::string& str) {
	Node temp(str);
	set<Node>::iterator it = nodes_.find(temp);
	const Node& t(const_cast<Node>(*it));
	return t;
}

void Graph::dumpGraph() {
	for(Node node: nodes_) {
		std::cout << node.toString() << endl;
		for(Edge edge: edges_) {
			if (!(edge.getFrom() < *node) && !(*node < edge.getFrom())) {
				cout << "+---" << edge.toString();
			}
		}
	}
}
