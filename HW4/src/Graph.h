/*
 * Graph.h
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <sstream>

class Graph {
public:
	Graph(std::vector<std::string> & nodes, std::vector<std::pair<std::pair<std::string, std::string>, int> > & edges);
	void dumpGraph();
	virtual ~Graph();
	void getPath(std::vector<std::string> & path, std::string & n1, std::string & n2);
private:
	class Node {
		public:
			Node(const std::string& label = "", int cost = 0):
				label_(label), cost_(cost) {}
			const std::string getLabel() {return label_;}
			const std::string toString() {
				std::ostringstream out;
				out << this << " " << label_ << " " << cost_;
				return out.str();
			}
			bool operator<(const Node& rhs) const {return label_.compare(rhs.label_) < 0;}
		private:
			std::string label_;
			int cost_;
		};

		class Edge {
		public:
			Edge(Node & from, Node & to, int w):
			from_(from), to_(to), w_(w){};
			Edge(std::pair<Node&, Node&>& nodes, int w):
				from_(nodes.first), to_(nodes.second), w_(w){};
			const Node& getFrom() {return from_;}
			const Node& getTo() {return to_;}
			const int getLabel() {return w_;}
			const std::string toString() {
				std::ostringstream out;
				out << this << " " << from_.toString() << " " << to_.toString() << " " << w_;
				return out.str();
			}
			bool operator<(const Edge& rhs) const {
				if (from_.getLabel() < rhs.from_.getLabel())
					return true;
				if (to_.getLabel() < rhs.to_.getLabel())
					return true;
				if (w_ < rhs.w_)
					return true;
				return false;
			}
		private:
			Node& from_;
			Node& to_;
			int w_;
		};

	Graph::Node& getNode(std::string& str);
	std::map<std::string, Node> nodes_;
	std::map<Node, std::vector<Edge>> edges_;
};

#endif /* GRAPH_H_ */
