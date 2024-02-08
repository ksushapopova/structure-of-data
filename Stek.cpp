#include <iostream>
#include "Stack.h"

AStack::AStack(int _size) 
{
	size = _size;
	stack = new char[_size];
	top = -1;
}

AStack::~AStack()
{
	delete[]stack;
	stack = nullptr;
}

void AStack::push(char elem)
{
	if (top < size - 1)
	{
		top++;
		stack[top] = elem;
	}
	else std::cout << "Стек заполнен" << std::endl;
}

void AStack::pop()
{
	if (top > -1)
	{
		top--;
	}
}

char AStack::peek()
{
	return stack[top];
}

bool AStack::isEmpty()
{
	return top == -1;
}

