//***************************************************************
//
//		Assignment:		#15
// 
//		File:			RussAssignment15.cpp
// 
//		Due Date:		October 28, 2022
//
//		Author:			Ryan Russell
//
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
using namespace std;
int main()
{
	int emplNum = -1;
	double emplGrossPay = 0;
	double emplWithholding = 0;
	double totalGrossPay = 0;
	double totalWithholding = 0;
	double totalNet = 0;

	do
	{
		cout << "\nEnter employee number (0 to quit): ";
		cin >> emplNum;
		while (emplNum <= -1)
		{
			cout << "Please enter a postitive number\nEnter again (0 to quit): ";
			cin >> emplNum;
		}
		if (emplNum != 0)
		{
			cout << "Enter gross pay: ";
			cin >> emplGrossPay;
			while (emplGrossPay <= 0)
			{
				cout << "Please enter a number that greater than 0\nEnter again (0 to quit): ";
				cin >> emplGrossPay;
			}

			cout << "Enter withholdings: ";
			cin >> emplWithholding;
			while (emplWithholding > emplGrossPay || emplWithholding <= 0)
			{
				if (emplWithholding <= 0)
				{
					cout << "Please enter a number that greater than 0\nEnter again: ";
					cin >> emplWithholding;
				}
				if (emplWithholding > emplGrossPay)
				{
					cout << "Withholding cannot be greater that gross\nEnter again: ";
					cin >> emplWithholding;
				}
			}
			totalGrossPay += emplGrossPay;
			totalWithholding += emplWithholding;
		}
	}
	while (emplNum != 0);

	totalNet = (totalGrossPay - totalWithholding);
	cout << fixed << setprecision(2);
	cout << "\n\n" << left << setw(20) << "Total Gross Pay:" << right << setw(7) << "$" << totalGrossPay << endl;
	cout << left << setw(20) << "Total Withholding:" << right << setw(7) << "$" << totalWithholding << endl;
	cout << left << setw(20) << "Total Net:" << right << setw(7) <<  "$" << totalNet << endl;
	return 0;
}

/*

Enter employee number (0 to quit): -1
Please enter a postitive number
Enter again (0 to quit): 1
Enter gross pay: 1500
Enter withholdings: 100

Enter employee number (0 to quit): 2
Enter gross pay: -14
Please enter a number that greater than 0
Enter again (0 to quit): 1000
Enter withholdings: -14
Please enter a number that greater than 0
Enter again: 1500
Withholding cannot be greater that gross
Enter again: 50

Enter employee number (0 to quit): 3
Enter gross pay: 500
Enter withholdings: 25

Enter employee number (0 to quit): 4
Enter gross pay: 250
Enter withholdings: 5

Enter employee number (0 to quit): 0


Total Gross Pay:          $3250.00
Total Withholding:        $180.00
Total Net:                $3070.00

C:\Users\stone\source\repos\Assignment15\Debug\Assignment15.exe (process 39952) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/