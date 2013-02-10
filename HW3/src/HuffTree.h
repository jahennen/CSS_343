/*
 * HuffTree.h
 *
 *  Created on: Feb 4, 2013
 *      Author: jay
 */

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include "HuffNode.h"
#include <vector>

using namespace std;

class HuffTree {
public:
	HuffTree(HuffNode * huffroot);
	~HuffTree();
	void addEncodings(vector<string> * map);
	HuffNode * returnRoot();
private:
	void cleanUp(HuffNode * current);
	void re_addEncodings(vector<string> *map, HuffNode * current, string & encoding);
	HuffNode * root;
};

#endif /* HUFFTREE_H_ */
