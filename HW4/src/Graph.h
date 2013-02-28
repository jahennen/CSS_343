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

class Graph {
public:
	class Node {
	public:
		Node(const std::string& id, const std::string& label = "", int cost):
			id_(id), label_(label), cost_(cost) {}
		const std::string& getID() {return id_;}
		const std::string& getLabel() {return label_;}
	private:
		std::string id_;
		std::string label_;
		int cost_;
	};

	class Edge {
	public:
		Edge(Node & from, Node & to, int w):
		from_(from), to_(to), w_(w){
			if(!from_ || !to_ || w_ < 0) {
				std::cout << "Illegal arguments to Edge constructor\n";
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
	Graph(std::list<std::string> & nodes, std::vector<std::string> & edges);
	virtual ~Graph();
 	void getPath(std::vector<std::string> & path, std::string & n1, std::string & n2);
private:
	std::list<Node> nodes;
	std::list<Edge> edges;
};

#endif /* GRAPH_H_ */
