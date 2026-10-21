//*****************************************************************************************************
//
//		File:					Driver.cpp
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
//		This program is the driver.
//	
//		Other files required: 
//			1.	Employee.h
//			2.  ProductionWorker.h
//			3.  Employee.cpp
//			4.  ProductionWorker.cpp
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "Employee.h"
#include "ProductionWorker.h"

//*****************************************************************************************************

int main()
{
	Employee emp("John Workhard", "1", 2016);
	ProductionWorker pw("Dee Best", "23", 2020, 48, 10.5);

	emp.display();
	cout << endl;
	pw.display();

	return 0;
}

//*****************************************************************************************************

/*
Employee #1
Name: John Workhard
Hire Date: 2016

Employee #23
Name: Dee Best
Hire Date: 2020
Total Pay: 504
*/