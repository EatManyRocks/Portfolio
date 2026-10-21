//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					9/16/24
//
//
//		This is the header for the Stock class.
//	
//		Other files required: 
//			1.	ArrayList.h
//			2.  Stock.cpp
//			3.  main.cpp
//			
//*****************************************************************************************************

#ifndef HTELEMENT_H
#define HTELEMENT_H

//*****************************************************************************************************

template <typename TYPE>
struct HTElement
{
	TYPE item;
	int status;

	HTElement();
}; 

//*****************************************************************************************************

template <typename TYPE>
HTElement<TYPE>::HTElement()
{
	status = 0;
}

//*****************************************************************************************************

#endif