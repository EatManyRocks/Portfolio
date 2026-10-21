//*******************************************************************************************************
//
//		File:					Students.cpp
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
//		This program holds Student class functions like get, set, constructors, deconstructors, and private functions.
//	
//		Other files required: 
//			1.	Students.h
//			2.  StudentsDriver.cpp
//			
//*******************************************************************************************************

#include "Students.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//*******************************************************************************************************

void Students::_initStudentNumber(char* num)
{
	this->studentNumber = new char[51];
	strcpy_s(this->studentNumber, 51, num);
}

//*******************************************************************************************************

void Students::_initStudentName(char* name)
{
	this->studentName = new char[51];
	strcpy_s(this->studentName, 51, name);
}

//*******************************************************************************************************

Students::Students(char* num, char* name, double tempGPA)
{
	_initStudentNumber(num);
	_initStudentName(name);
	this->GPA = tempGPA;
}

//*******************************************************************************************************

Students::Students()
{
	studentName = new char[51];
	studentNumber = new char[51];
	strcpy_s(studentNumber, 51, "00000");
	strcpy_s(studentName, 51, "*none*");
	GPA = 0.0;
}


//*******************************************************************************************************

Students::~Students()
{
	cout << this->studentName << " removed." << endl;
	delete[] this->studentNumber;
	delete[] this->studentName;
}

//*******************************************************************************************************

void Students::setStudentNumber(char* num)
{
	_initStudentNumber(num);
}

//*******************************************************************************************************

void Students::setStudentName(char* name)
{
	_initStudentName(name);
}

//*******************************************************************************************************

void Students::setGPA(double gpaNum)
{
	this->GPA = gpaNum;
}

//*******************************************************************************************************

const char* Students::getStudentName() const
{
	return studentName;
}

//*******************************************************************************************************

const char* Students::getStudentNumber() const
{
	return studentNumber;
}

//*******************************************************************************************************

double Students::getStudentGPA() const
{
	return GPA;
}