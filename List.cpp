#include <iostream>
#include "List.h"


void insertSorted(Node*& head, int value) {
	Node* new_node = new Node; // create a new node with the value
	new_node->value = value;
	new_node->next = nullptr;

	if (head == nullptr) { // if the list is empty
		head = new_node; // make the new node the head of the list
	}
	else if (value < head->value) { // if the value is smaller than the head value
		new_node->next = head; // make the new node point to the head
		head = new_node; // make the new node the head of the list
	}
	else { // if the value is larger than or equal to the head value
		Node* p = head; // create a pointer to traverse the list
		while (p->next != nullptr && value >= p->next->value) { // while the next node is not null and the value is larger than or equal to the next node value
			p = p->next; // move the pointer to the next node
		}
		// now p points to the node after which the new node should be inserted
		new_node->next = p->next; // make the new node point to the next node of p
		p->next = new_node; // make p point to the new node
	}
}
void Init(Node* &head, int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = rand() % 10;
		//AddToHead(head, k);
		insertSorted(head, k);
	}
}
void AddToHead(Node* &head, int value)
{
	Node* new_head = new Node;
	new_head->value = value;
	new_head->next = head;
	head = new_head;
}

void AddAfter(Node*& el, int value)
{
	Node* new_el = new Node;
	new_el->value = value;
	new_el->next = el->next;
	el->next = new_el;
}

void Print(Node* head) 
{
	Node* p = head;
	while (p) 
	{
		std::cout << p->value << " ";
		p = p->next;
	} 
	std::cout << '\n';
}
Node* searchValue(Node* head, int value) 
{
	while (head->value != value) 
	{
		head = head->next;
	}
	if (head->next == nullptr) 
	{
		std::cout << "node is not found\n";
	}
	return head;
}

void DeleteFromHead(Node*& head)
{
	Node* p = head;
	head = head->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}
void DeleteAfterNode(Node*& el) 
{
	Node* p = el->next;
	el->next = p->next;
	p->next = nullptr;
	delete p;
	p = nullptr;
}

void Clear(Node*& head)
{
	while (head != nullptr)
	{
		DeleteFromHead(head);
	}
}


