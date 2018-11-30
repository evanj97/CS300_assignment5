/*
 * Evan Johnson
 * CS300 Fall 2018
 * 21 November, 2018
 * Assignment 4
 *
 * BarcodeIndex.h
 *
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
	map& operator=(const map& in)
	{
		map temp;
		temp.key = in.key;
		temp.val = in.val;
		return temp;
	}

};

class BarcodeIndex
{
private:
	BinaryTree<map>* tree;
	map* arr;
	int count;
	int DataSetLimit;

public:
	BarcodeIndex(int);
	bool readFile(string);
	void search(clock_t&, clock_t&, string&, string&);
};

BarcodeIndex::BarcodeIndex(int in) // Constructor
{
	tree = new BinaryTree<map>();
	arr = new map[1100000];
	count = 0;
	DataSetLimit = in;
}

bool BarcodeIndex::readFile(string _fileName) // reads file
{
	string code = "";
	string desc = "";
	count = 0;

	map temp;
	ifstream inFile;

	inFile.open(_fileName);

	if (!inFile.is_open()) // if file not found, display error message, then return
	{
		cout << "File not found" << endl;
		inFile.close();
		return false;
	}

	cout << "file successfully loaded" << endl;

	while (inFile.good() && count < DataSetLimit) // read file and store entries in objects pointed to by array
	{
		getline(inFile, code, ',');
		getline(inFile, desc);

		temp.key = code;
		temp.val = desc;

		arr[count] = temp; // add item to array
		count++;
		tree->insert(temp); // add item to BST

		if (count % 1000 == 0) // debug
			cout << count << endl;
	}
	inFile.close();

	cout << "Finished loading file. " << count << " elements loaded." << endl;

	return true;
}

// performs searches
void BarcodeIndex::search(clock_t& arrayTime, clock_t& treeTime, string& description, string& UPC)
{

	arrayTime = clock(); // start array timer

	for (int i = 0; i < count; i++) // linear search
	{
		if (arr[i].key == UPC) // if item found, grab description, break
		{
			description = arr[i].val;
			break;
		}
	}
	arrayTime = clock() - arrayTime; // stop array timer

	map tempMap; // temporary map object to search for
	tempMap.key = UPC;
	tempMap.val = "";

	treeTime = clock(); // start BST timer

	tree->search(tempMap); // perform search

	treeTime = clock() - treeTime; // stop BST timer

//BST

}

#endif /* BARCODEINDEX_H_ */
