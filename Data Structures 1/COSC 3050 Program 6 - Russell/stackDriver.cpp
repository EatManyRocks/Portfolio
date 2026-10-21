//*****************************************************************************************************
//
//		File:					stackDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					3/21/24
//
//
//		This program is the driver that proves the correctness of the stack class.
//	
//		Other files required: 
//			1.	stack.h
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

int main()
{
	Stack<int> numStack;
	int dataIn = 3;
	int dataOut = 0;

	if (numStack.isEmpty())
		cout << "The stack is empty." << endl;
	else
		cout << "The stack is not empty." << endl;

	if (numStack.peek(dataOut))
		cout << "Peeked data: " << dataOut << endl;
	else
		cout << "Failed to peek. Stack empty." << endl;

	if (numStack.pop(dataOut))
		cout << "Popped data: " << dataOut << endl;
	else
		cout << "Failed to pop. Stack empty." << endl;
	
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	dataIn = 5;
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	dataIn = 8;
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	if (numStack.isEmpty())
		cout << "The stack is empty." << endl;
	else
		cout << "The stack is not empty." << endl;

	dataIn = 2;
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	dataIn = 24;
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	dataIn = 36;
	if (numStack.push(dataIn))
		cout << "Pushed data: " << dataIn << endl;
	else
		cout << "Failed to push. Stack full." << endl;

	if (numStack.isFull())
		cout << "Stack is full." << endl;
	else
		cout << "Stack is not full." << endl;

	cout << "Number of values is " << numStack.getNumValues() << "." << endl;

	if (numStack.peek(dataOut))
		cout << "Peeked data: " << dataOut << endl;
	else
		cout << "Failed to peek. Stack empty." << endl;

	if (numStack.pop(dataOut))
		cout << "Popped data: " << dataOut << endl;
	else
		cout << "Failed to pop. Stack empty." << endl;

	if (numStack.pop(dataOut))
		cout << "Popped data: " << dataOut << endl;
	else
		cout << "Failed to pop. Stack empty." << endl;

	if (numStack.pop(dataOut))
		cout << "Popped data: " << dataOut << endl;
	else
		cout << "Failed to pop. Stack empty." << endl;

	if (numStack.isFull())
		cout << "Stack is full." << endl;
	else
		cout << "Stack is not full." << endl;

	return 0;
}

//*****************************************************************************************************

/*
The stack is empty.
Failed to peek. Stack empty.
Failed to pop. Stack empty.
Pushed data: 3
Pushed data: 5
Pushed data: 8
The stack is not empty.
Pushed data: 2
Pushed data: 24
Failed to push. Stack full.
Stack is full.
Number of values is 5.
Peeked data: 24
Popped data: 24
Popped data: 2
Popped data: 8
Stack is not full.
*/