//*****************************************************************************************************
//
//		File:					StudentList.cpp
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
//		This is the application file that uses a doubly linked list to store
//		student information/records. 
//	
//		Other files required: 
//			1.	DLList.cpp
//			2.  node.h
//			3.	Student.h
//			4.	studentFile.txt
//			
//*****************************************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "DLList.h"

//*****************************************************************************************************

char getChoice();
void process(DLList<Student>& sList);
void buildList(DLList<Student>& sList);
void displayStudents(DLList<Student>& sList);
void displayStudentsRev(DLList<Student>& sList);
void countStudents(DLList<Student>& sList);
void addNewStudent(DLList<Student>& sList);
void removeStudent(DLList<Student>& sList);
void findStudent(DLList<Student>& sList);

//*****************************************************************************************************

int main()
{
	DLList<Student>studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "======== MENU ========\n"
		<< " A:  Add a new Student\n"
		<< " F:  Find a Student Record\n"
		<< " R:  Remove a Student\n"
		<< " D:  Display Students\n"
		<< " V:  Display Students in Reverse\n"
		<< " C:  Counts number of Students\n"
		<< " Q:  Quit\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'F':
		case 'R':
		case 'D':
		case 'V':
		case 'C':
		case 'Q':
			valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice\n"
				 << "Please try again: ";
			break;
		}
	} 
	while (!valid);

	return choice;
}

//*****************************************************************************************************

void process(DLList<Student>& sList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':
			addNewStudent(sList);
			break;
		case 'F':
			findStudent(sList);
			break;
		case 'R':
			removeStudent(sList);
			break;
		case 'D':
			displayStudents(sList);
			break;
		case 'V':
			displayStudentsRev(sList);
			break;
		case 'C':
			countStudents(sList);
			break;
		case 'Q':
			break;
		}
	} 
	while (choice != 'Q');
}

//*****************************************************************************************************

