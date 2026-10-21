//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					4/25/24
//
//
//		This is the header for the Node struct which has 2 private data members. Stores a data value
//		and the address of the next and prev node.  
//	
//		Other files required: 
//			1.	StudentList.cpp
//			2.  DLList.h
//			3.	Student.h
//			4.	studentFile.txt
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
	Node<TYPE>* prev;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr, Node<TYPE>* p = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	next = n;
	prev = p;
}

//*****************************************************************************************************

#endif