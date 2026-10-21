//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					4/4/24
//
//
//		This is the header for the Node struct which has 2 private data members. Stores a data value
//		and the address of the next node.  
//	
//		Other files required: 
//			1.	pal2.cpp
//			2.	queue.h
//			3.	stack.h
//			4.	palindromes.txt
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