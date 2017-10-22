#include <iostream>
#include <cstdlib>
#include <string>

#include "hashing.h"

using namespace std;

hashing::hashing()
{
	for(int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = nullptr;
	}
}

hashing::~hashing()
{

}

int hashing::Hash(string key)
{
	int index;
	int hashh;

	for(int i = 0; i < key.length(); i++)
	{
		hashh = (hashh + (int)key[i])* 7;
	}

	index = hashh % tableSize;

	return index;
}

void hashing::AddItem(string name_in, string drink_in)
{
	int hashIndex = Hash(name_in);
	if(HashTable[hashIndex]->name == "empty")
	{
		HashTable[hashIndex]->name = name_in;
		HashTable[hashIndex]->drink	= drink_in;
		HashTable[hashIndex]->next = nullptr;
	}
	else
	{
		item* HashTablePtr = HashTable[hashIndex];
		item* itemptr = new item;
		itemptr->name = name_in;
		itemptr->drink = drink_in;
		itemptr->next = nullptr;
		while(HashTablePtr->next != nullptr)
		{

			HashTablePtr = HashTablePtr->next;
		}

		if(HashTablePtr->next == nullptr)
		{
			HashTablePtr->next = itemptr;
		}
	}

}

int hashing::numberInBucket(int index)
{
	int count = 0;

	item* itemptr = HashTable[index];

	if(itemptr->name == "empty")			//he typed it as HashTable[index]->name == "empty"
	{
		return count;
	}
	else
	{
		count++;
		while(itemptr->next	!= nullptr)
		{
			count++;
			itemptr	= itemptr->next;
		}
	}

	return count;
}

void hashing::printTable()
{
	//item* itemptr;
	int number;
	for(int i = 0; i < tableSize; i++)
	{
		number = numberInBucket(i);
		cout << "----------------------------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "----------------------------------------\n";
	}
}

void hashing::printItemsInIndex(int index)
{
	item* itemptr = HashTable[index];
	if(HashTable[index]->name == "empty")
	{
		cout << "index = " << index << " is empty" << endl;
	}
	else
	{
		cout << "index " << index << " contains the following items\n" << endl;
		while(itemptr != nullptr)
		{
			cout << "name = " << itemptr->name << endl;
			cout << "drink = " << itemptr->drink << endl << endl;


			itemptr = itemptr->next;
		}
	}

}

void hashing::FindDrink(string name_d)
{
	int index = Hash(name_d);
	bool foundName = false;
	string drink_d;
	item* itemptr = HashTable[index];
	while(itemptr != nullptr)
	{
		if(itemptr->name == name_d)
		{
			foundName = true;
			drink_d = itemptr->drink;

		}
		itemptr = itemptr->next;
	}
	if(foundName)
	{
		cout << "Favourite drink = " << drink_d << endl;
	}
	else
	{
		cout << name_d << "'s info was not found in the Hash table\n";
	}
}
