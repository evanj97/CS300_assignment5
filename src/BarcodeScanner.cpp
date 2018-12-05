/*
 * Evan Johnson
 * CS300 Fall 2018
 * 5 December, 2018
 * Assignment 5
 *
 * BarcodeScanner.cpp
 */

#include "BarcodeIndex.h"

using namespace std;

int main()
{
	clock_t arrayTime;
	clock_t treeTime;
	clock_t hashTime;
	string desc;
	string UPC;

	BarcodeIndex* ind = new BarcodeIndex(); // param is # of UPCs to load

	ind->readFile("upc_corpus.txt"); // file name

	while (1)
	{
		cout << "UPC Code: " << endl; // take UPC code
		cin >> UPC;

		ind->search(arrayTime, treeTime, hashTime, desc, UPC); // perform searches

		cout << desc;
		cout << "BST Time: 	 " << treeTime << endl;
		cout << "Array Time: " << arrayTime << endl; // print results
		cout << "Hash Time:  " << hashTime << endl << endl << endl;

	}

}

