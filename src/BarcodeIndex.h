/*
 * Evan Johnson
 * CS300 Fall 2018
 * 5 December, 2018
 * Assignment 5
 *
 * BarcodeIndex.h
 */

#ifndef BARCODEINDEX_H_
#define BARCODEINDEX_H_

#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
#include "BinaryTree.h"
#include <fstream>
#include <time.h>
#include <array>
#include "LinkedList.h"

struct map
{
	string key;
	string val;

	bool operator<(const map& in)
	{
		return key < in.key;
	}
	bool operator>(const map& in)
	{
		return key > in.key;
	}
	bool operator==(const map& in)
	{
		return key == in.key;
	}
	bool isSame(const map& in) // needed for LinkedList search, used in hashGet()
	{
		return key == in.key && val == in.val;
	}

};

class BarcodeIndex
{
private:
	BinaryTree<map>* tree;
	map* arr;
	LinkedList<map> hashTable[1000];
	int count;

public:
	BarcodeIndex();
	bool readFile(string);
	void search(clock_t&, clock_t&, clock_t&, string&, string&);

private:
	int hashFunction(string);
	void hashAdd(map);
	map hashGet(map);

};

BarcodeIndex::BarcodeIndex() // Constructor
{
	tree = new BinaryTree<map>();
	arr = new map[1100000];
	count = 0;
}

bool BarcodeIndex::readFile(string _fileName) // reads file
{
	string code = "";
	string desc = "";
	count = 0;

	map temp; // temporary object

	ifstream inFile;

	inFile.open(_fileName);

	if (!inFile.is_open()) // if file not found, display error message, then return
	{
		cout << "File not found" << endl;
		inFile.close();
		return false;
	}

	cout << "file successfully loaded" << endl;

	while (inFile.good()) // read file and store entries in objects in array, BST, and hash
	{
		getline(inFile, code, ',');
		getline(inFile, desc);

		temp.key = code;
		temp.val = desc;

		arr[count] = temp; // add item to array
		count++;
		tree->insert(temp); // add item to BST
		hashAdd(temp); // add item to hash table

	}
	inFile.close();

	cout << "Finished loading file. " << count << " elements loaded." << endl << endl;

	return true;
}

// performs searches
void BarcodeIndex::search(clock_t& arrayTime, clock_t& treeTime, clock_t& hashTime, string& desc,
		string& UPC)
{

	map tempMap; // temporary map object to search for
	tempMap.key = UPC;
	tempMap.val = "";

	// Array Search
	arrayTime = clock(); // start array timer
	for (int i = 0; i < count; i++) // linear search
	{
		if (arr[i].key == UPC) // if item found, grab description, break
		{
			desc = arr[i].val;
			break;
		}
	}
	arrayTime = clock() - arrayTime; // stop array timer

	// BST Search
	treeTime = clock();
	tree->search(tempMap);
	treeTime = clock() - treeTime;

	// Hash Table Search
	hashTime = clock();
	hashGet(tempMap);
	hashTime = clock() - hashTime;

}

int BarcodeIndex::hashFunction(string in) // hash function, will return # from 0-999 inclusive
{
	int sum = 0;
	for (int i = 0; i < in.length(); i++)
	{
		sum += in[i];
	}
	return sum % 1000;
}

void BarcodeIndex::hashAdd(map in) // adds item to hash table where necessary
{
	hashTable[hashFunction(in.key)].insertLast(in);
}

map BarcodeIndex::hashGet(map in) // gets item from hash table
{
	map temp;
	temp = hashTable[hashFunction(in.key)].search(in);

	if (!in.isSame(temp))
		return temp;
	else
		return in;
}

#endif /* BARCODEINDEX_H_ */
