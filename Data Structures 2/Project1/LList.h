//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 2
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					9/9/24
//
//
//		This is the header for the linked list class that stores items in descending order 
//		and uses recursion to insert and remove.
//	
//		Other files required: 
//			1.	main.cpp
//			2.  Node.h
//			3.  Stock.h
//			4.  Stock.cpp
//			
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

	void removeRec(Node<TYPE>* pTemp, const TYPE& dataIn, Node<TYPE>* pBefore = nullptr);
	void insertOrderDescRec(Node<TYPE>* pTemp, const TYPE& dataIn, Node<TYPE>* pBefore = nullptr);
public:
	LList();
	~LList();
	void insertOrderDesc(const TYPE& dataIn);
	void remove(const TYPE& dataOut);
	void display() const;
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
void LList<TYPE>::insertOrderDesc(const TYPE& dataIn)
{
	insertOrderDescRec(front, dataIn);
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::insertOrderDescRec(Node<TYPE>* pTemp, const TYPE& dataIn, Node<TYPE>* pBefore)
{
	if ((pTemp == nullptr) || (dataIn > pTemp->data))
	{
		Node<TYPE>* pNew = new(nothrow) Node<TYPE>(dataIn, pTemp);

		if (pNew)
		{
			if (pBefore)
				pBefore->next = pNew;
			else
				front = pNew;
		}
	}
	else
	{
		insertOrderDescRec(pTemp->next, dataIn, pTemp);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::remove(const TYPE& dataIn)
{
	removeRec(front, dataIn);
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::removeRec(Node<TYPE>* pTemp, const TYPE& dataIn, Node<TYPE>* pBefore)
{
	if (pTemp)
	{
		if (dataIn == pTemp->data)
		{
			if (pBefore)
				pBefore->next = pTemp->next;
			else
				front = pTemp->next;
			
			delete pTemp;
		}
		else
		{
			removeRec(pTemp->next, dataIn, pTemp);
		}
	}
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

#endif