/*
 * Ordermap.h
 *
 *  Created on: Jan 28, 2013
 *      Author: jay
 */

#ifndef ORDERMAP_H_
#define ORDERMAP_H_

class Ordermap {
public:
	Ordermap(int pos, const char * s);
	~Ordermap();
	const char* get_word();
	int get_pos();
	bool operator<(const Ordermap & rhs) const;
private:
	int position;
	char * word;
};
#endif /* ORDERMAP_H_ */
