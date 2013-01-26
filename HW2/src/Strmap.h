/*
 * Strmap.h
 *
 *  Created on: Jan 26, 2013
 *      Author: jay
 */

#ifndef STRMAP_H_
#define STRMAP_H_

#include <cstring>

// This class maps one string to an int 'count'
class Strmap {
public:
	Strmap(const char* s);
	~Strmap();
	const char* get_word();
	int get_count();
	void set_count(int n);
	bool operator<(const Strmap & rhs) const;
private:
	char * word;
	int count;
};

#endif /* STRMAP_H_ */
