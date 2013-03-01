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
//	unsigned int i;
//	for(i = 0; i < nodes_.size(); i++) {
//		delete nodes_[i];
//	}
}

void Graph::insertNode(string& str) {
	addNode(str);
}

Graph::Node* Graph::addNode(string& str) {
	Node* exists = getNode(str);
	if(!exists){
		Node * newNode = new Node(str, -1);
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

bool Graph::areDirectlyLinked(string& from, string& to) {
	Node* f = getNode(from);
	Node* t = getNode(to);
	vector<Edge*>& e = f->getEdges();
	for(Edge* i : e) {
		if (i->getTo() == *t )
			return true;
	}
	return false;
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
