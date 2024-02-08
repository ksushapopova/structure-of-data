#pragma once

struct Node
{
	Node* next;
	int value;
} ;
void AddToHead(Node* &head, int value);
void AddAfter(Node*& el, int value);
void Print(Node* head);
Node* searchValue(Node* head, int value);
//void Swap(Node* &head, int n);
void Init(Node* &head,  int n);
void DeleteFromHead(Node*& head);
void DeleteAfterNode(Node*& el);
void Clear(Node*& head);