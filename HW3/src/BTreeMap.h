/*
 * BTreeMap.h
 *
 *  Created on: Feb 3, 2013
 *      Author: jay
 */

#ifndef BTREEMAP_H_
#define BTREEMAP_H_

#include <iostream>
#include "BTree.h"

template <typename K, typename V>
class KVMap {
public:
	KVMap(K k, V v) {
		key = k;
		value = v;
	}
	~KVMap() {}
	K key;
	V value;
	bool operator<(const KVMap & rhs) const {
		return key < rhs.key;
	}
};

template <typename K, typename V>
class printer {
public:
	void operator()(KVMap<K,V> * m) {
		std::cout << m->key << "  " << m->value << "\n";
	}
};


template <typename K, typename V>
class BTreeMap {
public:
	BTreeMap();
	~BTreeMap();
	bool isEmpty();
	bool add(K k, V v);
	bool containsKey(K k);
	V* get(K key);
	bool remove(K key);
	void print();

private:
	BTree<KVMap<K,V> > tree;
};

template <typename K, typename V>
BTreeMap<K,V>::BTreeMap() { }

template <typename K, typename V>
BTreeMap<K,V>::~BTreeMap() {}

template <typename K, typename V>
bool BTreeMap<K,V>::isEmpty() {
	return tree.isEmpty();
}

template <typename K, typename V>
bool BTreeMap<K,V>::add(K k, V v) {
	KVMap<K,V> entry(k, v);
	return tree.insert(entry);
}

template <typename K, typename V>
bool BTreeMap<K,V>::containsKey(K k) {
	KVMap<K,V> entry(k,0);
	return tree.lookup(entry);
}

template <typename K, typename V>
V* BTreeMap<K,V>::get(K k) {
	KVMap<K,V> entry(k,0);
	return &tree.lookup(entry)->value;
}

template <typename K, typename V>
bool BTreeMap<K,V>::remove(K k) {
	V temp;
	KVMap<K,V> entry(k,temp);
	return tree.remove(entry);
}

template <typename K, typename V>
void BTreeMap<K,V>::print() {
	printer<K,V> p;
	tree.walk(p);
}

#endif /* BTREEMAP_H_ */
