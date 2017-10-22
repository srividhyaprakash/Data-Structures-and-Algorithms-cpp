#ifndef HASH_H_
#define HASH_H_

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hashing
{
public:
	hashing();
	~hashing();

	int Hash(string key);
	void AddItem(string	name_in, string drink_in);
	int numberInBucket(int index);
	void printTable();
	void printItemsInIndex(int index);
	void FindDrink(string name_d);

private:
	static const int tableSize = 40;

	struct item
	{
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];
};

#endif
