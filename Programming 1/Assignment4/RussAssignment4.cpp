//***************************************************************
//
//		Assignment:		#4
// 
//		File:			RussAssignment4.cpp
// 
//		Due Date:		September 9, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Computes miles per gallon from user
//						input
//
//
//***************************************************************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double miles;
	double gallons;
	double mpg;

	cout << "How many miles were driven?\n";
	cin >> miles;

	cout << "How many gallons of gas were used?\n";
	cin >> gallons;

	cout << fixed << showpoint << setprecision(2);
	mpg = static_cast<double>(miles) / gallons;

	cout << "\nThe miles per gallon is " << mpg << endl;

}

/*
How many miles were driven?
100
How many gallons of gas were used?
6

The miles per gallon is 16.67

C:\Users\stone\source\repos\Assignment4\Debug\Assignment4.exe (process 2652) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

//////////////////////////////////////////////////////

How many miles were driven?
350
How many gallons of gas were used?
12

The miles per gallon is 29.17

C:\Users\stone\source\repos\Assignment4\Debug\Assignment4.exe (process 33712) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/