//*******************************************************************************************************
//
//		File:					StudentInfo2.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #8
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 8
//
//		Due:					3/13/23
//
//
//		This program keeps track of students' information in a class using structures with functions.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//*******************************************************************************************************

struct Students
{
	char name[81];
	int id;
	double grade;
};

//*******************************************************************************************************

const string line(60, '*');

//*******************************************************************************************************

void editStudent(Students[], int);
void viewStudent(const Students[], int);
void countStudent(const Students[], int);

//*******************************************************************************************************

int main()
{
	const int SIZE = 10;
	Students students[SIZE];
	bool loop = true;
	int choice = 0;

	for (int i = 0; i < SIZE; i++)
	{
		students[i] = { "-", 0, 0 };
	}

	while (loop)
	{
		choice = 0;

		cout << line << endl;
		cout << "1)      Edit a student" << endl;
		cout << "2)      View a student info" << endl;
		cout << "3)      Display a count of how many students are in the list." << endl;
		cout << "4)      quit" << endl;
		cout << "Please choose one of the options: ";
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "Please choose an option between 1 to 4: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			editStudent(students, SIZE);
			break;
		case 2:
			viewStudent(students, SIZE);
			break;
		case 3:
			countStudent(students, SIZE);
			break;
		case 4:
			cout << "Finished!" << endl;
			loop = false;
			break;
		}
	}
	return 0;
}

//*******************************************************************************************************

void editStudent(Students students[], int size)
{
	int index = 0;

	cout << "Please enter an index: ";
	cin >> index;
	cin.ignore();

	while (index < 0 || index >= size)
	{
		cout << "Enter a valid index (0-9): ";
		cin >> index;
	}

	cout << "Please enter a name: ";
	cin.getline(students[index].name, 81);

	cout << "Please enter an ID: ";
	cin >> students[index].id;

	cout << "Please enter a grade: ";
	cin >> students[index].grade;

}

//*******************************************************************************************************

void viewStudent(const Students students[], int size)
{
	int index = 0;

	cout << "Please enter an index: ";
	cin >> index;

	while (index < 0 || index >= size)
	{
		cout << "Enter a valid index (0-9): ";
		cin >> index;
	}

	while (strcmp(students[index].name, "-") == 0)
	{
		cout << "There is no student on that index, please re-enter: ";
		cin >> index;
	}

	cout << students[index].id << ". " << students[index].name << " " << students[index].grade << endl;

}

//*******************************************************************************************************

void countStudent(const Students students[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(students[i].name, "-") != 0)
		{
			count++;
		}
	}

	cout << "There are " << count << " students" << endl;
}

//*******************************************************************************************************

/*
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 5
Please choose an option between 1 to 4: 1
Please enter an index: 1
Please enter a name: John
Please enter an ID: 1234
Please enter a grade: 97
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 2
Please enter an index: 1
1234. John 97
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 2
Please enter an index: 0
There is no student on that index, please re-enter: 1
1234. John 97
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 1
Please enter an index: 4
Please enter a name: Jane
Please enter an ID: 234
Please enter a grade: 59
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 3
There are 2 students
************************************************************
1)      Edit a student
2)      View a student info
3)      Display a count of how many students are in the list.
4)      quit
Please choose one of the options: 4
Finished!

C:\Users\stone\source\repos\RussStudentInfo2\Debug\RussStudentInfo2.exe (process 27484) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/