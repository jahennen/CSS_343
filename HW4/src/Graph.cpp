/*
 * Graph.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#include "Graph.h"

using namespace std;

Graph::Graph() {}

Graph::~Graph() {
	unsigned int i;
	for(i = 0; i < nodes_.size(); i++) {
		delete nodes_[i];
	}
}

void Graph::insertNode(string& str) {
	addNode(str);
}

Graph::Node* Graph::addNode(string& str) {
	Node* exists = getNode(str);
	if(!exists){
		Node * newNode = new Node(str);
		nodes_.push_back(newNode);
		return newNode;
	}
	return exists;
}

void Graph::insertEdge(string& from, string& to, int w) {
	Node* f = getNode(from);
	Node* t = getNode(to);
	if (!f)
		f = addNode(from);
	if (!t)
		t = addNode(to);
	Edge * newEdge = new Edge(*f, *t, w);
	f->getEdges().push_back(newEdge);
}

Graph::Node* Graph::getNode(std::string& str) {
	unsigned int i;
	for(i = 0; i < nodes_.size(); i++) {
		if (nodes_[i]->getLabel() == str)
			return nodes_[i];
	}
	return NULL;
}

Graph::Node* Graph::findMinCost(set<Node*>& nodes) {
	set<Node*>::iterator it;
	Node* minCost = *nodes.begin();
	for(it = nodes.begin(); it != nodes.end(); it++) {
		Node* n = *it;
		if (n->getCost() < minCost->getCost())
			minCost = n;
	}
	return minCost;
}

// This function uses dijkstra's algorithm to find and store a path of Edge*
// in reverse into the vector passed to it, using the start and end nodes.
// If no path is found, the function will return -1, else it will return the
// number of nodes to get to the destination.
int Graph::dijkstra(vector<Edge*>& djkpath, Node* from, Node* to) {
	set<Node*> known;
	set<Node*> unknown(nodes_.begin(),nodes_.end());
	from->setCost(0); // starting cost = 0
	while(!known.count(to)) { // while destination is not known
		Node* next = findMinCost(unknown);
		known.insert(next);
		unknown.erase(next);
		if (next->getCost() == INT_MAX) { // all remaining nodes are inaccessable, there is no path
			return -1;
		}
		vector<Edge*>& paths = next->getEdges();
		for(vector<Edge*>::iterator it = paths.begin(); it != paths.end(); it++) {
			Edge* path = *it;
			Node& n = path->getTo();
			int cost = next->getCost()+path->getWeight();
			if (cost < n.getCost()) {
				n.setCost(cost);
				n.setprev(path);
			}
		}
	}
	Node* cur = to;
	while (cur != from) {
		djkpath.push_back(cur->getPrev());
		cur = &cur->getPrev()->getFrom();
	}
	return int(djkpath.size());
}

// This function does some preprocessing of input and output for the dijkstra function.
//
void Graph::getShortestPath(vector<string>& path, string& from, string& to) {
	Node* f = getNode(from);
	Node* t = getNode(to);
	if (!f) {
		cout << "Source " << from << " does not exist" << endl;
		return;
	}
	if (!t) {
		cout << "Destination " << to << " does not exist" << endl;
		return;
	}
	if (from == to) { // if source is also destination, cost is 0
		ostringstream out;
		out << f->getLabel() << "\t" << f->getLabel() << "\t" << 0;
		path.push_back(out.str());
		return;
	}

	vector<Edge*> djkpath; // will contain reverse path, to->from
	stack<string> reverser;
	if(dijkstra(djkpath, f, t)== -1) {
		reverser.push(string("No path exists"));
	}
	// Stringify all edges and push into stack
	unsigned int i;
	for(i = 0; i < djkpath.size(); i++) {
		ostringstream out;
		Edge * e = djkpath[i];
		out << e->getFrom().getLabel() << "\t" << e->getTo().getLabel() << "\t" << e->getWeight();
		reverser.push(out.str());
	}
	// Pop stack into path vector to be returned.
	while(!reverser.empty()) {
		path.push_back(reverser.top());
		reverser.pop();
	}
	// Reset costs and prev of each node for future calls
	for(i = 0; i < nodes_.size(); i++) {
		nodes_[i]->setCost(INT_MAX);
		nodes_[i]->setprev(NULL);
	}
}

void Graph::dumpGraph() {
	unsigned int i;
	for(i = 0; i < nodes_.size(); i++) {
		Node* n = nodes_[i];
		std::cout << n->toString() << endl;
		vector<Edge*>& e = n->getEdges();
		unsigned int k;
		for (k = 0; k < e.size(); k++) {
			cout << "+===" << e[k]->toString() << endl;;
		}
	}
}
