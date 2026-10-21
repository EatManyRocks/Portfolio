//*******************************************************************************************************
//
//		File:					NumberArrayDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #15
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 15
//
//		Due:					5/8/23
//
//
//		This program uses a NumberArray class to store user inputs in an array the size the user 
//		decides. 
//	
//		Other files required: 
//			1.	NumberArray.h
//			2.  NumberArray.cpp
//			
//*******************************************************************************************************

#include "NumberArray.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int getNumberOfValues();
int getIndex(int);
void display(const NumberArray&, int);

//*******************************************************************************************************

int main()
{
	int size = getNumberOfValues();
	double userNum;
	NumberArray obj1(size);

	cout << "Enter the " << size << " numbers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Number " << i + 1 << ": ";
		cin >> userNum;
		obj1.setCell(i, userNum);
	}

	display(obj1, size);
	
	int index = 0;
	cout << "Which number do you want to change: ";
	cin >> index;
	while (index < 1 || index > size)
	{
		cout << "!!!Error, index must be in the range of 1 - " << size << endl;
		cout << "Re-enter: ";
		cin >> index;
	}
	cout << "The current number on index " << index << ": " << obj1.getCell(index) << endl;
	cout << "What is the new number: ";
	cin >> userNum;
	obj1.setCell((index - 1), userNum);

	display(obj1, size);
}

//*******************************************************************************************************

int getNumberOfValues()
{
	int amount = 0;
	cout << "How many numbers do you want to store: ";
	cin >> amount;
	while (amount <= 1 || amount > 100)
	{
		cout << "!! Amount must be of length 2-100 !!" << endl;
		cout << endl;
		cout << "How many numbers do you want to store: ";
		cin >> amount;
	}
	return amount;
}

//*******************************************************************************************************

int getIndex(int size)
{
	int index = -1;

	while (index < 0 || index >= size)
	{
		cout << "Enter an index value for the array: ";
		cin >> index;
	}
	return index;
}

//*******************************************************************************************************

void display(const NumberArray& obj, int size)
{
	cout << string(25, '-') << endl;
	cout << "Here are the numbers in this array:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Number " << i + 1 << ": ";
		cout << obj.getCell(i) << endl;
	}

	cout << endl;
	cout << string(25, '-') << endl;
	cout << "The average of those numbers is :" << fixed << setprecision(2) << obj.getAverage() << endl;
	cout << "The highest of those numbers is :" << obj.getHighest() << endl;
	cout << "The lowest of those numbers is :" << obj.getLowest() << endl;
}

//*******************************************************************************************************

/*
How many numbers do you want to store: 4
Enter the 4 numbers:
Number 1: -100
Number 2: 92.5
Number 3: 3.14
Number 4: 9.56
-------------------------
Here are the numbers in this array:
Number 1: -100
Number 2: 92.5
Number 3: 3.14
Number 4: 9.56

-------------------------
The average of those numbers is :1.30
The highest of those numbers is :92.50
The lowest of those numbers is :-100.00
Which number do you want to change: 9
!!!Error, index must be in the range of 1 - 4
Re-enter: 0
!!!Error, index must be in the range of 1 - 4
Re-enter: 3
The current number on index 3: 9.56
What is the new number: 2.86
-------------------------
Here are the numbers in this array:
Number 1: -100.00
Number 2: 92.50
Number 3: 2.86
Number 4: 9.56

-------------------------
The average of those numbers is :1.23
The highest of those numbers is :92.50
The lowest of those numbers is :-100.00

C:\Users\stone\source\repos\RussNumberArray - 15\Debug\RussNumberArray - 15.exe (process 7740) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/