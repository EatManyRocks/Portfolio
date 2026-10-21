//*******************************************************************************************************
//
//		File:					PopulationAnalysis.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #4
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 4
//
//		Due:					2/10/23
//
//
//		This program conducts a statistical analysis over populations in major cities using pointer functions.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

//*******************************************************************************************************

long* getData(int);
long getAverage(const long*, int);
void displayForward(const long*, int);
long getMax(const long*, int);
void displayBackward(const long*, int);
void bubbleSort(long*, int);

//*******************************************************************************************************

int main()
{
	const int SIZE = 16;
	long population[SIZE];
	long* ptr = population;

	ptr = getData(SIZE);

	displayForward(ptr, SIZE);
	displayBackward(ptr, SIZE);

	long avg = getAverage(ptr, SIZE);
	cout << "\nAverage is: " << avg << endl;

	long max = getMax(ptr, SIZE);
	cout << "Max is: " << max << endl;

	bubbleSort(ptr, SIZE);

	displayForward(ptr, SIZE);
	displayBackward(ptr, SIZE);

	delete[] ptr;
	ptr = nullptr;
}

//*******************************************************************************************************

long* getData(int size)
{
	long* ptr = new long[size];

	cout << "Please enter the population of the 16 cities: " << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> ptr[i];
		while (ptr[i] <= 0)
		{
			cout << "\n!!! Population can't be <= 0 !!!" << endl;;
			cin >> ptr[i];
		}
	}
	return ptr;
}

//*******************************************************************************************************

long getAverage(const long* ptr, int size)
{
	long double average;
	long double sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(ptr);

		ptr++;
	}
	average = sum / size;

	return long(average);
}

//*******************************************************************************************************

void displayForward(const long* ptr, int size)
{
	cout << "\nDisplay forward: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << left << setw(10) << *(ptr + i);
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}

//*******************************************************************************************************

long getMax(const long* ptr, int size)
{
	long max = *(ptr);
	for (int i = 0; i < size; i++)
	{
		if (max < *(ptr))
			max = *(ptr);
		ptr++;
	}
	return max;
}

//*******************************************************************************************************

void displayBackward(const long* ptr, int size)
{
	cout << "\nDisplay backward: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << left << setw(10) << *(ptr + ((size - 1) - i));
		if ((i + 1) % 4 == 0)
			cout << endl;
	}
}

//*******************************************************************************************************

void bubbleSort(long* ptr, int size)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (*(ptr + j) < *(ptr + i))
			{
				temp = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = temp;
			}
		}
	}
}

/*
Please enter the population of the 16 cities:
860090
2704958
855164
264488
672795
481420
446970
595047
298800
413651
388072
389902
311404
302398
280364
279789

Display forward:
860090    2704958   855164    264488
672795    481420    446970    595047
298800    413651    388072    389902
311404    302398    280364    279789

Display backward:
279789    280364    302398    311404
389902    388072    413651    298800
595047    446970    481420    672795
264488    855164    2704958   860090

Average is: 596582
Max is: 2704958

Display forward:
264488    279789    280364    298800
302398    311404    388072    389902
413651    446970    481420    595047
672795    855164    860090    2704958

Display backward:
2704958   860090    855164    672795
595047    481420    446970    413651
389902    388072    311404    302398
298800    280364    279789    264488

C:\Users\stone\source\repos\PopulationAnalysis\Debug\PopulationAnalysis.exe (process 31764) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/