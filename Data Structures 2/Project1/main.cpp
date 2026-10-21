//*****************************************************************************************************
//
//		File:					main.cpp
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
//		This program is the driver.
//	
//		Other files required: 
//			1.	List.h
//			2.  Node.h
//			3.  Stock.h
//			4.  Stock.cpp
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "LList.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{
	const int size = 5;
	int array1[size] = {1, 2, 3, 4, 5};
	int value = 3;
	bool found = false;

	for (int i = 0; i < size && !found; i++)
	{
		if (array1[i] == value)
			found = true;
	}

	if (found)
		cout << "Value was found." << endl;
	else
		cout << "Value was not found." << endl;

	return 0;
}

//*****************************************************************************************************

/*
Stock3  Stock2  Stock1
Stock4  Stock3  Stock2  Stock1
Stock4  Stock3  Stock1
Stock3  Stock1
*/