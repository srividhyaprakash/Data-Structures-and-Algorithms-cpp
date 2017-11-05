#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "BST.h"

using namespace std;

int main()
{

	int TreeKeys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,73,87,80};
	int input = 0;
	BST myTree;

	cout << "Printing the tree in order\nBefore adding the numbers\n";
	myTree.PrintInOrder();

	for(int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}

	cout << "Printing the tree in order\nAfter adding the numbers\n";

	myTree.PrintInOrder();

	myTree.PrintChildren(myTree.ReturnRootKey());

	for(int i = 0; i < 16; i++)
	{
		myTree.PrintChildren(TreeKeys[i]);
	}

	cout << "The smallest key in the tree is " << myTree.FindSmallestKey() << endl;

	cout << "Enter a key value to delete. Enter -1 to stop the process.\n";

	
	while(input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		if(input != -1)
		{
			cout << endl;
			myTree.RemoveNode(input);
			myTree.PrintInOrder();
			cout << endl;
		}
	}
	cout << "Done!" << endl;
	return 0;
}