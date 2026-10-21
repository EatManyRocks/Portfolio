//***************************************************************
//
//		Assignment:		#11
// 
//		File:			RussAssignment11.cpp
// 
//		Due Date:		September 26, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Asks user for gender and age and 
//						finds how much the requestor is elligble
//						in social benefit.
//
//
//***************************************************************

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int age = 0;
	char gender;

	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter you gender (M/F): ";
	cin >> gender;
	gender = toupper(gender);

	if (gender != 'M' && gender != 'F')
	{
		cout << "Enter a valid gender option (M/F):";
		cin >> gender;
	}

	if (gender == 'M')
	{
		if (age >= 65)
		{
			cout << "Your benefit is $100.00 per month";
		}
		else
		{
			cout << "Your benefit is $0 per month - must be 65 years of age";

		}
	}
	else if (gender == 'F')
	{
		if (age >= 60)
		{
			cout << "Your benefit is $180.00 per month";
		}
		else
		{
			cout << "Your benefit is $0 per month - must be 60 years of age";
		}
	}
	else
	{

	}
	return 0;
}

/*
Enter your age: 55
Enter you gender (M/F): m
Your benefit is $0 per month - must be 65 years of age
C:\Users\stone\source\repos\Assignment11\Debug\Assignment11.exe (process 2844) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

-------------------------------------------------------
Enter your age: 68
Enter you gender (M/F): m
Your benefit is $100.00 per month
C:\Users\stone\source\repos\Assignment11\Debug\Assignment11.exe (process 4600) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

---------------------------------------------------------
Enter your age: 45
Enter you gender (M/F): f
Your benefit is $0 per month - must be 60 years of age
C:\Users\stone\source\repos\Assignment11\Debug\Assignment11.exe (process 23528) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

-------------------------------------------------------
Enter your age: 62
Enter you gender (M/F): f
Your benefit is $180.00 per month
C:\Users\stone\source\repos\Assignment11\Debug\Assignment11.exe (process 11340) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/