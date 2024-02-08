#include <iostream>
#include "List.h"

using namespace std;

void Swap(Node*& head)
{
	int temp = head->value;
	Node* iter = head;
	while (iter->next->next != nullptr)
	{
		iter = iter->next;
	}
	head->value = iter->next->value;
	iter->next->value = temp;
}




int main()
{
	int n;
	Node* head=nullptr;
	cout << "Enter list size" << endl;
	cin >> n;
	Init(head, n);
	Print(head);
	AddToHead(head, 3);
	AddAfter(head->next, 5);
	Print(head);
	DeleteFromHead(head);
	DeleteAfterNode(head->next);
	Print(head);
	Swap(head);
	Print(head);
	Clear(head);
	Print(head);
} 
