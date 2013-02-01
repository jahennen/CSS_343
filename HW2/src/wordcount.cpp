/*
 * wordcount.cpp
 *
 *  Created on: Jan 26, 2013
 *      Author: jay
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Strmap.h"
#include "BTree.h"

#define MAX_LEN 128
#define OPT_LOC 0	//option index in input string
#define STR_LOC 2	//string begin index in input string

using namespace std;

class Strmap_printer {
public:
	void operator()(Strmap * s) {
		printf("%7d ", s->get_count());
		cout << s->get_word() << "\n";
	}
};

class Strmap_deleter {
public:
	void operator()(Strmap * s) {
		delete s;
	}
};

int main() {
	BTree<Strmap> tree;

	string in_buffer;
	while(getline(cin, in_buffer)) {
		char opt = in_buffer[OPT_LOC];
		string word = &in_buffer[STR_LOC];

		if (in_buffer.length() < 3 || in_buffer[1] != ' ' ||
				(opt != 'a'&& opt != 'd')) {
			cerr << "Input was not formatted properly!\n";
			exit (EXIT_FAILURE);
		}
		if (opt == 'a') {
			Strmap * add = new Strmap(word);
			Strmap * res = tree.lookup(add);
			if (res && !(*res < *add) && !(*add < *res)) { //Item already exists in tree, +1 count
				res->set_count(res->get_count()+1);
				delete add;
			} else { // Item does not exist, add it
				tree.insert(add);
			}
		}
		if (opt == 'd') {
			Strmap * rem = new Strmap(word);
			Strmap * res = tree.lookup(rem);
			if (res && !(*res < *rem) && !(*rem < *res)) { //Item already exists in tree, -1 count
				res->set_count(res->get_count()-1);
				if (res->get_count() == 0) { // if count goes to zero, remove the item for good
					tree.remove(rem);
				}
			} else { // Item does not exist, exit failure
				delete rem;
				cerr << "Trying to decrement a word without an entry\n";
				exit (EXIT_FAILURE);
			}
		}
	}
	Strmap_printer p;
	tree.walk(p);
	Strmap_deleter d; // cleanup your mess
	tree.walk(d);
	return 0;
}
