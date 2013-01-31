/*
 * Ordermap.h
 *
 *  Created on: Jan 28, 2013
 *      Author: jay
 */

#ifndef ORDERMAP_H_
#define ORDERMAP_H_

using namespace std;

class Ordermap {
public:
	Ordermap(int pos, string s);
	~Ordermap();
	const char* get_word();
	int get_pos();
	bool operator<(const Ordermap & rhs) const;
private:
	int position;
	char * word;
};
#endif /* ORDERMAP_H_ */
