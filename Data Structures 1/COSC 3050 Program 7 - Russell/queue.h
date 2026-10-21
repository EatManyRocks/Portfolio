//*****************************************************************************************************
//
//		File:					queue.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #7
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					3/28/24
//
//
//		The class definition for a linked implementation of a queue.
//	
//		Other files required: 
//			1.	node.h
//			2.	qDriver.cpp
//			
//*****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************************************************

#include <new>
#include "node.h"

//*****************************************************************************************************

template <typename TYPE>
class Queue
{
private:
	Node<TYPE>* front;
	Node<TYPE>* rear;
	int numValues;
public:
	Queue();
	~Queue();
	bool enqueue(const TYPE& dataIn);
	bool dequeue(TYPE& dataOut);
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::Queue()
{
	front = nullptr;
	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::~Queue()
{
	Node<TYPE>* pTemp;

	while (front)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	rear = nullptr;
	numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pNew;
	pNew = new(nothrow) Node<TYPE>(dataIn);

	if (pNew)
	{
		if (rear)
		{
			rear->next = pNew;
		}
		else
		{
			front = pNew;
		}

		rear = pNew;
		numValues++;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pDel = front;

	if (front)
	{
		dataOut = front->data;
		front = front->next;
		delete pDel;
		numValues--;

		if (front == nullptr)
		{
			rear = nullptr;
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewFront(TYPE& dataOut) const
{
	bool success = false;

	if (front)
	{
		dataOut = front->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;

	if (rear)
	{
		dataOut = rear->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Queue<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isFull() const
{
	bool success = true;
	Node<TYPE>* pTemp;

	pTemp = new(nothrow) Node<TYPE>();

	if (pTemp)
	{
		success = false;
		delete pTemp;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

#endif