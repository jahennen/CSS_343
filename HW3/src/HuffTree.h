/*
 * HuffTree.h
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include "HuffNode.h"
#include "BTreeMap.h"

using namespace std;

class HuffTree {
public:
	HuffTree(HuffNode * huffroot);
	~HuffTree();
	void addEncodings(BTreeMap<char, string> * map);
private:
	void re_addEncodings(BTreeMap<char, string> *map, HuffNode * current, string & encoding);
	HuffNode * root;
};

#endif /* HUFFTREE_H_ */
