//*****************************************************************************************************
//
//		File:					pal1.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					3/29/24
//
//
//		This program uses stacks to test palindromes recieved from palindromes.txt. 
//	
//		Other files required: 
//			1.	stack.h
//			2.	palindromes.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void fillStack3(Stack<char>& palStack2, Stack<char>& palStack3);
bool testNdisplayPal(Stack<char>& palStack1, Stack<char>& palStack3);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main()
{
	ifstream palFile("palindromes.txt");
	char pal[80];
	Stack<char> palStack1,
				palStack2,
				palStack3;
	bool hasSpace,
		 hasPunct,
		 isValid;
	int len;
	int palType;

	while (palFile.getline(pal, 80, '#'))
	{
		hasSpace = false;
		hasPunct = false;
		len = int(strlen(pal));

		for (int i = 0; i < len; i++)
		{
			if (isalpha(pal[i]))
			{
				pal[i] = tolower(pal[i]);
				palStack1.push(pal[i]);
				palStack2.push(pal[i]);
			}
			else if (isspace(pal[i]))
				hasSpace = true;
			else if (ispunct(pal[i]))
				hasPunct = true;
		}

		fillStack3(palStack2, palStack3);
		isValid = testNdisplayPal(palStack1, palStack3);
		palType = getPalType(hasSpace, hasPunct);
		displayPalResult(isValid, palType);
	}

	palFile.close();
	return 0;
}

//*****************************************************************************************************

void fillStack3(Stack<char>& palStack2, Stack<char>& palStack3)
{
	char tempChar;

	while (palStack2.pop(tempChar))
		palStack3.push(tempChar);
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& palStack1, Stack<char>& palStack3)
{
	bool isValid = true;
	char tempChar1;
	char tempChar3;

	while (palStack1.pop(tempChar1) && (palStack3.pop(tempChar3)))
	{
		if (tempChar1 != tempChar3)
			isValid = false;

		cout << tempChar1;
	}

	cout << "\t\t";

	return isValid;
}

//*****************************************************************************************************

char getPalType(bool hasSpace, bool hasPunct)
{
	char palType = '1';

	if (hasPunct)
		palType = '3';
	else if (hasSpace)
		palType = '2';

	return palType;
}

//*****************************************************************************************************

void displayPalResult(bool isValid, char palType)
{
	if (isValid)
		cout << "palType " << palType << endl;
	else
		cout << "Invalid" << endl;
}

//*****************************************************************************************************

/*
aha             palType 3
isitiitisi              palType 3
deed            palType 1
srotor          Invalid
neveroddoreven          palType 2
nolemonsnomelon         palType 3
racecar         palType 2
cimoc           Invalid
wasitacaroracatisaw             palType 3
yddad           Invalid
*/