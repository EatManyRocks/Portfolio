//***************************************************************
//
//		Assignment:		#8
// 
//		File:			RussAssignment8.cpp
// 
//		Due Date:		September 21, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Promt user to enter amount of coins and then
//						adds coin value up to a dollar and cent amount
//
//
//***************************************************************


#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
	int pennies = 0;
	int nickles = 0;
	int dimes = 0;
	int quarters = 0;
	int totalValue = 0;

	cout << "This program will tell you your coin collection in dollars and cents" << endl;

	cout << "Enter the number of pennies: ";
	cin >> pennies;
	cout << "\nEnter the number of nickles: ";
	cin >> nickles;
	cout << "\nEnter the number of dimes: ";
	cin >> dimes;
	cout << "\nEnter the number of quarters: ";
	cin >> quarters;

	totalValue += pennies + (nickles * 5) + (dimes * 10) + (quarters * 25);
	int dollar = totalValue / 100;
	int cents = totalValue % 100;

	cout << "You have $" << dollar << "." << cents << endl;

	return 0;
}


/*
This program will tell you your coin collection in dollars and cents
Enter the number of pennies: 55

Enter the number of nickles: 35

Enter the number of dimes: 6

Enter the number of quarters: 12
You have $5.90

C:\Users\stone\source\repos\Assignment8\Debug\Assignment8.exe (process 18044) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

-----------------------------------------------------

This program will tell you your coin collection in dollars and cents
Enter the number of pennies: 1

Enter the number of nickles: 1

Enter the number of dimes: 1

Enter the number of quarters: 1
You have $0.41

C:\Users\stone\source\repos\Assignment8\Debug\Assignment8.exe (process 13712) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

-----------------------------------------------------

This program will tell you your coin collection in dollars and cents
Enter the number of pennies: 1

Enter the number of nickles: 5

Enter the number of dimes: 10

Enter the number of quarters: 25
You have $7.51

C:\Users\stone\source\repos\Assignment8\Debug\Assignment8.exe (process 31460) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/