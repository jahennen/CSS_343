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

template <typename T>
PQueue<T>::PQueue() {
	data(10);
	end = 1;
}

template <typename T>
PQueue<T>::~PQueue() {}

template <typename T>
bool PQueue<T>::isEmpty() {
	return end == 1;
}
template <typename T>
int PQueue<T>::size() {
	return end-1;
}

template <typename T>
T* PQueue<T>::top() {
	return &data[1];
}

template <typename T>
void PQueue<T>::push(T &item) {
	if (isEmpty()) {
		cout << data[1] << "\n";
		//data[1] = item;
		end++;
	}
//	data[end] = item;
//	if (data[end] < data[end/2]) {
//		int loc = end;
//		while (data[loc] < data[loc/2]) { // bubble up!
//			T temp = data[loc];
//			data[loc] = data[loc/2];
//			data[loc/2] = temp;
//			loc /= 2;
//		}
//	}
	return ;
}

template <typename T>
T* PQueue<T>::pop() {
	if (isEmpty()) {
	}
	T* item = data[1];
}

#endif /* PQUEUE_IMPL_H_ */
