#include <iostream>
#include "BinarySearchTree.h"

void Init(SearchTreeNode*& root)
{
	root = nullptr;
}

bool IsEmpty(SearchTreeNode* root)
{
	return (root == nullptr);
}

void Insert(SearchTreeNode*& root, int value)
{
	if (root == nullptr)
	{
		root = new SearchTreeNode;
		root->elem = value;
		root->left = nullptr;
		root->right = nullptr;
	}
	else 
	{
		if (root->elem > value)
		{
			Insert(root->right, value);
		}
		if (root->elem < value)
		{
			Insert(root->left, value);
		}
	}
}


void Remove(SearchTreeNode*& ptr, const int& elem) {
	if (ptr != nullptr) {
		if (ptr->elem == elem) {
			if (ptr->left == nullptr && ptr->right == nullptr) {
				delete ptr;    ptr = nullptr;
			}
			else
			{
				if (ptr->left == nullptr || ptr->right == nullptr)
				{
					SearchTreeNode* tmp = ptr;
					if (ptr->left != nullptr)      ptr = ptr->left;
					else      ptr = ptr->right;
					delete tmp;
				}
				else {
					SearchTreeNode* current = ptr->right;     while (current->left != nullptr)
						current = current->left;     ptr->elem = current->elem;
					Remove(ptr->right, current->elem);
				}
			}
		}
		else {
			if (ptr->elem > elem) {
				Remove(ptr->right, elem);
			}
			else {
				Remove(ptr->left, elem);
			}
		}
	}
}



void DeleteNode(SearchTreeNode*& root)
{
	if (root->left == 0 && root->right == 0)
	{
		delete root;
		root = nullptr;
	}
	else if (root->left == 0 || root->right == 0)
	{
		SearchTreeNode* tmp = root;
		if (root->left != 0)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
			delete tmp;
		}
	}
	else root->elem = FindSuccessor(root->right);
}

int FindSuccessor(SearchTreeNode*& root)
{
	SearchTreeNode* cur = root;
	while (cur->left != nullptr)
	{
		cur = cur->left;
	}
	int tmp = cur->elem;
	DeleteNode(cur);
	return tmp;
}

SearchTreeNode* Search(SearchTreeNode*& root, int value)
{
	int i; 
	if (root != nullptr)
	{
		if (root->elem == value)
			i = 1;  
		else if (root->elem < value)
			return Search(root->left, value);  
		else
			return Search(root->right, value);
	}
	else {
		i = 0;
	}
	if (i == 1) std::cout << "Yes" << std::endl; else std::cout << "No" << std::endl;
}


void PrintTree(SearchTreeNode* root, int level)
{
	if (root == nullptr)
	{
		return;
	}


	PrintTree(root->left, level + 1);
	for (int i = 0; i < level; i++)
	{
		std::cout << "    ";
	}

	std::cout << root->elem << "\n";

	PrintTree(root->right, level + 1);
}