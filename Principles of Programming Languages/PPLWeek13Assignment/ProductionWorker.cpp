//*****************************************************************************************************
//
//		File:					ProductionWorker.cpp
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
//		This program contains all the functions for the employee class.
//	
//		Other files required: 
//			1.	Driver.cpp
//			2.  ProductionWorker.h
//			3.  Employee.h
//			4.  Employee.cpp
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "ProductionWorker.h"

//*****************************************************************************************************

ProductionWorker::ProductionWorker(string name, string num, int date, int h, double p)
	:Employee(name, num, date)
{
	hours = h;
	payRate = p;
}

//*****************************************************************************************************

void ProductionWorker::display() const
{
	Employee::display();
	cout << "Total Pay: " << hours * payRate << endl;
}

//*****************************************************************************************************