//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/29/24
//
//
//		This is the header for the LList class which has 1 private data member and 9 functions.
//		The class is a linked list which is ordered.
//		Holds the front node address and uses functions to insert, remove, and retrieve Nodes/data. 
//		Also, includes functions to display the list's data, get number of values, and check
//		if the list is full or empty.
//	
//		Other files required: 
//			1.	LDriver.cpp
//			2.  Node.h
//			
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename TYPE>
class LList
{
private:
	Node<TYPE>* front;
public:
	LList();
	~LList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& dataOut) const;
	bool viewFront(TYPE& dataOut) const;
	bool viewRear(TYPE& dataOut) const;
	void display() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
};

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE>::LList()
{
	front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE>::~LList()
{
	Node<TYPE>* pTemp;

	while (front != nullptr)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::insert(const TYPE& dataIn)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pAfter = front;
	Node<TYPE>* pNew;

	while ((pAfter) && (pAfter->data < dataIn))
	{
		pBefore = pAfter;
		pAfter = pAfter->next;
	}

	pNew = new(nothrow) Node<TYPE>(dataIn, pAfter);

	if (pNew)
	{
		if (pBefore)
			pBefore->next = pNew;
		else
			front = pNew;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;
	Node<TYPE>* pBefore = nullptr;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pBefore = pTemp;
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;

		if (pBefore)
			pBefore->next = pTemp->next;
		else
			front = pTemp->next;

		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->data < dataOut))
	{
		pTemp = pTemp->next;
	}

	if ((pTemp) && (pTemp->data == dataOut))
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::viewFront(TYPE& dataOut) const
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
bool LList<TYPE>::viewRear(TYPE& dataOut) const
{
	bool success = false;
	Node<TYPE>* pTemp = front;

	while ((pTemp) && (pTemp->next))
	{
		pTemp = pTemp->next;
	}

	if (pTemp)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::display() const
{
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		cout << pTemp->data << "\t";
		pTemp = pTemp->next;
	}

	cout << endl;
}

//*****************************************************************************************************

template <typename TYPE>
int LList<TYPE>::getNumValues() const
{
	int numValues = 0;
	Node<TYPE>* pTemp = front;

	while (pTemp)
	{
		numValues++;
		pTemp = pTemp->next;
	}

	return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::isEmpty() const
{
	return (!front);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::isFull() const
{
	bool success = true;
	Node<TYPE>* pTemp;

	pTemp = new(nothrow) Node<TYPE>;

	if (pTemp)
	{
		success = false;
		delete pTemp;
	}

	return success;
}

//*****************************************************************************************************

#endif