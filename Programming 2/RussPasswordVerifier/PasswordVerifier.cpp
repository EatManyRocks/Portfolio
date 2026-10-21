//*******************************************************************************************************
//
//		File:					PasswordVerifier.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #6
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 6
//
//		Due:					2/24/23
//
//
//		This program checks the validity of a given password by checking to see if it is 8-20 chracters,
//		has at least one uppercase and one lowercase letter, has at least one symbol, and has no white spaces.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//*******************************************************************************************************

void getInput(string&);
bool checkLength(string);
bool checkCase(string);
bool checkDigit(string);
bool checkAlpha(string);
bool checkSymbol(string);
bool checkWhiteSpace(string);

//*******************************************************************************************************

int main()
{
	bool valid = false;
	string password;

	while (valid == false)
	{
		valid = true;
		cout << "****************************************************" << endl;
		getInput(password);

		if (!checkLength(password))
		{
			valid = false;
		}
		if (!checkCase(password))
		{
			valid = false;
		}
		if (!checkDigit(password))
		{
			valid = false;
		}
		if (!checkAlpha(password))
		{
			valid = false;
		}
		if (!checkSymbol(password))
		{
			valid = false;
		}
		if (!checkWhiteSpace(password))
		{
			valid = false;
		}
	}
	cout << "You have successfully entered a password" << endl;
	cout << "The password you've entered is: " << password << endl;
	return 0;
}

//*******************************************************************************************************

void getInput(string & password)
{
	cout << "Please enter a valid password : " << endl;
	getline(cin, password);
}

//*******************************************************************************************************

bool checkLength(string password)
{
	if (password.length() < 8)
	{
		cout << "!!!Error!!! Input is too short" << endl;
		return false;
	}
	if (password.length() > 20)
	{
		cout << "!!!Error!!! Input is too long" << endl;
		return false;
	}
}

//*******************************************************************************************************

bool checkCase(string password)
{
	bool upperDetected = false;
	bool lowerDetected = false;
	int length = password.length();

	for (int i = 0; i < length; i++)
	{
		if (isupper(password[i]))
		{
			upperDetected = true;
		}
		if (islower(password[i]))
		{
			lowerDetected = true;
		}
	}
	if (!lowerDetected)
	{
		cout << "!!!Error!!! Input doesn't contain a lower case letter" << endl;
	}
	if (!upperDetected)
	{
		cout << "!!!Error!!! Input doesn't contain an upper case letter" << endl;
	}
	if (!upperDetected || !lowerDetected)
	{
		return false;
	}
}

//*******************************************************************************************************

bool checkDigit(string password)
{
	bool digitDetected = false;
	int length = password.length();

	for (int i = 0; i < length; i++)
	{
		if (isdigit(password[i]))
		{
			digitDetected = true;
		}
	}
	if (!digitDetected)
	{
		cout << "!!!Error!!! Input doesn't contain a digit" << endl;
		return false;
	}
}

//*******************************************************************************************************

bool checkAlpha(string password)
{
	bool alphaDetected = false;
	int length = password.length();

	for (int i = 0; i < length; i++)
	{
		if (isalpha(password[i]))
		{
			alphaDetected = true;
		}
	}
	if (!alphaDetected)
	{
		cout << "!!!Error!!! Input doesn't contain an alphabet" << endl;
		return false;
	}
}

//*******************************************************************************************************

bool checkSymbol(string password)
{
	size_t found = password.find(" ");
	bool symbolDetected = false;
	int length = password.length();

	for (int i = 0; i < length; i++)
	{
		if (!isalnum(password[i]) && found == string::npos)
		{
			symbolDetected = true;
		}
	}
	if (!symbolDetected)
	{
		cout << "!!!Error!!! The password doesn't contain at least one symbol" << endl;
		return false;
	}
}

//*******************************************************************************************************

bool checkWhiteSpace(string password)
{
	bool whiteSpaceDetected = false;
	size_t found = password.find(" ");

	if (found != string::npos)
	{
		whiteSpaceDetected = true;
	}
	if (whiteSpaceDetected)
	{
		cout << "!!!Error!!! Input cannot contain a white space" << endl;
		return false;
	}
}
/*
****************************************************
Please enter a valid password :
123
!!!Error!!! Input is too short
!!!Error!!! Input doesn't contain a lower case letter
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! Input doesn't contain an alphabet
!!!Error!!! The password doesn't contain at least one symbol
****************************************************
Please enter a valid password :
password
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! Input doesn't contain a digit
!!!Error!!! The password doesn't contain at least one symbol
****************************************************
Please enter a valid password :
password1
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! The password doesn't contain at least one symbol
****************************************************
Please enter a valid password :
Password1
!!!Error!!! The password doesn't contain at least one symbol
****************************************************
Please enter a valid password :
Password  1
!!!Error!!! The password doesn't contain at least one symbol
!!!Error!!! Input cannot contain a white space
****************************************************
Please enter a valid password :
Password      1
!!!Error!!! The password doesn't contain at least one symbol
!!!Error!!! Input cannot contain a white space
****************************************************
Please enter a valid password :
Password1#
You have successfully entered a password
The password you've entered is: Password1#

C:\Users\stone\source\repos\RussPasswordVerifier\Debug\RussPasswordVerifier.exe (process 37984) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/