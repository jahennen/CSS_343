/*
 * Graph.h
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

class Graph {
public:
	Graph();
	void insertNode(std::string& str);
	void insertEdge(std::string& str, std::string& to, int w);
	bool areDirectlyLinked(std::string& from, std::string& to);
	void dumpGraph();
	virtual ~Graph();
	void getPath(std::vector<std::string> & path, std::string & n1, std::string & n2);
private:
	class Edge;
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
			std::vector<Edge*>& getEdges() {return edges_;}
			bool operator<(const Node& rhs) const {return label_.compare(rhs.label_) < 0;}
			bool operator==(const Node& rhs) const {return label_==rhs.label_;}
		private:
			std::vector<Edge*> edges_;
			std::string label_;
			int cost_;
		};

		class Edge {
		public:
			Edge(Node & from, Node & to, int w):
			from_(from), to_(to), w_(w){};
			Edge(const Edge& other):from_(other.from_), to_(other.to_), w_(other.w_){}
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
				else if (from_.getLabel() == rhs.from_.getLabel() &&
						to_.getLabel() < rhs.to_.getLabel())
					return true;
				else if (from_.getLabel() == rhs.from_.getLabel() &&
						to_.getLabel() == rhs.to_.getLabel() &&
						w_ < rhs.w_)
					return true;
				else
					return false;
			}
			bool operator==(const Edge& rhs) const {
				return (from_.getLabel() == rhs.from_.getLabel() &&
						to_.getLabel() == rhs.to_.getLabel() &&
						w_ == rhs.w_);
			}
		private:
			Node& from_;
			Node& to_;
			int w_;
		};

	Graph::Node* getNode(std::string& str);
	Graph::Node* addNode(std::string& str);
	std::vector<Node*> nodes_;
};

#endif /* GRAPH_H_ */
