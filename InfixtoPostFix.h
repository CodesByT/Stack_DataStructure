#pragma once

class InfixToPostfix {
	char* InfixExpression;
	char* PostFixExpression;
	int InfixLength;
	int PostFixLength=0;
public:
	InfixToPostfix();
	void scanInfixExpression(char* Expression);
	char* InfixToPostfixConversion();
	void displayInfixExpression();
	void displayPostfixExpression();
	bool getPrecendence(char FirstOperator, char SecondOperator);
	int getPostFixLength();
	~InfixToPostfix();
};
