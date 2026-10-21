//*****************************************************************************************************
//
//		File:					stack.h
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
//		This is the header for the stack class which has 3 private data member and 6 functions.
//		The class uses an array for a stack.
//	
//		Other files required: 
//			1.	stackDriver.cpp
//			
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

#include <new>

//*****************************************************************************************************

template <typename TYPE>
class Stack
{
private:
	TYPE* stack;
	int top;
	int capacity;
public:
	Stack(int cap = 80);
	~Stack();
	bool push(const TYPE& dataIn);
	bool pop(TYPE& dataOut);
	bool peek(TYPE& dataOut) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::Stack(int cap)
{
	capacity = cap;
	stack = new(nothrow) TYPE [capacity];
	top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::~Stack()
{
	delete[] stack;
	stack = nullptr;
	top = -1;
	capacity = 0;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::push(const TYPE& dataIn)
{
	bool success = false;

	if (top + 1 < capacity)
	{
		top++;
		stack[top] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::pop(TYPE& dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		top--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::peek(TYPE& dataOut) const
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Stack<TYPE>::getNumValues() const
{
	return (top + 1);
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isFull() const
{
	return (top + 1 >= capacity);
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return (top == -1);
}

//*****************************************************************************************************

#endif