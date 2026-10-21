//*******************************************************************************************************
//
//		File:					QuizGrades2.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #3
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 3
//
//		Due:					2/6/23
//
//
//		This program calculates the user's final grades based on 10 quizzes using an array, pointers, and functions.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

//*******************************************************************************************************

const int MAXGRADE = 100;
const int MINGRADE = 0;

//*******************************************************************************************************

void getAllData(int, int*);
void displayAllValue(int, const int*);
double getAverage(int, const int*);
void bubbleSort(int* const, const int);

//*******************************************************************************************************

int main()


{
	const int SIZE = 10;
	int quizzes[SIZE];
	int* ptr = quizzes;

	getAllData(SIZE, ptr);
	displayAllValue(SIZE, ptr);
	double average = getAverage(SIZE, ptr);
	cout << "\nAverage is: " << fixed << setprecision(2) << average;
	bubbleSort(ptr, SIZE);
	cout << "\n\nAfter sort:";
	displayAllValue(SIZE, ptr);

	return 0;
}

//*******************************************************************************************************

void getAllData(int size, int* p)
{
	cout << "Please enter your quiz grades: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Quiz " << i + 1 << ": ";

		cin >> p[i];

		while (p[i] < MINGRADE || p[i] > MAXGRADE)
		{
			cout << "\n!!!Grades cannot be less than 0 or more than 100";
			cout << "\nQuiz " << i + 1 << ": ";

			cin >> p[i];
		}
	}
}

//*******************************************************************************************************

void displayAllValue(int size, const int* p)
{
	cout << "\nDisplay all values: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << left << setw(8) << *(p + i);
		if (i == 4)
			cout << "\n";
	}
}

//*******************************************************************************************************

double getAverage(int size, const int* p)
{
	double average = 0;
	double sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(p);

		p++;
	}
	average = sum / size;

	return average;
}

//*******************************************************************************************************

void bubbleSort(int* const p, const int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(p + j) < *(p + i))
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}

/*
Please enter your quiz grades:
Quiz 1: 90
Quiz 2: -9

!!!Grades cannot be less than 0 or more than 100
Quiz 2: 91
Quiz 3: 89
Quiz 4: 105

!!!Grades cannot be less than 0 or more than 100
Quiz 4: 85
Quiz 5: 78
Quiz 6: 65
Quiz 7: 64
Quiz 8: 92
Quiz 9: 75
Quiz 10: 49

Display all values:
90      91      89      85      78
65      64      92      75      49
Average is: 77.80

After sort:
Display all values:
49      64      65      75      78
85      89      90      91      92
C:\Users\stone\source\repos\RussQuizGrades2\Debug\RussQuizGrades2.exe (process 37692) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/