#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class BTree;

template <typename T>
class TreeNode
{
	friend class BTree<T>;

public:
	TreeNode();
	T* getK1();
	T* getK2();

private:
	T* key1;
	T* key2;
	TreeNode* left; //pointer to left child node of node
	TreeNode* mid; //pointer to right child node of node
	TreeNode* right; //pointer to right child node of node
};

template <typename T>
TreeNode<T>::TreeNode()
{
	key1 = NULL;
	key2 = NULL;
	left = NULL;
	mid  = NULL;
	right = NULL;
}

template <typename T>
T* TreeNode<T>::getK1() {
	return key1;
}

template <typename T>
T* TreeNode<T>::getK2() {
	return key2;
}

#endif
