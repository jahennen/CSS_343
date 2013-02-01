/*
 * PQueue.h
 *
 *  Created on: Feb 1, 2013
 *      Author: jay
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
	T* top();
	void push(T &item);
	T* pop();
private:
	vector<T> data;
	int end;
};


#include "PQueue_impl.h"
#endif /* PQUEUE_H_ */
