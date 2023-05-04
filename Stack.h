#pragma once
#include<iostream>
using namespace std;

template<class Type>
class Stack {
private:
	int size, top;
	Type* stackPointer;
public:

	Stack();
	Stack(int s);
	~Stack();
	void Push(Type value);
	Type Pop();
	bool isEmpty();
	bool isFull();
	int currentSize();
	Type topValue();
	int getSize();
	int getTopSize();
	void displayStack();
};