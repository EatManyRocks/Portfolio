//***************************************************************
//
//		Assignment:		#2
// 
//		File:			RussellAssignment2.cpp
// 
//		Due Date:		September 2, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	This program finds the sum, difference,
//						product, and quotient of the integers
//						7 and 2.
//
//
//***************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int numOne = 2;
	int numTwo = 7;
	int sum = 0;
	int product = 0;
	int difference = 0;
	double quotient = 0;

	sum = numTwo + numOne;
	cout << "The sum of " << numTwo << " and "
		<< numOne << " equals " << sum << endl;

	difference = numTwo - numOne;
	cout << "The difference of " << numTwo << " and "
		<< numOne << " equals " << difference << endl;

	product = numTwo * numOne;
	cout << "The product of " << numTwo << " and "
		<< numOne << " equals " << product << endl;

	cout << fixed << showpoint << setprecision(2);
	quotient = static_cast<double>(numTwo)/numOne;
	cout << "The quotient of " << numTwo << " and "
		<< numOne << " equals " << quotient << endl;

	return 0;
}

/*
The sum of 7 and 2 equals 9
The difference of 7 and 2 equals 5
The product of 7 and 2 equals 14
The quotient of 7 and 2 equals 3.50

C:\Users\stone\source\repos\RussellAssignment2\Debug\RussellAssignment2.exe (process 648) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/