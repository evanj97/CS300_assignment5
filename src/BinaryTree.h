/*
 * Evan Johnson
 * CS300 Fall 2018
 * 21 November, 2018
 * Assignment 4
 *
 * BinaryTree.h
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>

using namespace std;

template<class T>
struct Node // Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
};

template<class T>
class BinaryTree // Binary Search Tree Class
{

private:
	Node<T>* treeRoot;
	long count;

public:

	BinaryTree()
	{
		treeRoot = NULL;
	}

	void insert(T& item); // initial root state, calls recursive insert()
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	T findMax(T&);
	bool search(T&);
	void deleteNode(T&);

private:

	void insert(Node<T>* &, T&); // recursive
	void printPreOrder(Node<T>*);
	void printInOrder(Node<T>*);
	void printPostOrder(Node<T>*);

	//bool search(T&);
	//void deleteNode(T&);
	//int height();
	T findMax(Node<T>*);
	//T findMin();
	bool search(Node<T>*, T&);
	void deleteNode(Node<T>*&, T&);

};

template<class T>
void BinaryTree<T>::deleteNode(T& item)
{
	deleteNode(treeRoot, item);
}

template<class T>
void BinaryTree<T>::deleteNode(Node<T>*& p, T& item)
{
	if (p == NULL)
		return;
	if (item < p->data)
	{
		deleteNode(p->left, item);
		count--;
	}
	if (item > p->data)
	{
		deleteNode(p->right, item);
		count--;
	}
	else // found
	{
		if (p->right != NULL && p->left != NULL) // node with 2 children
		{
			T maxNode = findMax(p->left, item);
			p->data = maxNode;
			deleteNode(p->left, max);
			count--;
		}
		else if (p->left != NULL)
		{
			p = p->left;
		}

		else if (p->right != NULL)
		{

		}
	}
}

template<class T>
bool BinaryTree<T>::search(T& item)
{
	return search(treeRoot, item);
}

template<class T>
bool BinaryTree<T>::search(Node<T>* p, T& item)
{
	if (p == NULL)
	{
		return 0;
	}
	else if (item < p->data)
	{
		return search(p->left, item);
	}
	else if (item > p->data)
	{
		return search(p->right, item);
	}
	else
	{
		item = p->data;
		return 1;
	}
}

template<class T>
void BinaryTree<T>::insert(T& item)
{
	insert(treeRoot, item);
}

template<class T>
void BinaryTree<T>::insert(Node<T>*& p, T& item)
{
	if (p == NULL)
	{
		p = new Node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if (item < p->data)
		insert(p->left, item);

	else
		insert(p->right, item);
}

template<class T>
void BinaryTree<T>::printPreOrder() // public printPreOrder()
{
	printPreOrder(treeRoot);
}

template<class T>
void BinaryTree<T>::printPreOrder(Node<T>* p) // private printPreOrder()
{
	if (p != NULL)
	{
		cout << p->data << endl;
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

template<class T>
void BinaryTree<T>::printInOrder()
{
	printInOrder(treeRoot);
}

template<class T>
void BinaryTree<T>::printInOrder(Node<T> * p)
{
	if (p != NULL)
	{
		printPreOrder(p->left);
		cout << p->data << endl;
		printPreOrder(p->right);
	}
}

template<class T>
void BinaryTree<T>::printPostOrder()
{
	printPostOrder(treeRoot);
}

template<class T>
void BinaryTree<T>::printPostOrder(Node<T> * p)
{
	if (p != NULL)
	{
		cout << p->data << endl;
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

template<class T>
T BinaryTree<T>::findMax(T& e)
{
	if (treeRoot == NULL)
		return e;
	return findMax(treeRoot);
}

template<class T>
T BinaryTree<T>::findMax(Node<T>* p)
{
	if (p->right == NULL)
		return p->data;

	else
		findMax(p->right);
}

#endif /* BINARYTREE_H_ */

