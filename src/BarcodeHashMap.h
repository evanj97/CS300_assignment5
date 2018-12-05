/*
 * BarcodeHashMap.h
 *
 *  Created on: Nov 27, 2018
 *      Author: Evan
 */

#ifndef BARCODEHASHMAP_H_
#define BARCODEHASHMAP_H_

#include <string>
#include <iostream>
#include <time.h>
#include <sstream>
#include <fstream>
#include <time.h>
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

struct map
{
	string key;
	string val;

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

class BarcodeHashMap
{
private:
	LinkedList<map>* arr;

public:

	BarcodeHashMap();

};

BarcodeHashMap::BarcodeHashMap()
{
	arr = new LinkedList<map> [1000];
}

#endif /* BARCODEHASHMAP_H_ */

