//*****************************************************************************************************
//
//		File:					rpn.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					4/18/24
//
//
//		This is the application file that evaluates RPN expressions that contain integers 
//		and integer operations.  
//	
//		Other files required: 
//			1.	stack.h
//			2.	results.txt
//			3.	expressions.txt
//			
//*****************************************************************************************************

#include <fstream>
#include <cstdlib>
#include <cctype>
#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile);
void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile);
bool processOperator(Stack<int>& rpnStack, char mathOpr, ofstream& resultsFile);
void displayResult(bool isValid, Stack<int>& rpnStack, ofstream& resultsFile);
void resetFlagStack(bool& isValid, Stack<int>& rpnStack);

//*****************************************************************************************************

int main()
{
	ifstream expressionsFile("expressions.txt");
	ofstream resultsFile("results.txt");
	char token[5];
	Stack<int> rpnStack;
	bool isValid = true;

	int temp = -696969;

	while (expressionsFile >> token)
	{
		outputToken(token, resultsFile);

		if (token[0] == ';')
		{
			displayResult(isValid, rpnStack, resultsFile);
			resetFlagStack(isValid, rpnStack);
		}
		else if ((isValid) && (isdigit(token[0])))
		{
			processNumber(token, rpnStack, resultsFile);
		}
		else if ((isValid) && (ispunct(token[0])))
		{
			isValid = processOperator(rpnStack, token[0], resultsFile);
		}
	}

	expressionsFile.close();
	resultsFile.close();

	return 0;
}

//*****************************************************************************************************

void outputToken(char token[], ofstream& resultsFile)
{
	resultsFile << endl << "( Token: " << token << " ) \t\t";

	if (token[0] != ';')
		cout << token << " ";
}

//*****************************************************************************************************

void processNumber(char token[], Stack<int>& rpnStack, ofstream& resultsFile)
{
	int num;

	num = atoi(token);
	rpnStack.push(num);

	resultsFile << "Push " << num;
}

//*****************************************************************************************************

bool processOperator(Stack<int>& rpnStack, char mathOpr, ofstream& resultsFile)
{
	bool success = false;
	int val1,
		val2,
		ans = 0;

	if ((rpnStack.pop(val2)) && (rpnStack.pop(val1)))
	{
		switch (mathOpr)
		{
		case '+':
			ans = val1 + val2;
			break;
		case '-':
			ans = val1 - val2;
			break;
		case '*':
			ans = val1 * val2;
			break;
		case '/':
			ans = val1 / val2;
			break;
		case '%':
			ans = val1 % val2;
			break;
		}

		resultsFile << "Pop " << val2 << "\t\t" << "Pop " << val1 << "\t\t" << "Push " << ans;

		success = true;
		rpnStack.push(ans);
	}

	return success;
}

//*****************************************************************************************************

void displayResult(bool isValid, Stack<int>& rpnStack, ofstream& resultsFile)
{
	int result;

	rpnStack.pop(result);

	if (rpnStack.pop(result))
	{
		resultsFile << endl << "\t\t\t\t" << "Invalid RPN expression - not enough operands" << endl;
		cout << "\t\t\t" << "invalid" << endl;
	}
	else if (isValid)
	{
		resultsFile << "Pop " << result;
		resultsFile << endl << "\t\t\t\t" << "Valid:\tresult = " << result << "\n\n" << endl;
		cout << "= " << result << endl;
	}
	else
	{
		resultsFile << endl << "\t\t\t\t" << "Invalid RPN expression - too many operands" << endl;
		cout << "\t\t\t" << "invalid" << endl;
	}
}

//*****************************************************************************************************

void resetFlagStack(bool& isValid, Stack<int>& rpnStack)
{
	int temp;
	isValid = true;
	
	while (rpnStack.pop(temp));
}

//*****************************************************************************************************

/*
2 4 * 5 + = 13
13 5 % 5 + = 8
15 1 + 2 / 1 - = 7
15 + 1 + 2 / 1 -                        invalid
3 4 + 15 10 - * = 35
3 4 + 6 15 10 - *                       invalid
2 13 + 14 6 - - 5 * 4 + = 39
35 6 4 2 2 / + * - = 5
3 4 + 1 2 - * 4 2 / 3 - + = -8
3 14 1 2 4 2 3 + % * + - + = 8
*/