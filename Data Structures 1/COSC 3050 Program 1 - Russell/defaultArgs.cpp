//*****************************************************************************************************
//
//		File:					defaultArgs.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #1
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					1/29/24
//
//
//		This program calls a single function named displayMsg which accepts 3 to 0 arguments 
//		using default arguments.
//	
//		Other files required: 
//			1.	none
//			
//*****************************************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

//*****************************************************************************************************

void displayMsg(const char phrase[50] = "Decide. Commit. Succeed.", char symbol = ' ', int symLen = 10);

//*****************************************************************************************************

int main()
{

	displayMsg("I will decide", '*', 15);
	displayMsg("I will commit.", '+');
	displayMsg("I will succeed");
	displayMsg();

	return 0;
}

//*****************************************************************************************************

void displayMsg(const char phrase[50], char symbol, int symLen)
{
	for (int i = 0; i < symLen; i++)
	{
		cout << symbol;
	}

	cout << phrase;

	for (int i = 0; i < symLen; i++)
	{
	    cout << symbol;
	}
	cout << endl;
}

//*****************************************************************************************************
/*

***************I will decide***************
++++++++++I will commit.++++++++++
          I will succeed          
		  Decide.Commit.Succeed.

*/