/*
 * Evan Johnson
 * LinkedList.h
 * CS300 Fall 2018
 * Assignment 5
 * Due: 12 Nov, 2018
 *
 * Version: 1.1
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	node* next;
};

template<class T>
class LinkedList
{
private:
	LinkedList(const LinkedList&) = delete; //copy constructor

protected:
	int count;
	node<T> *head, *last;

public:
	LinkedList(); // Default constructor
	bool isEmpty(); // if List has no nodes, return true
	int length(); // return length (number of nodes)
	T front(); // return data of first node(?)
	T back(); // return data of last node(?)
	void insertFirst(T&); // insert new node at beginning
	void insertLast(T&); // insert new node at the end
	bool deleteNode(T&); // hello
	void destroylist(); // deletes all nodes in list

	LinkedList<T>& operator=(LinkedList<T>&); // set another list = to this
	template<class U>
	friend ostream& operator<<(ostream& os, LinkedList<U>& list); // set another list = to this
	~LinkedList(); // destructor
};

template<class T>
LinkedList<T>::LinkedList() // Default constructor
{
	head = NULL;
	last = NULL;
	count = 0;
}

template<class T>
bool LinkedList<T>::isEmpty() // if List has no nodes, return true
{
	return head == NULL;
}

template<class T>
int LinkedList<T>::length() // return length (number of nodes)
{
	return count;
}

template<class T>
T LinkedList<T>::front() // return data of first node(?)
{
	return head->data;
}

template<class T>
T LinkedList<T>::back() // return data of last node(?)
{
	return last->data;
}

template<class T>
void LinkedList<T>::insertFirst(T& item) // insert new node at beginning
{
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if (last == NULL)
		last = temp;
}

template<class T>
void LinkedList<T>::insertLast(T& item) // insert new node at the end
{
	node<T> *newnode = new node<T>;
	newnode->data = item;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = last = newnode;
	}
	else
	{
		last->next = newnode;
		last = newnode;
	}
	count++;
}

template<class T>
bool LinkedList<T>::deleteNode(T& item) // hello
{

	if (head->data == item) // if searched item is first item
	{
		node<T>* p = head; // temp pointer to hold item
		head = head->next; // make head pointer point at second element
		delete p; // delete item, dereference pointer for searched item
		count--; // decrement total number of items in list
		if (head == NULL) // if head now == null, (deleted item was only item in list)
			last = NULL; // set last = null as well
	}
	else // if searched item is NOT first item
	{
		node<T>* p = head; // temp pointer to hold head
		node<T>* q = p->next; // temp pointer to move down list
		while (q != NULL && q->data != item) // while next item exists and data not yet found
		{
			p = q; // shift both pointers forward 1 item (p is 1 item behind q)
			q = q->next;
		}
		if (q != NULL) // if searched item is found (iterator finishes search with an item not null
		{
			p->next = q->next;
			count--; // decrement total number of items in list
			if (last == q) // if deleted item was last item
				last = p; // reassign last to [new] last item in list
			delete q; // delete searched item
			return true;
		}
		return false;

	}
}

template<class T>
void LinkedList<T>::destroylist() // deletes all nodes in list
{
	node<T> *p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list) // set another list = to this
{
	if (this != &list)
	{
		copylist(list);
	}
	return *this;
}

template<class T>
ostream& operator<<(ostream& os, LinkedList<T>& list) // print all data in the list
{
	node<T> *p = list.head;
	while (p != NULL)
	{
		os << p->data << " " << endl;
		p = p->next;
	}
}

template<class T>
LinkedList<T>::~LinkedList() // destructor
{
	destroylist();
}

#endif /* LINKEDLIST_H_ */
