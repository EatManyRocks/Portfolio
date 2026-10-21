//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/11/24
//
//
//		This is the header for the Node struct which has 3 private data members. Stores a data value
//		and the address of the left and right nodes in the binary tree.  
//	
//		Other files required: 
//			1.	main.cpp
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  HuffmanStock.txt
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	double frequency;
	Node<TYPE>* left;
	Node<TYPE>* right;

	Node(const TYPE& d = TYPE(), double f = 0, Node<TYPE>* l = nullptr, Node<TYPE>* r = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE& d, double f, Node<TYPE>* l, Node<TYPE>* r)
{
	data = d;
	frequency = f;
	left = l;
	right = r;
}

//*****************************************************************************************************

#endif