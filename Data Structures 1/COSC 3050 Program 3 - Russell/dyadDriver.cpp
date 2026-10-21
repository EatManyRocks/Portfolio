//*****************************************************************************************************
//
//		File:					dyadDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/11/24
//
//
//		This program is the driver that proves the correctness of the Dyad class template and classes
//		by insantiating three Dyad classes holding 2 values of int, double, and char respectively.
//		Then uses getFirst, getSecond, swapValues, and get2Values functions for each Dyad.
//	
//		Other files required: 
//			1.	dyad.h
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "dyad.h"

//*****************************************************************************************************

int main()
{
	Dyad<int> numDyad(1, 2);
	Dyad<double> doubleDyad(3.4, 5.6);
	Dyad<char> charDyad('a', 'b');

	int num1,
		num2;
	double dNum1,
		   dNum2;
	char character1,
		 character2;

	//int
	num1 = numDyad.getFirst();

	num2 = numDyad.getSecond();

	cout << "1st value: " << num1 << endl;
	cout << "2nd value: " << num2 << endl;

	numDyad.swapValues();

	numDyad.get2Values(num1, num2);

	cout << "1st value: " << num1 << endl;

	cout << "2nd value: " << num2 << endl;

	//double
	dNum1 = doubleDyad.getFirst();

	dNum2 = doubleDyad.getSecond();

	cout << "1st value: " << dNum1 << endl;
	cout << "2nd value: " << dNum2 << endl;

	doubleDyad.swapValues();

	doubleDyad.get2Values(dNum1, dNum2);

	cout << "1st value: " << dNum1 << endl;

	cout << "2nd value: " << dNum2 << endl;

	//char
	character1 = charDyad.getFirst();

	character2 = charDyad.getSecond();

	cout << "1st value: " << character1 << endl;
	cout << "2nd value: " << character2 << endl;

	charDyad.swapValues();

	charDyad.get2Values(character1, character2);

	cout << "1st value: " << character1 << endl;

	cout << "2nd value: " << character2 << endl;

	return 0;
}

//*****************************************************************************************************

/*

1st value: 1
2nd value: 2
1st value: 2
2nd value: 1
1st value: 3.4
2nd value: 5.6
1st value: 5.6
2nd value: 3.4
1st value: a
2nd value: b
1st value: b
2nd value: a

*/