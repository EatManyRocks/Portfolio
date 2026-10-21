//***************************************************************
//
//		Assignment:		#13
// 
//		File:			RussAssignment13.cpp
// 
//		Due Date:		October 7, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Uses a while loop to let user enter numbers
//						and then after entering -99, the sentinel value,
//						it will produce the largest and smallest value
//
//
//***************************************************************

#include<iostream>

using namespace std;
int main()
{
	int largest = 0;
	int smallest;
	int numHolder = 0;

	cout << "Enter a whole number (-99 to quit): ";
	cin >> numHolder;
	largest = numHolder;
	smallest = numHolder;
	while (numHolder != -99)
	{
		cout << "Enter another whole number (-99 to quit): ";
		cin >> numHolder;

		if (numHolder != -99)
		{
			if (numHolder > largest)
			{
				largest = numHolder;
			}
			if (numHolder < smallest)
			{
				smallest = numHolder;
			}
		}
	}
	cout << "\nThe greatest number you entered is " << largest << endl;
	cout << "The smallest number you entered is " << smallest;
	return 0;
}

/*
Enter a whole number (-99 to quit): 50
Enter another whole number (-99 to quit): 60
Enter another whole number (-99 to quit): 70
Enter another whole number (-99 to quit): 3
Enter another whole number (-99 to quit): 5
Enter another whole number (-99 to quit): 100
Enter another whole number (-99 to quit): -99

The greatest number you entered is 100
The smallest number you entered is 3
C:\Users\stone\source\repos\Assignment13\Debug\Assignment13.exe (process 10296) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/