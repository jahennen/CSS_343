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

int Graph::dijkstra(vector<Edge*>& djkpath, Node* from, Node* to) {
	set<Node*> known;
	set<Node*> unknown(nodes_.begin(),nodes_.end());
	from->setCost(0); // starting cost = 0
	while(!known.count(to)) { // while destination is not known
		Node* next = findMinCost(unknown);
		known.insert(next);
		unknown.erase(next);
		if (next->getCost() == INT_MAX) { // all remaining nodes are inaccessable
			break;
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

void Graph::getShortestPath(vector<string>& path, string& from, string& to) {
	Node* f = getNode(from);
	Node* t = getNode(to);
	if (!f||!t || f == t)
		return;
	vector<Edge*> djkpath; //will contain reverse path, to->from
	dijkstra(djkpath, f, t);
	stack<string> reverser;
	unsigned int i;
	for(i = 0; i < djkpath.size(); i++) {
		ostringstream out;
		Edge * e = djkpath[i];
		out << e->getFrom().getLabel() << "\t" << e->getTo().getLabel() << "\t" << e->getWeight();
		reverser.push(out.str());
	}
	while(!reverser.empty()) {
		path.push_back(reverser.top());
		reverser.pop();
	}
	// Reset costs and prev for future calls
	for(i = 0; i < nodes_.size(); i++) {
		nodes_[i]->setCost(INT_MAX);
		nodes_[i]->setprev(NULL);
	}
}

bool Graph::areDirectlyLinked(string& from, string& to) {
	Node* f = getNode(from);
	Node* t = getNode(to);
	if (!f || !t)
		return false;
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
