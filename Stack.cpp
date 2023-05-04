#include "Stack.h"


template<class Type>
Stack<Type>::Stack() {
	size = NULL;
	top = NULL;
	stackPointer = nullptr;
}
template<class Type>
Stack<Type>::Stack(int s) {
	size = s; top = 0;
	stackPointer = new Type[size];
}
template<class Type>
Stack<Type>::~Stack() {
	delete[] stackPointer;
}
template<class Type>
void Stack<Type>::Push(Type value) {
	if (isFull() == 1)
		cout << "Stack is already full :(\n";
	else
		stackPointer[top++] = value;
}
template<class Type>
Type Stack<Type>::Pop() {
	if (isEmpty() == 1) {
		cout << "Stack is emty no value to pop :(\n"; return 0;
	}
	else
		return stackPointer[--top];
}
template<class Type>
bool Stack<Type>::isEmpty() {
	return(top == 0 ? 1 : 0);
}
template<class Type>
bool Stack<Type>::isFull() {
	return (top >= size ? 1 : 0);
}
template<class Type>
int Stack<Type>::currentSize() {
	return (top == 0 ? 0 : top);
}
template<class Type>
Type Stack<Type>::topValue() {
	return stackPointer[top - 1];
}
template<class Type>
int Stack<Type>::getSize() {
	return size;
}
template<class Type>
int Stack<Type>::getTopSize() {
	return top;
}
template<class Type>
void Stack<Type>::displayStack() {
	if (isEmpty() == 0) {
		cout << "\t\nStack: \n\n";
		for (int i = top - 1; i >= 0; i--)
			cout << "\t#\t" << stackPointer[i] << "\t#\n";
		cout << "\t# # # # # # # # #\t\n\n";
	}
	else {
		cout << "\n\t# # # # # # # # #\t\n";
		cout << "\t  STACK IS EMPTY\t\n";
		cout << "\t# # # # # # # # #\t\n\n";
	}
}
