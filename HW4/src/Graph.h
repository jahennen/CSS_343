/*
 * Graph.h
 *
 *  Created on: Feb 19, 2013
 *      Author: jay
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <climits>

class Graph {
public:
	Graph();
	void insertNode(std::string& str);
	void insertEdge(std::string& str, std::string& to, int w);
	void dumpGraph();
	virtual ~Graph();
	void getShortestPath(std::vector<std::string> & path, std::string & n1, std::string & n2);
private:
	class Edge;
	class Node {
	public:
		Node(const std::string& label = "", int cost = INT_MAX):
			prev_(NULL),label_(label), cost_(cost) {}
		~Node() {
			unsigned int i;
			for(i = 0; i < edges_.size(); i++) {
				delete edges_[i];
			}
		}
		const std::string getLabel() {return label_;}
		const int getCost() {return cost_;}
		Edge* getPrev() {return prev_;}
		void setCost(int cost) {cost_ = cost;}
		void setprev(Edge* prev) {prev_ = prev;}
		const std::string toString() {
			std::ostringstream out;
			out << this << " " << label_ << " " << cost_;
			return out.str();
		}
		std::vector<Edge*>& getEdges() {return edges_;}
		bool operator<(const Node& rhs) const {return label_.compare(rhs.label_) < 0;}
		bool operator==(const Node& rhs) const {return label_==rhs.label_;}
	private:
		Edge* prev_;
		std::vector<Edge*> edges_;
		std::string label_;
		int cost_;
	};

	class Edge {
	public:
		Edge(Node & from, Node & to, int w):
			from_(from), to_(to), w_(w){};
		Edge(const Edge& other):from_(other.from_), to_(other.to_), w_(other.w_){}
		Node& getFrom() {return from_;}
		Node& getTo() {return to_;}
		const int getWeight() {return w_;}
		const std::string toString() {
			std::ostringstream out;
			out << this << " " << from_.toString() << " " << to_.toString() << " " << w_;
			return out.str();
		}
	private:
		Node& from_;
		Node& to_;
		int w_;
		};
	int dijkstra(std::vector<Edge*>& djkpath, Node* from, Node* to);
	Graph::Node* findMinCost(std::set<Node*>& nodes);
	Graph::Node* getNode(std::string& str);
	Graph::Node* addNode(std::string& str);

	std::vector<Node*> nodes_;
};

#endif /* GRAPH_H_ */
