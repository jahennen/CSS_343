/*
 * HuffTree.h
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include "PQueue.h"
#include "BitStream.h"
#include <vector>

class HuffTree {
public:
	HuffTree(std::vector<int> & types);
	~HuffTree();
	void addEncodings(std::vector<std::string> & map);
	void decode(BitStream & bits, std::ostream & out);
private:
	class HuffNode {
	public:
		HuffNode();
		HuffNode(int sum, HuffNode * l, HuffNode * r);
		HuffNode(int count, char character);
		~HuffNode();
		unsigned char getChar();
		int getCount();
		HuffNode * getChild(bool bit);
		bool operator<(const HuffNode & rhs) const;
		unsigned char c;
		int count;
		HuffNode * left;
		HuffNode * right;
	};
	void clean_up(HuffNode * current);
	void re_addEncodings(std::vector<std::string> & map, HuffNode * current, std::string & encoding);
	HuffNode * root;
};

#endif /* HUFFTREE_H_ */
