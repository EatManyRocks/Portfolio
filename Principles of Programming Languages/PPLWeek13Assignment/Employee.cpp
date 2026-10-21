//*****************************************************************************************************
//
//		File:					Employee.cpp
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
//			4.  ProductionWorker.cpp
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "Employee.h"

//*****************************************************************************************************

Employee::Employee(string name, string num, int date)
{
	empName = name;
	empNum = num;
	hireDate = date;
}

//*****************************************************************************************************

void Employee::display() const
{
	cout << "Employee #" << empNum << endl;
	cout << "Name: " << empName << endl;
	cout << "Hire Date: " << hireDate << endl;
}

//*****************************************************************************************************

