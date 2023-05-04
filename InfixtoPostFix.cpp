#include "InfixtoPostFix.h"
#include "Stack.h"


InfixToPostfix::InfixToPostfix() {
		InfixExpression = nullptr;
		PostFixExpression = nullptr;
		InfixLength = 0;
}
void InfixToPostfix::scanInfixExpression(char* Expression) {
		for (int i = 0; Expression[i] != '\0'; i++)
			InfixLength++;
		InfixExpression = Expression;
		PostFixExpression = new char[InfixLength];
}
char* InfixToPostfix::InfixToPostfixConversion() {
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
	void InfixToPostfix::displayInfixExpression() {
		cout << "\n\nInfix expression   = ";
		for (int i = 0; i <= InfixLength; i++)
			cout << InfixExpression[i];
	}
	void InfixToPostfix::displayPostfixExpression() {
		cout << "\nPostFix expression = ";
		for (int i = 0; i <= PostFixLength; i++)
			cout << PostFixExpression[i];
		cout << "\n\n\n";
	}
	bool InfixToPostfix::getPrecendence(char FirstOperator, char SecondOperator) {
		int FirstOperatorPrecedence=NULL, SecondOperatorPrecedence=NULL;
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
	int InfixToPostfix::getPostFixLength() {
		return PostFixLength;
	}
	InfixToPostfix::~InfixToPostfix() {
		delete[] InfixExpression;
		delete[] PostFixExpression;
	}
