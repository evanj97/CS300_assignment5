/*
 * Evan Johnson
 * CS300 Fall 2018
 * 21 November, 2018
 * Assignment 4
 *
 * BarcodeBSTScanner.h
 */

/* NOTES:
 *
 *
 * Implemented code according to assignment instructions, but the arrayTime and treeTime
 * appear completely nonsensical.  For one, BST search time is exponentially higher than
 * array search time (which should be impossible).  Second, the times returned, allegedly
 * in milliseconds, do not seem to represent the actual time spent searching.  In cases
 * where the # of UPCs loaded is ~10,000, it claims the BST search too 1,300 milliseconds,
 * which would be 1.3 seconds, when the search was actually performed instantaneously.
 *
 * Not sure why this is, something must be wrong with the clock or something.
 *
 */

#include "BarcodeIndex.h"

using namespace std;

int main()
{
	clock_t arrayTime;
	clock_t treeTime;
	string desc;
	string UPC;

	BarcodeIndex* ind = new BarcodeIndex(); // param is # of UPCs to load

	ind->readFile("upc_corpus.txt"); // file name

	while (1)
	{
		cout << "UPC Code: " << endl; // take UPC code
		cin >> UPC;

		ind->search(arrayTime, treeTime, desc, UPC); // perform searches

		cout << desc << endl;
		cout << "BST Time: " << treeTime << endl;
		cout << "Array Time: " << arrayTime << endl << endl; // print results

	}

}

