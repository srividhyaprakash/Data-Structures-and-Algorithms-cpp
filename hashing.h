#ifndef HASH_H_
#define HASH_H_

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hashing
{
public:
	/**
     * Defaut constructor.
     * initialise all the item's with "empty" name and "empty" drink.
     */
	hashing();
	/**
     * Destructor.
     * Deletes the array upon invoking.
     */
	~hashing();

    /**
     * Return an index for the key passed.
     * @param key the key for which an index needs to be created.
     * @return the index.
     */
	int Hash(string key);

	/**
     * Add an item with the person's name and his favorite drink to the hash table.
     * @param name_in the person's name.
     * @param drink_in the person's favorite drink.
     */
	void AddItem(string	name_in, string drink_in);
	
	/**
     * Returns the number of item's present in the particular index (a result of chaining).
     * @param index the index for which the number of items needs to be known.
     * @return the number of item's in the bucket.
     */
	int numberInBucket(int index);

	/**
     * Print out the first items of all the buckets in the hash table, "empty" if no item in bucket.
     */
	void printTable();

	/**
     * Print out all the items in the particular bucket in the hash table, "empty" if no item in bucket.
     * @param index the index/bucket for which all the items needs to be printed.
     */
	void printItemsInIndex(int index);

	/**
     * Finding the person's favortie drink.
     * @param name_d the person's name for whom his drink needs to be found.
     */
	void FindDrink(string name_d);

private:

	static const int tableSize = 40;		// # of buckets in the array.

	struct item
	{
		string name;
		string drink;
		item* next;
	};										// the item declaration, essentially a LinkedList used for chaining

	item* HashTable[tableSize];				// core of the hash table, an array of items
};

#endif
