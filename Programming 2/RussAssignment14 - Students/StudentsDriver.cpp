//*******************************************************************************************************
//
//		File:					StudentsDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #14
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 14
//
//		Due:					5/1/23
//
//
//		This program uses a Student class, constructors, deconstructors, and default arguments to store and display student info.
//	
//		Other files required: 
//			1.	Students.h
//			2.  Students.cpp
//			
//*******************************************************************************************************

#include "Students.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

//*******************************************************************************************************

char* getID();
double getGPA();
char* getName();
void getInput(Students*, const int);
void displayAllStudentsInfo(const Students*, const int);


//*******************************************************************************************************

int main()
{
	const int SIZE = 3;
	Students* ptrStu = new Students[SIZE];
	char* userNum;
	char* userName;
	double userGPA;

	displayAllStudentsInfo(ptrStu, SIZE);
	getInput(ptrStu, SIZE);
	displayAllStudentsInfo(ptrStu, SIZE);

	delete[] ptrStu;
	return 0;
}

//*******************************************************************************************************

char* getID()
{
	char* tempNum = new char[51];
	do
	{
		cout << "Student number: ";
		cin.getline(tempNum, 50);
		if (strlen(tempNum) != 5)
		{
			cout << "Student number must be 5 digits." << endl;
		}
	} while (strlen(tempNum) != 5);
	return tempNum;
}

//*******************************************************************************************************

double getGPA()
{
	double tempGPA;
	do
	{
		cout << "GPA: ";
		cin >> tempGPA;
		cin.ignore();
		if (tempGPA < 0 || tempGPA > 4)
		{
			cout << "GPA must be more than 0 and equal to or less than 4.0." << endl;
		}
	} while (tempGPA < 0 || tempGPA > 4);
	return tempGPA;
}

//*******************************************************************************************************

char* getName()
{
	char* tempName = new char[51];
	do
	{
		cout << "Student name: ";
		cin.getline(tempName, 50);
		if (strlen(tempName) > 51)
		{
			cout << "Student name can't be more than 50 characters." << endl;
		}
	} while (strlen(tempName) > 51);
	return tempName;
}

//*******************************************************************************************************

void getInput(Students* ptrS, const int size)
{
	cout << string(40, '*') << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter information for student " << i + 1 << endl;
		ptrS[i].setStudentNumber(getID());
		ptrS[i].setStudentName(getName());
		ptrS[i].setGPA(getGPA());
	}
}

//*******************************************************************************************************

void displayAllStudentsInfo(const Students* ptrS, const int size)
{
	cout << string(60, '*') << endl;
	cout << left << setw(25) << "Student Name";
	cout << setw(25) << "Student Number";
	cout << "GPA" << endl;
	cout << string(60, '*') << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(25) << ptrS[i].getStudentName();
		cout << setw(25) << ptrS[i].getStudentNumber();
		cout << fixed << setprecision(2) << ptrS[i].getStudentGPA() << endl;
	}
}

//*******************************************************************************************************

/*
************************************************************
Student Name             Student Number           GPA
************************************************************
*none*                   00000                    0.00
*none*                   00000                    0.00
*none*                   00000                    0.00
****************************************
Please enter information for student 1
Student number: 1001
Student number must be 5 digits.
Student number: 10001
Student name: John Doe
GPA: 4.0
Please enter information for student 2
Student number: 10002
Student name: Joe Doe
GPA: 4.5
GPA must be more than 0 and equal to or less than 4.0.
GPA: 3.4
Please enter information for student 3
Student number: 10004
Student name: Janet Doe
GPA: 2.1
************************************************************
Student Name             Student Number           GPA
************************************************************
John Doe                 10001                    4.00
Joe Doe                  10002                    3.40
Janet Doe                10004                    2.10
Janet Doe removed.
Joe Doe removed.
John Doe removed.

C:\Users\stone\source\repos\RussAssignment14 - Students\Debug\RussAssignment14 - Students.exe (process 46428) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/