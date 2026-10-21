//*****************************************************************************************************
//
//		File:					max.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #2
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/5/24
//
//
//		This program asks for users input, finds the max of those inputs, 
//		and then prints out the inputs and max.
//		These tasks are done using functions with prototypes and templates. 
//	
//		Other files required: 
//			1.	none
//			
//*****************************************************************************************************

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

//*****************************************************************************************************

template <typename TYPE>
void getData(TYPE& input1, TYPE& input2);
void getData(char input1[], char input2[]);

template <typename TYPE>
TYPE findMax(TYPE& input1, TYPE& input2);
char *findMax(char input1[], char input2[]);

template <typename TYPE>
void displayMax(TYPE input1, TYPE input2, TYPE max);

//*****************************************************************************************************

int main()
{
	int aInt, 
		bInt,
		maxInt;
	double aDouble,
		   bDouble,
		   maxDouble;
	char aChar,
		 bChar,
		 maxChar;
	char aArray[80],
		 bArray[80];
		 
	char* maxArray;

	getData(aInt, bInt);
	getData(aDouble, bDouble);
	getData(aChar, bChar);
	getData(aArray, bArray);

	maxInt = findMax(aInt, bInt);
	maxDouble = findMax(aDouble, bDouble);
	maxChar = findMax(aChar, bChar);
	maxArray = findMax(aArray, bArray);

	displayMax(aInt, bInt, maxInt);
	displayMax(aDouble, bDouble, maxDouble);
	displayMax(aChar, bChar, maxChar);
	displayMax(aArray, bArray, maxArray);
}

//*****************************************************************************************************

template <typename TYPE>
void getData(TYPE& input1, TYPE& input2)
{
	cout << "Enter first " << typeid(input1).name() << ": ";
	cin >> input1;

	cout << "Enter second " << typeid(input1).name() << ": ";
	cin >> input2;
}

//*****************************************************************************************************

void getData(char input1[],char input2[])
{
	cin.ignore();

	cout << "Enter first string: ";
	cin.getline(input1, 80);

	cout << "Enter second string: ";
	cin.getline(input2, 80);
}

//*****************************************************************************************************

template <typename TYPE>
TYPE findMax(TYPE& input1, TYPE& input2)
{
	TYPE max;

	if (input1 > input2)
	{
		max = input1;
	}
	else
	{
		max = input2;
	}

	return max;
}

//*****************************************************************************************************

char* findMax(char input1[], char input2[])
{
	char* max;

	if (strcmp(input1, input2) > 0)
	{
		max = input1;
	}
	else
	{
		max = input2;
	}
	
	return max;
}

//*****************************************************************************************************

template <typename TYPE>
void displayMax(TYPE input1, TYPE input2, TYPE max)
{
	cout << "The max of " << input1 << " and " << input2 << " is " << max << endl;
}

//*****************************************************************************************************
/*
Enter first int: 75
Enter second int: 6
Enter first double: 89.36
Enter second double: 123.4
Enter first char: z
Enter second char: a
Enter first string: apple pie
Enter second string: apple dumpling
The max of 75 and 6 is 75
The max of 89.36 and 123.4 is 123.4
The max of z and a is z
The max of apple pie and apple dumpling is apple pie
*/