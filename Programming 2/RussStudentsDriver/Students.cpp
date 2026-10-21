#include "Students.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

//*******************************************************************************************************

void Students::setStudentNumber(int num)
{
	if (num > 0)
	{
		studentNumber = num;
	}
	else
	{
		cout << "Student number can't be less than 1." << endl;
		exit(EXIT_FAILURE);
	}
}

void Students::setStudentName(char* name)
{
	if (strlen(name) < 51)
	{
		strcpy_s(studentName, 51, name);
	}
	else
	{
		cout << "Student name must be 50 or less characters." << endl;
		exit(EXIT_FAILURE);
	}
}

void Students::setGPA(double gpaNum)
{
	if (gpaNum > 0)
	{
		GPA = gpaNum;
	}
	else
	{
		cout << "GPA must be more than 0." << endl;
		exit(EXIT_FAILURE);
	}
}

void Students::getStudentName(char* outStr) const
{
	for (int i = 0; i < 50; ++i)
	{
		outStr[i] = studentName[i];
	}
}

int Students::getStudentNumber() const
{
	return studentNumber;
}

double Students::getStudentGPA() const
{
	return GPA;
}