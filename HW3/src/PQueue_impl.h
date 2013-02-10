/*
 * PQueue_impl.h
 *
 *  Created on: Feb 1, 2013
 *      Author: jay
 */

#ifndef PQUEUE_IMPL_H_
#define PQUEUE_IMPL_H_
#include "PQueue.h"
#include <iostream>
#include <limits>

template <typename T>
PQueue<T>::PQueue() {
	data.push_back(T()); // append default item into 0th pace
	end = 1; // start work from position 1
}

template <typename T>
PQueue<T>::~PQueue() {}

template <typename T>
bool PQueue<T>::isEmpty() {
	return end == 1;
}

// Returns the # of elements in the priority queue
template <typename T>
int PQueue<T>::size() {
	return end-1;
}

// Returns the smallest element
template <typename T>
T * PQueue<T>::top() {
	return data[1];
}

// Push an item into the queue
template <typename T>
void PQueue<T>::push(T &item) {
	if (isEmpty()) {
		data.push_back(item);
		end++;
		return;
	}
	data.push_back(item); // add item to end of queue
	int loc = end;
	while (data[loc] < data[loc/2]) { // bubble up!
		T temp = data[loc];
		data[loc] = data[loc/2];
		data[loc/2] = temp;
		loc /= 2;
	}
	end++;
}

// Helper method to swap the items at 2 locations
template <typename T>
void PQueue<T>::swap(int i1, int i2) {
	T temp = data[i1];
	data[i1] = data[i2];
	data[i2] = temp;
}

// Pops the smallest element and returns a pointer to it.
template <typename T>
T * PQueue<T>::pop() {
	if (isEmpty()) {
		cerr << "Queue empty" << endl;
		return NULL;
	}
	T* item = new T(data[1]);
	data[1] = data[end-1]; // swap last element with root
	end--;
	data.pop_back(); // remove last element
	int loc = 1;
	// bubble root down until heap is restored
	while ((2*loc < end) && ((data[2*loc] < data[loc]) || data[2*loc+1] < data[loc])) {
		if (data[2*loc] < data[loc] && data[2*loc+1] < data[loc]) { // both child smaller than parent
			if(data[2*loc] < data[2*loc+1]) { // left child < right child
				swap(loc, 2*loc);
				loc *= 2;
			} else {
				swap(loc, 2*loc+1);
				loc = 2*loc+1;
			}
		} else {
			if (data[2*loc] < data[loc]) {
				swap(loc, 2*loc);
				loc *= 2;
			} else if (data[2*loc+1] < data[loc]) {
				swap(loc, 2*loc+1);
				loc = 2*loc+1;
			}
		}
	}
	return item;
}

#endif /* PQUEUE_IMPL_H_ */
