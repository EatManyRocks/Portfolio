//***************************************************************
//
//		Assignment:		#20
// 
//		File:			RussAssignment20.cpp
// 
//		Due Date:		December 5, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	A program with array and functions
//						for working on a student's
//						test scores.
//
//
//***************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

//***************************************************************

void getTests( double[], int );
double toTotalTest( double[], int );
double getAverage( double, int );
double getHighest( double[], int );
double getLowest( double[], int );
void Report( int, double[], double, double, double, double );

//***************************************************************

int main()
{
	const int numTests = 4;
	double tests[numTests],
			total = 0,
			average,
			highest,
			lowest;
	getTests(tests, numTests);
	total = toTotalTest(tests, numTests);
	average = getAverage(total, numTests);
	highest = getHighest(tests, numTests);
	lowest = getLowest(tests, numTests);
	Report(numTests, tests, total, average, highest, lowest);
	return 0;
}

//**************************************************************

void getTests(double tests[], int numT)
{
	
	for (int count = 0; count < numT; count++)
	{
		cout << "Enter score for student " << count + 1 << ": ";
		cin >> tests[count];
	}
	cin.ignore();

	cout << "Press enter to continue";
	cin.get();
}

//**************************************************************

double toTotalTest(double tests[], int numT)
{
	double total = 0;
	for (int count = 0; count < numT; count++)
	{
		total += tests[count];
	}
	return total;
}

//**************************************************************

double getAverage( double total, int numT)
{
	double average = total / numT;
	return average;
}

//**************************************************************

double getHighest(double tests[], int numT)
{
	double highest = tests[0];
	for (int count = 0; count < numT; count++)
	{
		if (tests[count] > highest)
		{
			highest = tests[count];
		}
	}
	return highest;
}

//**************************************************************

double getLowest(double tests[], int numT)
{
	double lowest = tests[0];
	for (int count = 0; count < numT; count++)
	{
		if (tests[count] < lowest)
		{
			lowest = tests[count];
		}
	}
	return lowest;
}

//**************************************************************

void Report( int numT, double tests[], double total, double average, double highest, double lowest)
{
	for (int count = 0; count < numT; count++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Student score " << count + 1 << " is: " << tests[count] << endl;
	}
	cout << "Press enter to continue";
	cin.get();

	cout << "The sum total of scores is: " << total << endl;
	cout << "Press enter to continue";
	cin.get();

	cout << "The average of the scores is: " << average << endl;
	cout << "Press enter to continue";
	cin.get();

	cout << "The highest score is: " << highest << endl;
	cout << "Press enter to continue";
	cin.get();

	cout << "The lowest score is: " << lowest << endl;
	cout << "Press enter to continue";
	cin.get();
}

//**************************************************************

/*
Enter score for student 1: 65
Enter score for student 2: 90
Enter score for student 3: 80
Enter score for student 4: 78
Press enter to continue
Student score 1 is: 65.00
Student score 2 is: 90.00
Student score 3 is: 80.00
Student score 4 is: 78.00
Press enter to continue
The sum total of scores is: 313.00
Press enter to continue
The average of the scores is: 78.25
Press enter to continue
The highest score is: 90.00
Press enter to continue
The lowest score is: 65.00
Press enter to continue

C:\Users\stone\source\repos\Assignment20\Debug\Assignment20.exe (process 29160) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/