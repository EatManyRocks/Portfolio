//*******************************************************************************************************
//
//		File:					NumberArray.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #15
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 15
//
//		Due:					5/8/23
//
//
//		This program holds NumberArray class functions like get, set, constructors, and deconstructors.
//	
//		Other files required: 
//			1.	NumberArray.h
//			2.  NumberArrayDriver.cpp
//			
//*******************************************************************************************************

#include "NumberArray.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//*******************************************************************************************************

NumberArray::NumberArray(int amount)
{
	this->size = amount;
	this->arrayPtr = new double[size];
	for (int i = 0; i < size; i++)
	{
		this->arrayPtr[i] = 0;
	}
}

//*******************************************************************************************************

NumberArray::~NumberArray()
{
	delete[] arrayPtr;
}

//*******************************************************************************************************

void NumberArray::setCell(int index, double value)
{
	arrayPtr[index] = value;
}

//*******************************************************************************************************

double NumberArray::getCell(int index) const
{
	return arrayPtr[index];
}

//*******************************************************************************************************

double NumberArray::getAverage() const
{
	double total = 0;

	for (int i = 0; i < size; i++)
	{
		total += arrayPtr[i];
	}
	double average = total / size;
	return average;
}

//*******************************************************************************************************

double NumberArray::getHighest() const
{
	double highest = this->arrayPtr[0];

	for (int i = 1; i < size; i++)
	{
		if (arrayPtr[i] > highest)
		{
			highest = arrayPtr[i];
		}
	}
	return highest;
}

//*******************************************************************************************************

double NumberArray::getLowest() const
{
	double lowest = arrayPtr[0];

	for (int i = 1; i < size; i++)
	{
		if (arrayPtr[i] < lowest)
		{
			lowest = arrayPtr[i];
		}
	}
	return lowest;
}


