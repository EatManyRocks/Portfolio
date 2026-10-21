//*****************************************************************************************************
//
//		File:					Employee.h
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
//		This program is the header for the employee class.
//	
//		Other files required: 
//			1.	Driver.cpp
//			2.  ProductionWorker.h
//			3.  Employee.cpp
//			4.  ProductionWorker.cpp
//			
//*****************************************************************************************************

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

//*****************************************************************************************************

class Employee
{
private:
	string empName;
	string empNum;
	int hireDate;
public:
	Employee(string name = "***", string num = "***", int date = 1900);
	void display() const;
};

//*****************************************************************************************************

#endif
