//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/4/24
//
//
//		This is the header for the Node struct which has 4 private data members. Stores a data value
//		and the address of the left and right nodes in the AVL tree.  
//	
//		Other files required: 
//			1.	AVLTree.h
//			2.  Stock.h
//			3.  main.cpp
//			4.  Stock.txt
//			5.	Stock.cpp
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	int bFactor;
	Node<TYPE>* left;
	Node<TYPE>* right;

	Node(const TYPE& d, Node<TYPE>* l = nullptr, Node<TYPE>* r = nullptr, int b = 0);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* l, Node<TYPE>* r, int b)
{
	data = d;
	bFactor = b;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif