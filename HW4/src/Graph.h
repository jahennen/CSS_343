/*
 * Graph.h
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

class Graph {
public:
	class Node {
	public:
		Node(const string& id, const string& label = "", int cost):
			id_(id), label_(label), cost_(cost) {}
		const string& getID() {return id_;}
		const string& getLabel() {return label_;}
	private:
		string id_;
		string label_;
		int cost_;
	};

	class Edge {
	public:
		Edge(Node & from, Node & to, int w):
		from_(from), to_(to), w_(w){
			if(!from_ || !to_ || w_ < 0) {
				cout << "Illegal arguments to Edge constructor" << endl;
				exit (EXIT_FAILURE);
			}
		};
		const Node& from() {return from_;}
		const Node& to() {return to_;}
		const int label() {return w_;}
	private:
		Node * from_;
		Node * to_;
		int w_;
	};
	Graph(list<string> & nodes, vector<string> & edges);
	virtual ~Graph();
	void getPath(vector<string> & path, string & n1, string & n2);
private:
	list<Node> nodes;
	list<Edge> edges;
};

#endif /* GRAPH_H_ */
