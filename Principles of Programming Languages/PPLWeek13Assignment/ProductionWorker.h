//*****************************************************************************************************
//
//		File:					ProductionWorker.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Week 13
//
//		Course Name:			Principles of Programming Languages
//
//		Course Number:			COSC 3810
//
//		Due:					11/25/24
//
//
//		This program is the header for the Production Worker class which is derived from Employee.
//	
//		Other files required: 
//			1.	Driver.cpp
//			2.  Employee.h
//			3.  Employee.cpp
//			4.  ProductionWorker.cpp
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

#include "Employee.h"

//*****************************************************************************************************

class ProductionWorker: public Employee
{
private:
	int hours;
	double payRate;
public:
	ProductionWorker(string name = "***", string num = "***", int date = 1900, int h = 40, double p = 9.5);
	void display() const;
};

//*****************************************************************************************************

#endif
