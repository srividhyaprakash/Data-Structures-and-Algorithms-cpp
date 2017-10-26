#include <iostream>
#include <cmath>
#include <string>

#include "hashing.h"

using namespace std;


int main()
{

	//creating an object of the class..
	hashing Hashy;
	string findName;

	// adding data to the hash table.
	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");
	
	// printing the hash table.
	Hashy.printTable();

	// print all the items in the particular index.
	Hashy.printItemsInIndex(7);

	/*
	while(findName != "exit")
	{
		cout << "Search for ";
		cin >> findName;
		if(findName != "exit")
		{
			Hashy.FindDrink(findName);
		}
	}
	*/
	return 0;
}
