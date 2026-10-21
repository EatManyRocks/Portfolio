//*******************************************************************************************************
//
//		File:					NameReport.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #9
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 9
//
//		Due:					3/27/23
//
//
//		This program .
//	
//		Other files required: 
//			1.	name.txt
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

//*******************************************************************************************************

const int DISPLAY_FIRST_FIVE = 1;
const int DISPLAY_LAST_FIVE = 2;
const int COUNT = 3;
const int COPY_TO_FILE = 4;
const int SEARCH = 5;
const int QUIT = 6;

//*******************************************************************************************************

int getChoice();
void handleMenu(ifstream& fin);
void displayFirstFive(ifstream& fin);
void displayLastFive(ifstream& fin);
int count(ifstream& fin);
void copyToFile(ifstream& fin, ofstream& fout);
void search(ifstream& fin);

//*******************************************************************************************************

int main()
{
	bool running = true;
	ifstream namesFile("names.txt", ios::in);

	handleMenu(namesFile);
}

//*******************************************************************************************************

int getChoice()
{
	int ch = 0;
	cout << string(40, '*') << endl;
	cout << "1. Display first five names" << endl;
	cout << "2. Display last five names" << endl;
	cout << "3. Count the number of names" << endl;
	cout << "4. Copy Names to names_copy.txt" << endl;
	cout << "5. Search for a name" << endl;
	cout << "6. Quit" << endl;
	cout << "Enter your choice: ";
	cin >> ch;
	return ch;
}

//*******************************************************************************************************

void handleMenu(ifstream& fin)
{
	ofstream fout("names_copy.txt", ios::out);
	
	bool running = true;

	while (running)
	{
		int cnt = 0;
		int choice = getChoice();
		switch (choice)
		{
		case DISPLAY_FIRST_FIVE:
			displayFirstFive(fin);
			break;
		case DISPLAY_LAST_FIVE:
			displayLastFive(fin);
			break;
		case COUNT:
			cnt = count(fin);
			cout << "There are " << cnt << " names." << endl;
			break;
		case COPY_TO_FILE:
			copyToFile(fin, fout);
			break;
		case SEARCH:
			search(fin);
			break;
		case QUIT:
			running = false;
			break;
		default:
			cout << "\nERROR: Invalid Input" << endl;
			break;
		}
		cin.ignore(INT_MAX, '\n');
	}
}

//*******************************************************************************************************

void displayFirstFive(ifstream& fin)
{
	string input;

	fin.close();
	fin.open("names.txt", ios::in);

	if (fin.is_open())
	{
		getline(fin, input);

		if (fin.is_open())
		{
			for (int i = 0; i < 5; i++)
			{
				cout << i + 1 << ": " << input << endl;
				getline(fin, input);
			}
		}

		fin.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n";
	}
}

//*******************************************************************************************************

void displayLastFive(ifstream& fin)
{
	string input;
	fin.close();
	fin.open("names.txt", ios::in);
	if (fin.is_open())
	{
		getline(fin, input);

		if (fin.is_open())
		{
			for (int i = 0; i < 45; i++)
			{
				getline(fin, input);
			}
			for (int i = 0; i < 5; i++)
			{
				cout << i + 46 << ": " << input << endl;
				getline(fin, input);
			}
		}
		fin.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n";
	}
}

//*******************************************************************************************************

int count(ifstream& fin)
{
	int cnt = 0;
	string input;

	fin.close();
	fin.open("names.txt", ios::in);

	if (fin.is_open())
	{
		while (fin)
		{
			getline(fin, input);
			if (isalnum(input[0]))
			{
				cnt++;
			}
			
		}

		fin.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n";
	}
	return cnt;
}

//*******************************************************************************************************

void copyToFile(ifstream& fin, ofstream& fout)
{
	fin.close();
	fout.close();
	fin.open("names.txt", ios::in);
	fout.open("names_copy.txt", ios::out);

	string input;

	if (fin.is_open() && fout.is_open())
	{
		getline(fin, input);

		if (fin.is_open() && fout.is_open())
		{
			while (fin)
			{
				if (isalnum(input[0]))
				{
					cout << "Printing to copy: " << input << endl;
					fout << input << endl;
				}
				getline(fin, input);
			}
		}
		cout << "Done!" << endl;

		fout.close();
		fin.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n";
	}

	
}

//*******************************************************************************************************

void search(ifstream& fin)
{
	bool notFound = true;
	int cnt = 0;
	string input;
	string userInput;
	cin.ignore(INT_MAX, '\n');
	cout << "Enter a name so I can search for it: ";
	getline(cin, userInput, '\n');
	fin.close();
	fin.open("names.txt", ios::in);

	if (fin.is_open())
	{
		while (getline(fin, input, '\n'))
		{
			cnt++;
			if (input == userInput)
			{
				notFound = false;
				cout << "Found on line " << cnt << endl;
			}
		}
		if (notFound == true)
		{
			cout << "NOT FOUND" << endl;
		}
		fin.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n";
	} 

}

//*******************************************************************************************************

/*
* ****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 1
1: Woodrow Holloway
2: Andy Rodgers
3: Jean Barker
4: Lynda Hernandez
5: Carol Diaz
****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 2
46: Emily Santos
47: Cynthia Burton
48: Noah Moreno
49: Glenn Barnes
50: Nancy Hicks
****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 3
There are 50 names.
****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 4
Printing to copy: Woodrow Holloway
Printing to copy: Andy Rodgers
Printing to copy: Jean Barker
Printing to copy: Lynda Hernandez
Printing to copy: Carol Diaz
Printing to copy: Kristopher Mann
Printing to copy: Lydia Howard
Printing to copy: Cedric Armstrong
Printing to copy: Evan Patton
Printing to copy: Homer Butler
Printing to copy: Terrance Hanson
Printing to copy: Jackie Christensen
Printing to copy: Meghan Lewis
Printing to copy: Rolando Jefferson
Printing to copy: Sadie Perry
Printing to copy: Amelia Kelley
Printing to copy: Lora Carson
Printing to copy: Ida Rice
Printing to copy: Marion Harris
Printing to copy: Pablo Mcguire
Printing to copy: Janet Sandoval
Printing to copy: Tasha Cross
Printing to copy: Pam Greer
Printing to copy: Stanley Duncan
Printing to copy: Alfred Frank
Printing to copy: Naomi Austin
Printing to copy: Rochelle Maxwell
Printing to copy: Benny Woods
Printing to copy: Mae Ferguson
Printing to copy: Sharon Little
Printing to copy: Albert Ramirez
Printing to copy: Brittany Hayes
Printing to copy: Erma Wade
Printing to copy: Annie Evans
Printing to copy: Gerardo Massey
Printing to copy: Garry Williamson
Printing to copy: Moses Hughes
Printing to copy: Tracy Roy
Printing to copy: Amber Alexander
Printing to copy: Orville Edwards
Printing to copy: Doyle Morris
Printing to copy: Wallace Parker
Printing to copy: Mitchell Cooper
Printing to copy: Corey Barrett
Printing to copy: Nicholas Vega
Printing to copy: Emily Santos
Printing to copy: Cynthia Burton
Printing to copy: Noah Moreno
Printing to copy: Glenn Barnes
Printing to copy: Nancy Hicks
Done!
****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 5
Enter a name so I can search for it: Emily Santos
Found on line 46

****************************************
1. Display first five names
2. Display last five names
3. Count the number of names
4. Copy Names to names_copy.txt
5. Search for a name
6. Quit
Enter your choice: 6

C:\Users\stone\source\repos\RussNameReport\Debug\RussNameReport.exe (process 39604) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/