void buildList(DLList<Student>& sList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
					>> student.gender
					>> student.year
					>> student.credits
					>> student.gpa
					>> student.major;

		sList.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void displayStudents(DLList<Student>& sList)
{
	cout << "\n\t\t\tSTUDENT LIST" << endl;
	cout << "========================================================" << endl;
	cout << left << setw(12) << "ID" << setw(30) << "NAME" << setw(10) << "MAJOR"
		<< "GPA" << endl;
	cout << "========================================================" << endl;
	sList.display();
}

//*****************************************************************************************************

void displayStudentsRev(DLList<Student>& sList)
{
	cout << "\n\t\tREVERSE STUDENT LIST" << endl;
	cout << "========================================================" << endl;
	cout << left << setw(12) << "ID" << setw(30) << "NAME" << setw(10) << "MAJOR"
		<< "GPA" << endl;
	cout << "========================================================" << endl;
	sList.displayReverse();
}

//*****************************************************************************************************

void countStudents(DLList<Student>& sList)
{
	cout << "\nNumber of Students: " << sList.getNumValues() << endl;
}

//*****************************************************************************************************

void addNewStudent(DLList<Student>& sList)
{
	Student newStudent;
	bool valid = false;

	cout << endl;

	while (!valid)
	{
		cout << "Enter student ID: ";
		cin >> newStudent.id;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	cout << "Enter student name: ";
	cin.ignore();
	cin.getline(newStudent.name, 50);
	cout << "Enter student city and state: ";
	cin.ignore();
	cin.getline(newStudent.citystate, 50);

	valid = false;
	while (!valid)
	{
		cout << "Enter student's phone number: ";
		cin >> newStudent.phone;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	valid = false;
	while (!valid)
	{
		cout << "Enter student gender: ";
		cin >> newStudent.gender;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}


	valid = false;
	while (!valid)
	{
		cout << "Enter students year: ";
		cin >> newStudent.year;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	valid = false;
	while (!valid)
	{
		cout << "Enter students credits: ";
		cin >> newStudent.credits;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	valid = false;
	while (!valid)
	{
		cout << "Enter students GPA: ";
		cin >> newStudent.gpa;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	valid = false;
	while (!valid)
	{
		cout << "Enter student major: ";
		cin >> newStudent.major;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	sList.insert(newStudent);

	cout << newStudent << endl;
}

//*****************************************************************************************************

void removeStudent(DLList<Student>& sList)
{
	Student delStudent;

	cout << "\nEnter ID of student you would wish to remove" << endl;
	cin >> delStudent.id;

	if (!sList.remove(delStudent))
	{
		cout << "Removal failed!" << endl;
	}
	else
	{
		cout << delStudent << endl;
	}
}

//*****************************************************************************************************

void findStudent(DLList<Student>& sList)
{
	Student tempStudent;

	cout << "\nEnter ID of student you would wish to retrieve information" << endl;
	cin >> tempStudent.id;

	if (!sList.retrieve(tempStudent))
	{
		cout << "Retrieval failed!" << endl;
	}
	else
	{
		cout << tempStudent << endl;
	}
}

//*****************************************************************************************************

/*
======== MENU ========
 A:  Add a new Student
 F:  Find a Student Record
 R:  Remove a Student
 D:  Display Students
 V:  Display Students in Reverse
 C:  Counts number of Students
 Q:  Quit
Enter your choice: v

                REVERSE STUDENT LIST
========================================================
ID          NAME                          MAJOR     GPA
========================================================
32631       Freud, JR, Fred E             PSYC      1.85
32598       Xerxes, Art I                 GREE      3.25
31631       Aristotle, Alice A            PHIL      3.1
30878       Lewis, Clark N                GEOG      3.37
30749       Mendelssohn, Mozart W         MUSC      2.87
30655       Angelo, Mike L                ART       3.74
30381       Elba, Able M                  SPEE      3.4
30280       Dewey, Johanna A              EDUC      3.83
30268       Newmann, Alfred E             EDUC      0.99
29583       Yewliss, Cal C                MATH      2.99
28658       Cicero, Marsha                LATI      2.87
27503       Fahrenheit, Felicia O         CHEM      3.85
26316       Custer, General G             HIST      1.95
25831       Santamaria, Nina P            HIST      1.77
25377       Porgy, Bess N                 MUSI      2.78
24237       Euler, Lennie L               MATH      3.83
23750       Vespucci, Vera D              GEOG      2.29
23544       Gestalt, Gloria G             PSYC      2.48
23497       Fault, Paige D                CPSC      2.95
23314       Macdonald, Ronald B           CPSC      2.99
22447       Zylstra, Zelda A              ENGL      1.95
22277       Principal, Pamela P           EDUC      1.75
21144       Pasteur, Louise A             BIOL      3.1
20991       Augusta, Ada B                CPSC      3.83
20454       Chicita, Juanita A            BIOL      2.66
19918       Virus, Vera W                 CPSC      3.25
19077       Medes, Archie L               ENGR      3.1
18264       Lucky, Lucy L                 HIST      2.29
18213       Marx, Karl Z                  ECON      2.75
17424       Nakamura, Toky O              SOCI      1.95
17376       Scrooge, Ebenezer T           SOCI      3.25
16622       Issacson, Esau B              RELI      2.98
16540       Weerd, Dewey L                PHIL      2.99
16183       Kuts, Cole                    FOOD      3.98
15889       Gazelle, Gwendolyn D          PE        2.78
15802       Pascal, Blaze R               CPSC      1.98
15755       VandenVander, Vanessa V       HIST      3.74
15671       Rembrandt, Roberta E          ART       2.2
15052       Einstein, Alfred M            ENGR      2.78
14815       Tchaikovsky, Wolfgang A       MUSC      2.75
14674       Rockne, Newton K              PE        1.98
13511       Pitt, Stew                    GNED      0.21
11951       Mouse, Michael E              EDUC      1.99
11749       Issacson, Jacob A             RELI      2.99
11688       Kronecker, Leo P              MATH      2.75
10304       Deutsch, Sprechen Z           GERM      3.05
10236       Andrews, Peter J              CPSC      2.78
9743        Johnson, James L              ENGR      3.15
9463        Hochschule, Hortense C        EDUC      2.7
7885        Fibonacci, Leonard O          MATH      3.25
7844        Aardvark, Anthony A           ENGR      2.79
7448        Roosevelt, Rose Y             POLS      2.95
7107        Shoemaker, Imelda M           POLS      3.15
5873        Psycho, II,  Prunella E       PSYC      2.99
5710        Busch, Arch E                 ENGR      2.75
5430        Nightingale, Florence K       NURS      3.15
5316        GotoDijkstra, Edgar G         CPSC      4
4777        Gauss, Carl F                 MATH      4
4559        Shyster, Samuel D             SOCI      1.95
4454        Atanasoff, Eniac C            CPSC      1.88
3930        Leibniz, Gottfried W          MATH      1.95

======== MENU ========
 A:  Add a new Student
 F:  Find a Student Record
 R:  Remove a Student
 D:  Display Students
 V:  Display Students in Reverse
 C:  Counts number of Students
 Q:  Quit
Enter your choice: q
*/