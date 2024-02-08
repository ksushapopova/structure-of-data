#pragma once


struct SearchTreeNode
{
	int elem;
	SearchTreeNode* left;
	SearchTreeNode* right;

};

void Init(SearchTreeNode*& root);
bool IsEmpty(SearchTreeNode* root);
void Insert(SearchTreeNode*& root, int value);
//void Copy(SearchTreeNode* root, SearchTreeNode* new_root);
int FindSuccessor(SearchTreeNode*& root);
void Remove(SearchTreeNode*& root, const int& value);
void DeleteNode(SearchTreeNode*& root);
SearchTreeNode* Search(SearchTreeNode*& root, int value);
void PrintTree(SearchTreeNode* root, int level);