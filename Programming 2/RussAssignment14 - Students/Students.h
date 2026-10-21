//*******************************************************************************************************
//
//		File:					Students.h
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
//		This is the header for the Student class.
//	
//		Other files required: 
//			1.	StudentsDriver.cpp
//			2.  Students.cpp
//			
//*******************************************************************************************************

#ifndef STUDENTS_H
#define STUDENTS_H

//*******************************************************************************************************

class Students
{
private:
	char* studentNumber;
	char* studentName;
	double GPA;

	void _initStudentNumber(char*);
	void _initStudentName(char*);
public:
	//can't figure out how to use a default argument to set studentNumber and studentName to a default argument with being a char*
	Students(char* num, char* name, double tempGPA = 0);
	Students();
	~Students();

	void setStudentNumber(char*);
	void setStudentName(char*);
	void setGPA(double);
	const char* getStudentName() const;
	const char* getStudentNumber() const;
	double getStudentGPA() const;
};

//*******************************************************************************************************

#endif