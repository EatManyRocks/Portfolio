//*****************************************************************************************************
//
//		File:					Node.h
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
//		This is the header for the Node struct which has 2 private data members. Stores a data value
//		and the address of the next node in the linked list (LList).  
//	
//		Other files required: 
//			1.	main.cpp
//			2.  LList.h
//			3.  Stock.h
//			4.  Stock.cpp
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif