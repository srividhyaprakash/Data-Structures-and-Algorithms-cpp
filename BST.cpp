#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;


BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	RemoveSubtree(root);
}

BST::Node* BST::CreateLeaf(int key_value)
{
	Node* n = new Node;
	n->key = key_value;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

void BST::AddLeaf(int key_value)
{
	AddLeafPrivate(key_value, root);
}

void BST::AddLeafPrivate(int key_value, Node* ptr)
{
	if(root == nullptr)
	{
		root = CreateLeaf(key_value);
	}
	else if(key_value < ptr->key)
	{
		if(ptr->left != nullptr)
		{
			AddLeafPrivate(key_value, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(key_value);
		}
	}
	else if(key_value > ptr->key)
	{
		if(ptr->right != nullptr)
		{
			AddLeafPrivate(key_value, ptr->right);
		}
		else
		{
			ptr->right = CreateLeaf(key_value);
		}
	}
	else
	{
		cout << "The key " << key_value << " has already been added to the tree" << endl;
	}
}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
	cout << endl;
}

void BST::PrintInOrderPrivate(Node* ptr)
{
	if(root !=	nullptr)
	{
		if(ptr->left != nullptr)
		{
			PrintInOrderPrivate(ptr->left);
		}
		cout << ptr->key << " ";
		if(ptr->right != nullptr)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
	
}


BST::Node* BST::ReturnNode(int key_value)
{
	return ReturnNodePrivate(key_value, root);
}


BST::Node* BST::ReturnNodePrivate(int key_value, Node* ptr)
{
	if(ptr != nullptr)
	{
		if(ptr->key == key_value)
		{
			return ptr;
		}
		else 
		{
			if(key_value < ptr->key)
			{
				return ReturnNodePrivate(key_value, ptr->left);
			}
			else if(key_value > ptr->key)
			{
				return ReturnNodePrivate(key_value, ptr->right);
			}	
		}
	}
	else
	{
		return nullptr;
	}
}



int BST::ReturnRootKey()
{
	if(root != nullptr)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
}

void BST::PrintChildren(int key_value)
{
	Node* ptr = ReturnNode(key_value);
	if( ptr != nullptr)
	{
		cout << "Parent Node = " << ptr->key << endl;

		ptr->left == nullptr ? 
		cout << "Left Child == nullptr\n" :
		cout << "Left Child = " << ptr->left->key << endl;
		ptr->right == nullptr ? 
		cout << "Right Child == nullptr\n" :
		cout << "Right Child = " << ptr->right->key << endl;
		cout << endl;
	}
	else
	{
		cout << "The key " << key_value << " is not in the tree\n";
	}
}

int BST::FindSmallestKey()
{
	return FindSmallestKeyPrivate(root);
}	

int BST::FindSmallestKeyPrivate(Node* ptr)
{
	if(root == nullptr)
	{
		cout << "The tree is empty\n";
		return -1000;
	}
	else
	{
		if(ptr->left != nullptr)
		{
			return FindSmallestKeyPrivate(ptr->left);
		}
		else
		{
			return ptr->key;
		}
	}
}

void BST::RemoveNode(int key_value)
{
	RemoveNodePrivate(key_value, root);
}

void BST::RemoveNodePrivate(int key_value, Node* parent)
{
	if(root != nullptr)
	{
		if(root->key == key_value)
		{
			RemoveRootMatch();
		}
		else
		{
			if(key_value < parent->key && parent->left != nullptr)
			{
				parent->left->key == key_value ? 
				RemoveMatch(parent, parent->left, true) :
				RemoveNodePrivate(key_value, parent->left);

			}
			else if(key_value > parent->key && parent->right != nullptr)
			{
				parent->right->key == key_value ? 
				RemoveMatch(parent, parent->right, false) :
				RemoveNodePrivate(key_value, parent->right);
			}
			else
			{
				cout << "The key " << key_value << " was not found in the tree" << endl;
			} 
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

void BST::RemoveRootMatch()
{
	if(root != nullptr)
	{
		Node* delptr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;

		// case 0 - 0 children
		if(root->left == nullptr && root->right == nullptr)
		{
			root = nullptr;
			delete delptr;
		}
		// case 1 - 1 children right node present
		else if(root->left == nullptr && root->right != nullptr)
		{
			root = root->right;
			delptr->right = nullptr;
			delete delptr;
			cout << "The root node with key " << rootKey << " was deleted. " << 
					"The new root contains key " << root->key << endl;
		}
		// case 1 - 1 children left node present
		else if(root->right == nullptr && root->left != nullptr)
		{
			root = root->left;
			delptr->left = nullptr;
			delete delptr;
			cout << "The root node with key " << rootKey << " was deleted. " << 
					"The new root contains key " << root->key << endl;			
		}
		// case 2 - 2 children
		else
		{
			smallestInRightSubtree = FindSmallestKeyPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root key containing " << rootKey << 
			" was overwritten with key " << root->key << endl;
		}
	}
	else
	{
		cout << "Cannot remove root. The tree is empty" << endl;	
	}
}

void BST::RemoveMatch(Node* parent, Node* match, bool left)
{
	if(root != nullptr)
	{
		Node* delptr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		// Case 0 - 0 children
		if(match->left == nullptr && match->right == nullptr)
		{
			delptr = match;
			left == true ? parent->left = nullptr : parent->right = nullptr;
			delete delptr;
			cout << "The node containing the key " << matchKey << " was removed.\n";
		}
		// Case 1 - 1 children right node present
		else if (match->left == nullptr && match->right != nullptr)
		{
			left == true? parent->left = match->right : parent->right = match->right;
			match->right = nullptr;
			delptr = match;
			delete delptr;
			cout << "The node containing the key " << matchKey << " was removed.\n";
		}
		// Case 1 - 1 Children left node present
		else if (match->right == nullptr && match->left != nullptr)
		{
			left == true? parent->left = match->left : parent->right = match->left;
			match->left = nullptr;
			delptr = match;
			delete delptr;
			cout << "The node containing the key " << matchKey << " was removed.\n";
		}
		// Case 2 - 2 children
		else
		{
			smallestInRightSubtree = FindSmallestKeyPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else
	{
		cout << "Cannot remove match. The tree is empty.\n";
	}
}

void BST::RemoveSubtree(Node* ptr)
{
	if(ptr != nullptr)
	{
		if(ptr->left != nullptr)
		{
			RemoveSubtree(ptr->left);
		}
		if(ptr->right != nullptr)
		{
			RemoveSubtree(ptr->right);
		}
		cout << "Deleting the node containing the key " << ptr->key << endl;
		delete ptr;
	}

}