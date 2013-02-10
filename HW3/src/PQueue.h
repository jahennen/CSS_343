/*
 * PQueue.h
 *
 *  Created on: Feb 1, 2013
 *      Author: jay
 *
 *      PQueue template using a vector, implements basic priority queue
 *      methods sugh as push, pop, top, size, and isEmpty
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <vector>

using namespace std;

template <typename T>
class PQueue {
public:
	PQueue();
	~PQueue();
	bool isEmpty();
	int size();
	T * top();
	void push(T &item);
	T * pop();
private:
	vector<T> data;
	int end;
	void swap(int i1, int i2);
};


#include "PQueue_impl.h"
#endif /* PQUEUE_H_ */
