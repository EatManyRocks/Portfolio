//***************************************************************
//
//		Assignment:		#21
// 
//		File:			RussAssignment21.cpp
// 
//		Due Date:		December 9, 2022
//
//		Author:			Ryan Russell
//
//
//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	2 dimensional array with 3 students,
//						each student has 4 test scores.
//
//
//***************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void getTests();
void totalTests();
void averageTest();
void averageEachTest();
void averageEachStudent();
void getHighest();
void getHighestOfEachTest();
void getLowestOfEachStudent();
void report();
void pause();

//******************************************************************************************

double tests[3][4];

//******************************************************************************************

int main()
{
	getTests();

	report();

	return 0;
}

//******************************************************************************************

void getTests()
{
    ifstream fin;
    fin.open("test.txt");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fin >> tests[i][j];

        }

    }
    fin.close();
}

//******************************************************************************************

void totalTests()
{
    double total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += tests[i][j];
        }
    }
    cout << "Total of all tests is: " << total << endl;
    pause();
}

//******************************************************************************************

void averageTest()
{
    double total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += tests[i][j];
        }
    }
    cout << "Average of all tests is: " << (total/12) << endl;
    pause();
}

//******************************************************************************************

void averageEachTest()
{
    for (int i = 0; i < 4; i++)
    {
        double total = 0;
        for (int j = 0; j < 3; j++)
        {
            total += tests[j][i];
        }
        cout << "Average for Test # " << i + 1 << ": " << (total / 3) << endl;
    }
    pause();
}

//******************************************************************************************

void averageEachStudent()
{
    for (int i = 0; i < 3; i++)
    {
        double total = 0;
        for (int j = 0; j < 4; j++)
        {
            total += tests[i][j];
        }
        cout << "Average for Student # " << i + 1 << ": " << (total / 4) << endl;
    }
    pause();
}

//******************************************************************************************

void getHighest()
{
    double highest = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (highest < tests[i][j])
            {
                highest = tests[i][j];
            }
        }
    }
    cout << "The highest test score is " << highest << endl;
    pause();
}

//******************************************************************************************

void getHighestOfEachTest()
{
    for (int i = 0; i < 4; i++)
    {
        int highest = 0;
        for (int j = 0; j < 3; j++)
        {
            if (highest < tests[j][i])
            {
                highest = tests[j][i];
            }
        }
        cout << "Highest test of Student # " << i + 1 << ": " << highest << endl;
    }
    pause();
}

//******************************************************************************************

void getLowestOfEachStudent()
{
    for (int i = 0; i < 3; i++)
    {
        int lowest = tests[i][0];
        for (int j = 0; j < 4; j++)
        {
            if (lowest > tests[i][j])
            {
                lowest = tests[i][j];
            }
        }
        cout << "Lowest test of Student # " << i + 1 << ": " << lowest << endl;
    }
    pause();
}

//******************************************************************************************

void report()
{
    totalTests();
    averageTest();
    averageEachTest();
    averageEachStudent();
    getHighest();
    getHighestOfEachTest();
    getLowestOfEachStudent();
}

//******************************************************************************************

void pause()
{
    cout << "Press Enter to Continue ";
    cin.get();
}

//******************************************************************************************

/*
Total of all tests is: 955
Press Enter to Continue
Average of all tests is: 79.5833
Press Enter to Continue
Average for Test # 1: 78.3333
Average for Test # 2: 86.6667
Average for Test # 3: 76.6667
Average for Test # 4: 76.6667
Press Enter to Continue
Average for Student # 1: 78.75
Average for Student # 2: 78.75
Average for Student # 3: 81.25
Press Enter to Continue
The highest test score is 90
Press Enter to Continue
Highest test of Student # 1: 85
Highest test of Student # 2: 90
Highest test of Student # 3: 90
Highest test of Student # 4: 80
Press Enter to Continue
Lowest test of Student # 1: 70
Lowest test of Student # 2: 60
Lowest test of Student # 3: 75
Press Enter to Continue

C:\Users\stone\source\repos\Assignment21\Debug\Assignment21.exe (process 27564) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/