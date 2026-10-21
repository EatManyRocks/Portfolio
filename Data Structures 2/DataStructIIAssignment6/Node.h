//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					10/7/24
//
//
//		This is the header for the Node struct which has 3 private data members. Stores a data value
//		and the address of the left and right nodes in the binary tree.  
//	
//		Other files required: 
//			1.	BinarySearchTree.h
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
	Node<TYPE>* left;
	Node<TYPE>* right;

	/*Node();*/
	Node(const TYPE& d, Node<TYPE>* l = nullptr, Node<TYPE>* r = nullptr);
};

//*****************************************************************************************************

//template <typename TYPE>
//Node<TYPE>::Node()
//{
//	left = nullptr;
//	right = nullptr;
//}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, Node<TYPE>* l, Node<TYPE>* r)
{
	data = d;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif