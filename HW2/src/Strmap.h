/*
 * Strmap.h
 *
 *  Created on: Jan 26, 2013
 *      Author: Jay Hennen
 *
 *      This simple class maps a single string to an int counter
 */

#ifndef STRMAP_H_
#define STRMAP_H_

#include <iostream>

using namespace std;

// This class maps one string to an int 'count'
class Strmap {
public:
	Strmap(string s);
	~Strmap();
	string get_word();
	int get_count();
	void set_count(int n);
	bool operator<(const Strmap & rhs) const;
private:
	string word;
	int count;
};

#endif /* STRMAP_H_ */
