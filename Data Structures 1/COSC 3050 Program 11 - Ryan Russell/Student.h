//*****************************************************************************************************
//
//		File:					Student.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					4/25/24
//
//
//		This is the header for the student struct which stores student information and has
//		over-loaded operators for "cout <<" and comparison operators.
//	
//		Other files required: 
//			1.	StudentList.cpp
//			2.  node.h
//			3.	DLList.h
//			4.	studentFile.txt
//			
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream& operator << (ostream& out, const Student & data);

	bool operator < (const Student& rhs);
	bool operator < (int value);
	bool operator > (const Student& rhs);
	bool operator > (int value);
	bool operator <= (const Student& rhs);
	bool operator <= (int value);
	bool operator >= (const Student& rhs);
	bool operator >= (int value);
	bool operator == (const Student& rhs);
	bool operator == (int value);
	bool operator != (const Student& rhs);
	bool operator != (int value);
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

ostream& operator << (ostream& out, const Student& data)
{
	out << left << setw(12) << data.id << setw(30) << data.name << setw(10) << data.major
		<< data.gpa;
	return out;
}

//*****************************************************************************************************

bool Student::operator < (const Student& rhs)
{
	return(this->id < rhs.id);
}

//*****************************************************************************************************

bool Student::operator < (int value)
{
	return(this->id < value);
}

//*****************************************************************************************************

bool Student::operator > (const Student& rhs)
{
	return(this->id > rhs.id);
}

//*****************************************************************************************************

bool Student::operator > (int value)
{
	return(this->id > value);
}

//*****************************************************************************************************

bool Student::operator <= (const Student& rhs)
{
	return(this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student::operator <= (int value)
{
	return(this->id <= value);
}

//*****************************************************************************************************

bool Student::operator >= (const Student& rhs)
{
	return(this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student::operator >= (int value)
{
	return(this->id >= value);
}

//*****************************************************************************************************

bool Student::operator == (const Student& rhs)
{
	return(this->id == rhs.id);
}

//*****************************************************************************************************

bool Student::operator == (int value)
{
	return(this->id == value);
}

//*****************************************************************************************************

bool Student::operator != (const Student& rhs)
{
	return(this->id != rhs.id);
}

//*****************************************************************************************************

bool Student::operator != (int value)
{
	return(this->id != value);
}

#endif