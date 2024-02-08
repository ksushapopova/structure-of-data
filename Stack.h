#pragma once
#include <string>
using namespace std;

class AStack
{
	
	char* stack;
	int size;
	void clear();
public:
	int top;
	AStack(int _size);
	~AStack();
	void push(char elem);
	void pop();
	char peek();
	bool isEmpty();
	bool Staples(int n, string s);
};
