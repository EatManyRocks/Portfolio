//***************************************************************
//
//		Assignment:		#12
// 
//		File:			RussAssignment12.cpp
// 
//		Due Date:		October 7, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Mobile Service Provider with three data plans
//						that uses switch menus
//
//
//***************************************************************


#include<iostream>
#include<cctype>
#include<iomanip>
using namespace std;
int main()
{
	char choice = 'D';
	double gigabytes = 0;
	double cost = 0;

	cout << "Select a subscription package (Enter Letter of Choice):\n";
	cout << "Package A\n";
	cout << "Package B\n";
	cout << "Package C\n";
	cout << "Quit D\n";
	cin >> choice;
	choice = toupper(choice);

	while (choice < 'A' && choice > 'D')
	{
		cout << "Please enter a valid letter (A, B, C, or D)\n\n";
		cout << "Select a subscription package (Enter Letter of Choice):\n";
		cout << "Package A\n";
		cout << "Package B\n";
		cout << "Package C\n";
		cout << "Quit D\n";
		cin >> choice;
		choice = toupper(choice);
	}

	switch (choice)
	{
	case 'A': 
	{
		cout << "How many gigabytes were used: ";
		cin >> gigabytes;
		cout << fixed << showpoint << setprecision(2);
		if (gigabytes < 4)
		{
			cout << "The total amount due is $39.99";
		}
		else
		{
			cost = 39.99 + (10 * (gigabytes - 4));
			cout << "The total amount due is $" << cost;
		}
		break;
	}
	case 'B':
	{
		cout << "How many gigabytes were used: ";
		cin >> gigabytes;
		cout << fixed << showpoint << setprecision(2);
		if (gigabytes < 8)
		{
			cout << "The total amount due is $59.99";
		}
		else
		{
			cost = 59.99 + (5 * (gigabytes - 8));
			cout << "The total amount due is $" << cost;
		}
		break;
	}
	case 'C':
	{
		cout << "The total amount due is $69.99";
		break;
	}
	case 'D':
	{
		break;
	}
	}
	return 0;
}

/*
Select a subscription package (Enter Letter of Choice):
Package A
Package B
Package C
Quit D
a
How many gigabytes were used: 3
The total amount due is $39.99
C:\Users\stone\source\repos\Assignment12\Debug\Assignment12.exe (process 30588) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

______________________________________________________________________
Select a subscription package (Enter Letter of Choice):
Package A
Package B
Package C
Quit D
a
How many gigabytes were used: 6
The total amount due is $59.99
C:\Users\stone\source\repos\Assignment12\Debug\Assignment12.exe (process 35616) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

_______________________________________________________________________
Select a subscription package (Enter Letter of Choice):
Package A
Package B
Package C
Quit D
b
How many gigabytes were used: 8
The total amount due is $59.99
C:\Users\stone\source\repos\Assignment12\Debug\Assignment12.exe (process 12004) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

______________________________________________________________________
Select a subscription package (Enter Letter of Choice):
Package A
Package B
Package C
Quit D
b
How many gigabytes were used: 9
The total amount due is $64.99
C:\Users\stone\source\repos\Assignment12\Debug\Assignment12.exe (process 28892) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

_____________________________________________________________________
Select a subscription package (Enter Letter of Choice):
Package A
Package B
Package C
Quit D
c
The total amount due is $69.99
C:\Users\stone\source\repos\Assignment12\Debug\Assignment12.exe (process 29996) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/