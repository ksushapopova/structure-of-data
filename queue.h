#pragma once
#include <iostream> 

class Queue {
	struct Node
	{
		char value = ' ';
		Node* next = nullptr;
	};
	Node* head;
	Node* tail;
public:
	Queue();
	void enqueue(char value);
	void dequeue();
	bool is_empty();
	int peek();
	void print();
	void clear();
	int size();
};