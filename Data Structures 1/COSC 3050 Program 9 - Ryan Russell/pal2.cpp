//*****************************************************************************************************
//
//		File:					pal2.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					4/4/24
//
//
//		This program uses stacks to test palindromes recieved from palindromes.txt. 
//	
//		Other files required: 
//			1.	stack.h
//			2.	queue.h
//			3.	node.h
//			4.	palindromes.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
#include "stack.h"
#include "queue.h"

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& palStack, Queue<char>& palQueue);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main()
{
	ifstream palFile("palindromes.txt");
	char pal[80];
	Stack<char> palStack;
	Queue<char> palQueue;
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
				palStack.push(pal[i]);
				palQueue.enqueue(pal[i]);
			}
			else if (isspace(pal[i]))
				hasSpace = true;
			else if (ispunct(pal[i]))
				hasPunct = true;
		}

		isValid = testNdisplayPal(palStack, palQueue);
		palType = getPalType(hasSpace, hasPunct);
		displayPalResult(isValid, palType);
	}

	palFile.close();
	return 0;
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& palStack, Queue<char>& palQueue)
{
	bool isValid = true;
	char tempChar1;
	char tempChar2;

	while (palStack.pop(tempChar1) && (palQueue.dequeue(tempChar2)))
	{
		if (tempChar1 != tempChar2)
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