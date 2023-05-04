#include<iostream>
using namespace std;
template<class T>class Stack {
private:
	int size, top;
	T* stackPointer;
public:

	Stack() {
		size = NULL; top = NULL; stackPointer = nullptr;
	}
	Stack(int s) {
		size = s; top = 0;
		stackPointer = new T[size];
	}
	~Stack() {
		delete[] stackPointer;
	}
	void Push(T value) {
		if (isFull() == 1)
			cout << "Stack is already full :(\n";
		else
			stackPointer[top++] = value;
	}
	T Pop() {
		if (isEmpty() == 1) {
			cout << "Stack is emty no value to pop :(\n"; return 0;
		}
		else
			return stackPointer[--top];
	}
	bool isEmpty() {
		return(top == 0 ? 1 : 0);
	}
	bool isFull() {
		return (top >= size ? 1 : 0);
	}
	int currentSize() {
		return (top == 0 ? 0 : top);
	}
	T topValue() {
		return stackPointer[top - 1];
	}
	int getSize() {
		return size;
	}
	int getTopSize() {
		return top;
	}
	void displayStack() {
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
};
class InfixToPostfix {
	char* InfixExpression;
	char* PostFixExpression;
	int InfixLength;
	static int PostFixLength;
public:
	InfixToPostfix() {
		InfixExpression = nullptr;
		PostFixExpression = nullptr;
		InfixLength = 0;
	}
	void scanInfixExpression(char* Expression) {
		for (int i = 0; Expression[i] != '\0'; i++)
			InfixLength++;
		InfixExpression = Expression;
		PostFixExpression = new char[InfixLength];
	}
	char* InfixToPostfixConversion() {
		int var = -1, bro = 0;
		Stack<char> mystack(12);
		for (int i = 0; i < InfixLength; i++) {
			if ((InfixExpression[i] >= 'A' && InfixExpression[i] <= 'Z') || (InfixExpression[i] >= 'a' && InfixExpression[i] <= 'z')) {
				PostFixExpression[++var] = InfixExpression[i];
			}
			else if (InfixExpression[i] == '+' || InfixExpression[i] == '-' || InfixExpression[i] == '*' || InfixExpression[i] == '/' || InfixExpression[i] == '(' || InfixExpression[i] == ')')
			{
				if (mystack.isEmpty() == 0)
				{
					// If expression is greater in precedence
					// --------------------------------------------------------------------------------------
					if (
						(InfixExpression[i] == '*' && mystack.topValue() != '*') ||
						(InfixExpression[i] == '/' && mystack.topValue() != '*' && mystack.topValue() != '/') ||
						(InfixExpression[i] == '+' && mystack.topValue() != '*' && mystack.topValue() != '/' && mystack.topValue() != '+') ||
						(InfixExpression[i] == '-' && mystack.topValue() != '*' && mystack.topValue() != '/' && mystack.topValue() != '+' && mystack.topValue() != '-')
						) {
						mystack.Push(InfixExpression[i]);
					}
					// If expression is lower in precedence
					// --------------------------------------------------------------------------------------

					else if (InfixExpression[i] == '/' && mystack.topValue() == '*')
					{
						while (true) {
							if (mystack.topValue() == '-' || mystack.topValue() == '+' || mystack.topValue() == '(' | mystack.topValue() == ')' || mystack.getTopSize() == 0) {
								mystack.Push(InfixExpression[i]); break;
							}
							PostFixExpression[++var] = mystack.Pop();
						}
					}
					else if (InfixExpression[i] == '+' && (mystack.topValue() == '*' || mystack.topValue() == '/'))
					{
						while (true) {
							if (mystack.topValue() == '-' || mystack.topValue() == '(' || mystack.topValue() == ')' || mystack.getTopSize() == 0) {
								mystack.Push(InfixExpression[i]); break;
							}
							PostFixExpression[++var] = mystack.Pop();
						}
					}
					else if (InfixExpression[i] == '-' && (mystack.topValue() == '*' || mystack.topValue() == '/' || mystack.topValue() == '+'))
					{
						while (true) {
							if (mystack.topValue() == '(' || mystack.topValue() == ')' || mystack.getTopSize() == 0) {
								mystack.Push(InfixExpression[i]); break;
							}
							PostFixExpression[++var] = mystack.Pop();
						}
					}
					// If expression is equal in precedence
					// --------------------------------------------------------------------------------------
					else
						if (
							(InfixExpression[i] == '*' && InfixExpression[i] == mystack.topValue()) ||
							(InfixExpression[i] == '+' && InfixExpression[i] == mystack.topValue()) ||
							(InfixExpression[i] == '-' && InfixExpression[i] == mystack.topValue()) ||
							(InfixExpression[i] == '/' && InfixExpression[i] == mystack.topValue())
							)
						{
							if (InfixExpression[i] == '*') {
								while (true) {
									if (mystack.topValue() != '*') {
										mystack.Push(InfixExpression[i]); break;
									}
									PostFixExpression[++var] = mystack.Pop();
								}
							}
							else if (InfixExpression[i] == '/') {
								while (true) {
									if (mystack.topValue() != '*' && mystack.topValue() != '/') {
										mystack.Push(InfixExpression[i]); break;
									}
									PostFixExpression[++var] = mystack.Pop();
								}
							}
							else if (InfixExpression[i] == '+') {
								while (true) {
									if (mystack.topValue() != '*' && mystack.topValue() != '/' && mystack.topValue() != '+') {
										mystack.Push(InfixExpression[i]); break;
									}
									PostFixExpression[++var] = mystack.Pop();
								}
							}
							else if (InfixExpression[i] == '-') {
								while (true) {
									if (mystack.topValue() == '(' || mystack.topValue() == ')') {
										mystack.Push(InfixExpression[i]); break;
									}
									PostFixExpression[++var] = mystack.Pop();
								}
							}
						}
					// If expression is opening paranthesis
					// --------------------------------------------------------------------------------------
						else if (InfixExpression[i] == '(') {
							mystack.Push(InfixExpression[i]);
						}

					// If expression is closing paranthesis
					// --------------------------------------------------------------------------------------
						else if (InfixExpression[i] == ')') {
							while (true) {
								if (mystack.topValue() == '(') {
									mystack.Pop();
									break;
								}
								PostFixExpression[++var] = mystack.Pop();
							}
						}
				}
				else {
					mystack.Push(InfixExpression[i]);
				}
			}
			else
				if (InfixExpression[i] != '+' || InfixExpression[i] != '-' || InfixExpression[i] != '*' || InfixExpression[i] != '/' ||
					(InfixExpression[i] <= 'A' && InfixExpression[i] >= 'Z')) {
					if (InfixExpression[i] == ' ')
						continue;
					else {
						bro = 1; break;
					}
				}
		}
		if (bro == 1) {
			cout << "\n~ ~ ~  W R O N G  I N P U T  ~ ~ ~\n";
			return nullptr;
		}
		while (true) {
			if (mystack.isEmpty() == 1) {
				break;
			}
			if (mystack.isEmpty() == ')') {
				mystack.Pop();
			}
			else {
				PostFixExpression[++var] = mystack.Pop();
			}
		}
		PostFixLength = var;
		return PostFixExpression;
	}
	void displayInfixExpression() {
		cout << "\n\nInfix expression   = ";
		for (int i = 0; i <= InfixLength; i++)
			cout << InfixExpression[i];
	}
	void displayPostfixExpression() {
		cout << "\nPostFix expression = ";
		for (int i = 0; i <= PostFixLength; i++)
			cout << PostFixExpression[i];
		cout << "\n\n\n";
	}
	bool getPrecendence(char FirstOperator, char SecondOperator) {
		int FirstOperatorPrecedence, SecondOperatorPrecedence;
		if (FirstOperator == '*' || FirstOperator == '/')
			FirstOperatorPrecedence = 3;
		if (FirstOperator == '+' || FirstOperator == '-')
			FirstOperatorPrecedence = 2;
		if (FirstOperator == '(' || FirstOperator == ')')
			FirstOperatorPrecedence = 1;

		if (SecondOperator == '*' || SecondOperator == '/')
			SecondOperatorPrecedence = 3;
		if (SecondOperator == '+' || SecondOperator == '-')
			SecondOperatorPrecedence = 2;
		if (SecondOperator == '(' || SecondOperator == ')')
			SecondOperatorPrecedence = 1;

		return (FirstOperatorPrecedence >= SecondOperatorPrecedence ? 1 : 0);

	}
	int getPostFixLength() {
		return PostFixLength;
	}
	~InfixToPostfix() {
		delete[] InfixExpression;
		delete[] PostFixExpression;
	}
};
int InfixToPostfix::PostFixLength = 0;
int main() {
	int controller = 1;
	while (true) {
		char* infixarray = new char[100];
		InfixToPostfix object;
		cout << "\n\nEnter Correct Infix Expression =  "; cin >> infixarray;
		object.scanInfixExpression(infixarray);
		object.displayInfixExpression();
		object.InfixToPostfixConversion();
		object.displayPostfixExpression();
		cout << "You want to continue ?\nIf 'Yes' enter '1'\nIf 'No' enter any other number\nEnter here = ";
		cin >> controller;
		if (controller != 1)
			break;
	}
	//	SAMPLE INPUTS TO VERIFY
	// ---------------------------------
	//  (A+B*C-D/(E+F)*G)*H/(I-J)
	//  (A-B+C)*(D+E*F)
	//  (A*B)-(C+D)
	//  A*(B+C)/D-E
	//  A-(B+C)*D+E/(F-G)
	//  A/(B+C)*(D+E)
	//  A+B+C+D+E+Z
	return 0;
}