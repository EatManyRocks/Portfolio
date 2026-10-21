//***************************************************************
//
//		Assignment:		#3
// 
//		File:			RussellAssignment3.cpp
// 
//		Due Date:		September 9, 2022
//
//		Author:		Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Displays the memory bytes on your computer
//						for char, int, and double
//
//
//***************************************************************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	char letter;
	int num;
	double dNum;

	cout << "The number of bytes in a char is " << sizeof(letter) << endl;
	cout << "The number of bytes in a num is " << sizeof(num) << endl;
	cout << "The number of bytes in a double is " << sizeof(dNum) << endl;

	return 0;

}

/*
The number of bytes in a char is 1
The number of bytes in a num is 4
The number of bytes in a double is 8

C:\Users\stone\source\repos\RussAssignment3\Debug\RussAssignment3.exe (process 34568) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/