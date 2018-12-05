/*
 * HashTable.h
 *
 *  Created on: Dec 5, 2018
 *      Author: Evan
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <string>
#include <array>
#include "LinkedList.h"

/*
 *
 * DEPRECIATED
 *
 *
 *
 *
 */

using namespace std;

class HashTable
{
private:
	LinkedList<string>* arr; // array of lists to store values
	int size; // size of arr[]

	int HashFunction(string);

public:
	HashTable(int); // constructor

};

HashTable::HashTable(int in)
{
	size = in;
	arr = new LinkedList<string> [];
}

int HashTable::HashFunction(string in) // hash function, will return # from 0-size
{
	int sum = 0;
	for (int i = 0; i < in.length(); i++)
	{
		sum += in[i];
	}
	return sum % size;
}

#endif /* HASHTABLE_H_ */
