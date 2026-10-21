//***********************************************************************************
//
// File: RussTwoDArray.cpp
//
// Student: Ryan Russell
//
// Assignment: Program #1
//
// Course Name: Programming II
//
// Course Number: COSC 1560-Week 1
//
// Due: Jan 23rd
//
//***********************************************************************************

#include<iomanip>
#include <iostream> 

using namespace std;

//******************************************************************************

const int COL_SIZE = 4;

//******************************************************************************

void getAllData(int[][COL_SIZE], int);
void displayAllData(int[][COL_SIZE], int);
double getAllAverage(const int[][COL_SIZE], int);
void displayRowSum(const int[][COL_SIZE], int);
void displayColSum(const int[][COL_SIZE], int);

//******************************************************************************

int main()
{
	const int ROW_SIZE = 4;
	int data[ROW_SIZE][COL_SIZE];
	double average;

	getAllData(data, ROW_SIZE);
	displayAllData(data, ROW_SIZE);
	average = getAllAverage(data, ROW_SIZE);
	cout << fixed << showpoint;
	cout << "\nThe average for all values: " << setprecision(2) << average << endl;
	displayRowSum(data, ROW_SIZE);
	displayColSum(data, ROW_SIZE);

	return 0;
}

//******************************************************************************

void getAllData(int data[][COL_SIZE], int row_size)
{
	for (int row = 0; row < row_size; row++)
	{
		cout << "Enter values for row " << 1+row << ":" << endl;
		for (int column = 0; column < COL_SIZE; column++)
		{
			cout << "value " << 1+column << ": ";
			cin >> data[row][column];
			while (data[row][column] < 0 || data[row][column] > 500)
			{
				cout << "Values cannot be less than 0 or more than 500:" << endl;
				cout << "Re-enter: ";
				cin >> data[row][column];
			}
		}
	}
}

//******************************************************************************

void displayAllData(int data[][COL_SIZE], int row_size)
{
	cout << "\nYou have entered:" << endl;
	for (int row = 0; row < row_size; row++)
	{
		for (int column = 0; column < COL_SIZE; column++)
		{
			cout << data[row][column] << setw(5);
		}
		cout << " " << endl;
	}
}

//******************************************************************************

double getAllAverage(const int data[][COL_SIZE], int row_size)
{
	double sum = 0;
	double values = COL_SIZE * row_size;
	double average;
	for (int row = 0; row < row_size; row++)
	{
		for (int column = 0; column < COL_SIZE; column++)
		{
			sum += data[row][column];
		}
	}
	average = sum / values;
	return average;
}

//******************************************************************************

void displayRowSum(const int data[][COL_SIZE], int row_size)
{
	int sum;
	cout << "\nThe sum of each row:" << endl;
	for (int row = 0; row < row_size; row++)
	{
		sum = 0;
		for (int column = 0; column < COL_SIZE; column++)
		{
			sum += data[row][column];
		}
		cout << "Sum for row " << 1+row << ": " << sum << endl;
	}
}

//******************************************************************************

void displayColSum(const int data[][COL_SIZE], int row_size)
{
	int sum = 0,
		lowest = data[0][0];

	cout << "\nThe sum of each column:" << endl;
	for (int column = 0; column < COL_SIZE; column++)
	{
		sum = 0;
		for (int row = 0; row < row_size; row++)
		{
			sum += data[row][column];
			if (data[row][column] < lowest)
				lowest = data[row][column];
		}
		cout << "Sum for column " << 1 + column << ": " << sum << endl;
	}
	cout << "\nLowest of all values is: " << lowest;
}

/*
Enter values for row 1:
value 1: 105
value 2: 156
value 3: 142
value 4: 143
Enter values for row 2:
value 1: 201
value 2: 213
value 3: 212
value 4: 244
Enter values for row 3:
value 1: 98
value 2: 82
value 3: 92
value 4: 97
Enter values for row 4:
value 1: 10
value 2: 13
value 3: 15
value 4: 19

You have entered:
105  156  142  143
201  213  212  244
98   82   92   97
10   13   15   19

The average for all values: 115.12

The sum of each row:
Sum for row 1: 546
Sum for row 2: 870
Sum for row 3: 369
Sum for row 4: 57

The sum of each column:
Sum for column 1: 414
Sum for column 2: 464
Sum for column 3: 461
Sum for column 4: 503

Lowest of all values is: 10
C:\Users\stone\source\repos\TwoDArray\Debug\TwoDArray.exe (process 15560) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/