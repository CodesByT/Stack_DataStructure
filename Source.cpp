#include "InfixtoPostFix.h"
#include "Stack.h"

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