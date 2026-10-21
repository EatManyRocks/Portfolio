//*******************************************************************************************************
//
//		File:					Students .cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #10
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 10
//
//		Due:					4/2/23
//
//
//		This program stores, displays, and counts customer records using read and write from a binary file.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include "Students.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <memory>

using namespace std;

//*******************************************************************************************************

int main()
{
	Students student1;
	int tempNum;
	char tempName[51];
	double tempGPA;

	//set

	student1.setStudentNumber(1);

	strcpy_s(tempName, 51, "John Doe");
	student1.setStudentName(tempName);

	student1.setGPA(3.5);

	//get & display

	tempNum = student1.getStudentNumber();
	student1.getStudentName(tempName);
	tempGPA = student1.getStudentGPA();

	cout << "Student 1:" << endl;
	cout << "  Number: " << tempNum << endl;
	cout << "  Name: " << tempName << endl;
	cout << "  GPA: " << tempGPA << endl;
	 
	cout << string(40, '*') << endl;

	//user input

	int userNum;
	char userName[51];
	double userGPA;

	Students student2;
	student1.setStudentNumber(2);

	cout << "Please enter information about student 2" << endl;
	
	do
	{
		cout << "Student number: ";
		cin >> userNum;
		cin.ignore();
		if (userNum < 1)
		{
			cout << "Student number can't be less than 1." << endl;
		}
	} while (userNum < 1);

	cout << "Student name: ";
	cin.getline(userName, 50);

	do
	{
		cout << "GPA: ";
		cin >> userGPA;
		cin.ignore();
		if (userGPA < 0)
		{
			cout << "GPA must be more than 0." << endl;
		}
	} while (userGPA < 0);

	cout << string(40, '*') << endl;

	cout << "Student 1:" << endl;
	cout << "  Number: " << tempNum << endl;
	cout << "  Name: " << tempName << endl;
	cout << fixed << setprecision(2) << "  GPA: " << tempGPA << endl;

	cout << "Student 2:" << endl;
	cout << "  Number: " << userNum << endl;
	cout << "  Name: " << userName << endl;
	cout << fixed << setprecision(2) << "  GPA: " << userGPA << endl;



	return 0;
}

/*
Student 1:
  Number: 1
  Name: John Doe
  GPA: 3.5
****************************************
Please enter information about student 2
Student number: 0
Student number can't be less than 1.
Student number: 90
Student name: Janet Doe
GPA: -0.9
GPA must be more than 0.
GPA: 4.0
****************************************
Student 1:
  Number: 1
  Name: John Doe
  GPA: 3.50
Student 2:
  Number: 90
  Name: Janet Doe
  GPA: 4.00

C:\Users\stone\source\repos\RussStudentsDriver\Debug\RussStudentsDriver.exe (process 35580) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/