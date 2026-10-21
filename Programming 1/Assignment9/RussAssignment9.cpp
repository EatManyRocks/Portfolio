//***************************************************************
//
//		Assignment:		#9
// 
//		File:			RussAssignment9.cpp
// 
//		Due Date:		September 21, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	
//
//
//***************************************************************

#include<iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	int amountBaseballs = 0;
	int price = 0;

	cout << "Enter the amount of baseballs you'd like to purchase: ";
	cin >> amountBaseballs;

	if (amountBaseballs % 2 == 1)
	{
		price += ((amountBaseballs / 2) * 7) + 4;
	}
	else
	{
		price += (amountBaseballs / 2) * 7;
	}

	cout << "\nYour total is $" << price << ".00.";

	return 0;

}

/*
Enter the amount of baseballs you'd like to purchase: 5

Your total is $18.00.
C:\Users\stone\source\repos\Assignment9\Debug\Assignment9.exe (process 17020) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

------------------------------------------------------

Enter the amount of baseballs you'd like to purchase: 8

Your total is $28.00.
C:\Users\stone\source\repos\Assignment9\Debug\Assignment9.exe (process 11292) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

------------------------------------------------------

Enter the amount of baseballs you'd like to purchase: 91

Your total is $319.00.
C:\Users\stone\source\repos\Assignment9\Debug\Assignment9.exe (process 30632) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

------------------------------------------------------

Enter the amount of baseballs you'd like to purchase: 16

Your total is $56.00.
C:\Users\stone\source\repos\Assignment9\Debug\Assignment9.exe (process 22568) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/