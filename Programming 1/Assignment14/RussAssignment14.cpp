//***************************************************************
//
//		Assignment:		#14
// 
//		File:			RussAssignment14.cpp
// 
//		Due Date:		October 14, 2022
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

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;
int main()
{
	int choice = 0;
	const int MAXRANGE = 50;
	int randomnum1;
	int randomnum2;
	double total = 0;
	double answer = 0;
	do
	{
		cout << "Enter 1 for addition \n";
		cout << "Enter 2 for subtraction\n";
		cout << "Enter 3 for multiplication\n";
		cout << "Enter 4 for division\n";
		cout << "Enter 5 to quit\n";
		cin >> choice;
		while (choice < 1 || choice > 5)
		{
			cout << "Choice must be 1, 2, 3, 4, or 5\n";
			cout << "Enter choice again\n";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			randomnum1 = 1 + rand() % MAXRANGE;
			randomnum2 = 1 + rand() % MAXRANGE;
			cout << randomnum1 << " + " << randomnum2 << " = ";
			cin >> answer;
			total = randomnum1 + randomnum2;
			if (answer == total)
			{
				cout << "That answer is correct!\n";
			}
			else
			{
				cout << "That answer is incorrect.\n";
			}
			break;
		}
		case 2:
		{
			randomnum1 = 1 + rand() % MAXRANGE;
			randomnum2 = 1 + rand() % MAXRANGE;
			cout << randomnum1 << " - " << randomnum2 << " = ";
			cin >> answer;
			total = randomnum1 - randomnum2;
			if (answer == total)
			{
				cout << "That answer is correct!\n";
			}
			else
			{
				cout << "That answer is incorrect. The real answer is " << total << ".\n";
			}
			break;
		}
		case 3:
		{
			randomnum1 = 1 + rand() % MAXRANGE;
			randomnum2 = 1 + rand() % MAXRANGE;
			cout << randomnum1 << " * " << randomnum2 << " = ";
			cin >> answer;
			total = randomnum1 * randomnum2;
			if (answer == total)
			{
				cout << "That answer is correct!\n";
			}
			else
			{
				cout << "That answer is incorrect. The real answer is " << total << ".\n";
			}
			break;
		}
		case 4:
		{
			randomnum1 = 1 + rand() % MAXRANGE;
			randomnum2 = 1 + rand() % MAXRANGE;
			cout << randomnum1 << " / " << randomnum2 << " = ";
			cin >> answer;
			total = static_cast<double>(randomnum1) / (randomnum2);
			double realDecimalAns = (int)(total * 100 + 0.5);
			total = double(realDecimalAns) / 100;
			if (answer == total)
			{
				cout << "That answer is correct!\n";
			}
			else
			{
				cout << "That answer is incorrect. The real answer is " << total << ".\n";
			}
			break;
		}
		case 5:
		{
			cout << "Quitting program...";
			break;
		}
		default:
		{
			cout << "You must enter 1, 2, 3, 4, or 5.\n";
			break;
		}
		}
	}
	while (choice != 5);
	return 0;
}

/*
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
1
42 + 18 = 1
That answer is incorrect.
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
1
35 + 1 = 36
That answer is correct!
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
2
20 - 25 = -5
That answer is correct!
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
3
29 * 9 = 261
That answer is correct!
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
4
13 / 15 = 0.87
That answer is correct!
Enter 1 for addition
Enter 2 for subtraction
Enter 3 for multiplication
Enter 4 for division
Enter 5 to quit
5
Quitting program...
C:\Users\stone\source\repos\Assignment14\Debug\Assignment14.exe (process 27744) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/