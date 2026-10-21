//*******************************************************************************************************
//
//		File:					PigLatin.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #5
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 5
//
//		Due:					2/20/23
//
//
//		This program converts english to "Pig Latin" (Uses C-Strings).
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

//*******************************************************************************************************

void convertToUpper(char*);
void findAndRemove(char*);
void appendAy(char*);
void reverse(char*);
void convertPigLatin(char*, int);

//*******************************************************************************************************

int main()
{
	const int SIZE = 181;
	char* ptr = new char[SIZE];
	convertPigLatin(ptr, SIZE);
}

//*******************************************************************************************************

void convertToUpper(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = toupper(str[i]);
	}
}

//*******************************************************************************************************

void findAndRemove(char* str)
{
	char *ptr = strstr(str, "IG");
	if (ptr)
	{
		*ptr = '\0';
	}
}

//*******************************************************************************************************

void appendAy(char* str)
{
	const char *pigLatin = "ay";
	int t = sizeof(str);
	strcat_s(str, sizeof(str) * strlen(str), pigLatin);
}

//*******************************************************************************************************

void reverse(char* str)
{
 	for (int i = 0; i < strlen(str) / 2; ++i)
	{
		swap(str[i], str[strlen(str) - i - 1]);
	}
}

//*******************************************************************************************************

void convertPigLatin(char* str, int size)
{
	bool cont = false;
	do 
	{
		cout << "Enter a string, enter quit to stop the process" << endl;
		cin.getline(str, strlen(str));
		convertToUpper(str);
		cont = strcmp(str, "QUIT");
		if (cont)
		{
			findAndRemove(str);
			appendAy(str);
			reverse(str);
			cout << str << strlen(str) << endl;
		}
		delete[] str;
		str = new char[size];
	} while (cont);
}

/*
Enter a string, enter quit to stop the process
night
yaN3
Enter a string, enter quit to stop the process
no ig here
ya ON5
Enter a string, enter quit to stop the process
no i-g here
yaEREH G-I ON13
Enter a string, enter quit to stop the process
over
yaREVO6
Enter a string, enter quit to stop the process
quit

C:\Users\stone\source\repos\RussPigLatin\Debug\RussPigLatin.exe (process 38036) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/