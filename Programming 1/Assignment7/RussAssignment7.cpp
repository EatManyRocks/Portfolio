//***************************************************************
//
//		Assignment:		#7
// 
//		File:			RussAssignment7.cpp
// 
//		Due Date:		September 19, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Asks user for the month, year and amount of money collected
//						and then finds the sales and tax values
//
//
//***************************************************************

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
	char month[20];
	char year[5];
	double amountCollected;
	double sales;
	double stateTax;
	double countryTax;

	cout << "Enter the month:";
	cin >> month;

	cout << "Enter the year:";
	cin >> year;

	cout << "Enter the amount collected:";
	cin >> amountCollected;

	sales = amountCollected / 1.06;
	stateTax = sales * 0.04;
	countryTax = sales * 0.02;


	cout << "\nMonth: " << month << endl;
	cout << "Year:  " << year << endl;
	cout << "	-----------------------" << endl;
	cout << left << setw(20) << "	Total Collected:" <<right << setw(4) << "$ " <<  amountCollected << endl;
	cout << left << setw(20) << "	Sales:" <<right << setw(4) << "$ " << sales << endl;
	cout << left << setw(20) << "	Country Sales Tax:" <<right << setw(4) << "$ " << countryTax << endl;
	cout << left << setw(20) << "	State Sales Tax:" <<right << setw(4) << "$ " << stateTax << endl;
	cout << left << setw(20) << "	Total Sales Tax:" <<right << setw(4) << "$ " <<  stateTax + countryTax << endl;

	return 0;

}

/*

Enter the month:September
Enter the year:2022
Enter the amount collected:26572.89

Month: September
Year:  2022
		-----------------------
		Total Collected:     $ 26572.9
		Sales:               $ 25068.8
		Country Sales Tax:   $ 501.375
		State Sales Tax:     $ 1002.75
		Total Sales Tax:     $ 1504.13

C:\Users\stone\source\repos\Assignment7\Debug\Assignment7.exe (process 2052) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/