//***************************************************************
//
//		Assignment:		#5
// 
//		File:			RussAssignement5.cpp
// 
//		Due Date:		September 9, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Asks user for 3 or 4 digit number and 
//						outputs the floor number and room number
//
//
//***************************************************************

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int userNum;
	int floorNum;
	int roomNum;

	cout << "Enter a 3 or 4 digit number" << endl;
	cin >> userNum;
	
	floorNum = userNum / 100;
	roomNum = userNum % 100;

	cout << "The floor number is " << floorNum <<
		"\nand the room number is " << roomNum << endl;

	return 0;


}


/*
Enter a 3 or 4 digit number
312
The floor number is 3
and the room number is 12

C:\Users\stone\source\repos\Assignment5\Debug\Assignment5.exe (process 13396) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

////////////////////////////////////////

Enter a 3 or 4 digit number
4156
The floor number is 41
and the room number is 56

C:\Users\stone\source\repos\Assignment5\Debug\Assignment5.exe (process 12112) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

////////////////////////////////////////

Enter a 3 or 4 digit number
910
The floor number is 9
and the room number is 10

C:\Users\stone\source\repos\Assignment5\Debug\Assignment5.exe (process 16668) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/