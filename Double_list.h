#pragma once
#include <iostream>
#include "CellularSubscribes.h"

struct Node
{
	Cellular elem;
	Node* next = nullptr;
	Node* prev = nullptr;
};

void Init(Node*& head, Node*& tail);
bool IsEmpty(Node* head);
void Print(Node* head);
//Node* searchValue(Node* head, int value);
void DeleteCurrent(Node*& current, Node*& head);
void DeleteBeforeCurrent(Node*& node, Node*& head);
void DeleteAfterCurrent(Node*& node, Node*& tail);
void AddAfter(Node* node, Node*& tail, Cellular elem);
void AddBefore(Node* node, Node*& head, Cellular elem);
void AddToHead(Node*& head, Node*& tail, Cellular elem);
void AddToTail(Node*& head, Node*& tail, Cellular elem);
void delete_search_value(Node*& head, Node*& tail, int balance);
