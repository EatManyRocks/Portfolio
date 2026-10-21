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
using namespace std;

int main()
{

	double numOne = 2;
	double numTwo = 7;

	double sum = numTwo + numOne;
	cout << "The sum of " << numTwo << " and "
		<< numOne << " equals " << sum << endl;

	double difference = numTwo - numOne;
	cout << "The difference of " << numTwo << " and "
		<< numOne << " equals " << difference << endl;

	double product = numTwo * numOne;
	cout << "The product of " << numTwo << " and "
		<< numOne << " equals " << product << endl;

	double quotient = numTwo / numOne;
	cout << "The quotient of " << numTwo << " and "
		<< numOne << " equals " << quotient << endl;

	return 0;
}
