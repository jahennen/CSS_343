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

class HuffTree {
public:
	HuffTree(HuffNode * huffroot);
	~HuffTree();
	void addEncodings(std::vector<std::string> & map);
	HuffNode & returnRoot();
private:
	void cleanUp(HuffNode * current);
	void re_addEncodings(std::vector<std::string> & map, HuffNode * current, std::string & encoding);
	HuffNode * root;
};

#endif /* HUFFTREE_H_ */
