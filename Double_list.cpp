#include "Double_list.h"

void Init(Node*& head, Node*& tail)
{
	head = nullptr;
	tail = nullptr;
}

bool IsEmpty(Node* head)
{
	return head == nullptr;
}

void Print(Node* head)
{
	
	while (head->next != nullptr)
	{

		std::cout << head->elem.name << " "<< head->elem.surname << " " << head->elem.patronymic << " " << head->elem.home.street << " " << head->elem.home.house << " " << head->elem.home.flat <<" "<< head->elem.number<<" "<< head->elem.balance<<"\n";
		head = head->next;
	}
	std::cout << head->elem.name << " " << head->elem.surname << " " << head->elem.patronymic << " " << head->elem.home.street << " " << head->elem.home.house << " " << head->elem.home.flat << " " << head->elem.number << " " << head->elem.balance << "\n";
}


//Node* searchValue(Node* head, int value)
//{
//	Node* current = head;
//	Node* result = nullptr;
//	while (current->next != nullptr && result == nullptr)
//	{
//		if (current->value == value)
//		{
//			result = current;
//		}  
//		current = current->next;
//	} 
//	return result;
//}

void DeleteCurrent(Node*& current, Node*& head)
{
	if (head == NULL || current->next == NULL) return;
	if (current == head)
	{
		head = current->next;
	}
	else
	{
		current->prev->next = current->next;
	}
	if (current->next == NULL)
	{
		head->prev = current->prev;
	}
	else
	{
		current->next->prev = current->prev;
	}
	delete current;
}


void DeleteBeforeCurrent(Node*& node, Node*& head)
{
	if (node != head)
	{
		Node* ptr = node->prev;
		node->prev = ptr->prev;
		if (ptr != head)
		{
			ptr->prev->next = node;
		}
		else { head = node; }
		ptr->next = 0;
		ptr->prev = 0;
		delete ptr;
		ptr = 0;
	}
	
}

void DeleteAfterCurrent(Node*& node, Node*& tail)
{
	if (node != tail)
	{
		Node* ptr = node->next;
		node->next = ptr->next;
		if(ptr!=tail)
		{
			ptr->next->prev = node;
		}
		else
		{
			tail = node;
		}
		ptr->next = nullptr;
		ptr->prev = nullptr;
		delete ptr;
		ptr = nullptr;
	}	
}

void AddAfter(Node* node, Node*& tail, Cellular elem)
{
	Node* ptr = new Node;
	ptr->next = node->next;
	if (node != tail)
	{
		node->next->prev = ptr;
	}
	else { tail = ptr; }
	node->next = ptr;
	ptr->prev = node;
}
void AddBefore(Node* node, Node*& head, Cellular elem)
{
	Node* ptr = new Node;
	ptr->prev = node->prev;
	if (node != head)
	{
		node->prev->next = ptr;
	}
	else { head = ptr; }
	node->prev = ptr;
	ptr->next = node;
}

void AddToHead(Node*& head, Node*& tail, Cellular elem)
{
	Node* newHead = new Node;
	newHead->elem = elem; newHead->next = head;
	if (head != nullptr)
		head->prev = newHead;
	head = newHead;
	if (head->next == nullptr)
		tail = head;

}

void AddToTail(Node*& head, Node*& tail, Cellular elem)
{
	Node* current = head;
	while (current->next != nullptr)
		current = current->next;
	current->next = new Node;
	current->next->elem = elem;
	current->next->prev = current;
	tail = current->next;
}

void delete_search_value(Node*& head, Node*& tail, int balance)
{
	Node* current = tail;
	Node* update;

	while (current->prev != nullptr)
	{
		if (current->next == nullptr && current->elem.balance > balance)
		{
			if (tail->prev != nullptr)
			{
				tail = tail->prev;
				delete tail->next;
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
				tail = nullptr;
			}
			current = tail;
			//std::cout << 1;
		}
		else if (current->elem.balance > balance)
		{
			//std::cout << current->elem.balance;
			update = current;
			current = current->next;
			current->prev = update->prev;
			current = current->prev;
			current->next = update->next;
			delete update;
		}
		else
			current = current->prev;
	}

}