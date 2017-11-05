#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>

using namespace std;
class BST
{
public:
	BST();
	~BST();
	
	// Getting the key value to add a leaf to the tree.
	void AddLeaf(int key_value);

	// In-order traversal of the binary tree to print all the elements.
	void PrintInOrder();

	// Helper Function to return the root key 
	int ReturnRootKey();

	// Helper function to print all the children of a speicifed key
	void PrintChildren(int key_value);

	// Helper function to find the smallest key.
	// Used when a node having both its branches occupied is attempted to be deleted.
	// The smallest key is found and replaced in place of that key_value.
	// This is done so that the format of the BST is maintained
	int FindSmallestKey();

	// Input function to the user to Remove a node with a particular key_value.
	// Nothing gets deleted if the key_value is not present in the tree
	void RemoveNode(int key_value);

private:
	struct Node
	{
		int key;
		Node* right;
		Node* left;
	};
	Node* root;					// Root Node Pointer


	/* 
	Note: Corresponding Private functions are present to access the Node pointer to the root Node
		  and Simplify the interface to the user.
	*/


	// Create a new leaf with the key_value.
	Node* CreateLeaf(int key_value);

	// Return a pointer to node with the specific value.
	Node* ReturnNode(int key_value);

	// Add a node to the BST with the specific key_value.
	// Pass the root of the BST in which the node has to be created.
	void AddLeafPrivate(int key_value, Node* ptr);

	// In order traversal of the BST to print all the Nodes.
	// Pass the root of the BST which has to be printed.
	void PrintInOrderPrivate(Node* ptr);

	// Function to find the smallest Key in the tree. Used when trying to delete a node which has two children.
	// Pass the root of the BST.
	int FindSmallestKeyPrivate(Node* ptr);

	// Remove a specific node with the given key value.
	void RemoveNodePrivate(int key_value, Node* parent);

	// Return a Node pointer to the node with the specific key_value.
	// Pass the root of the tree which contains the Node.
	Node* ReturnNodePrivate(int key_value, Node* ptr);
	
	// Remove helper function to remove the root.
	void RemoveRootMatch();

	// Function to remove a specific node from the tree.
	void RemoveMatch(Node* parent, Node* match, bool left);
	
	// Helper function to perform the Destructor Call.
	// Does a Post-Order Traversal to delete all the nodes in the tree.
	void RemoveSubtree(Node* ptr);
};

#endif /* BST_H_ */