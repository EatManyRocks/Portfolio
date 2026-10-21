//*******************************************************************************************************
//
//		File:					QuizGrades.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #2
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 2
//
//		Due:					1/30/23
//
//
//		This program calculates the user's final grades based on 10 quizzes using an array and pointers.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

//*******************************************************************************************************

void enterData(int, int*);
void displayData(int, const int*);
void displayAverage(int [], int, const int*);

//*******************************************************************************************************

int main()


{
	const int SIZE = 10;
	int quizzes[SIZE];
	int* ptr = quizzes;

	enterData(SIZE, ptr);
	displayData(SIZE, ptr);
	displayAverage(quizzes, SIZE, ptr);

	return 0;
}

//*******************************************************************************************************

void enterData(int size, int* p)
{
	cout << "Please enter your quiz grades: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Quiz " << i+1 << ": ";

		cin >> p[i];

		while (p[i] < 0 || p[i] > 100)
		{
			cout << "\n!!!Grades cannot be less than 0 or more than 100";
			cout << "\nQuiz " << i + 1 << ": ";

			cin >> p[i];
		}
	}
}

//*******************************************************************************************************

void displayData(int size, const int* p)
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

void displayAverage(int data[], int size, const int* p)
{
	double average = 0;
	double sum = 0;

	for (int i = 0; i < size; i++)
	{
		p = &data[i];

		sum += double(*p);
	}
	average = sum / size;
	
	cout << "\nAverage is: " << fixed << setprecision(2) << average;
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
C:\Users\stone\source\repos\RussAssignment2\Debug\RussAssignment2.exe (process 6836) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/