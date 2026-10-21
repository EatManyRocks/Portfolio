//***************************************************************
//
//		Assignment:		#6
// 
//		File:			RussAssignment6.cpp
// 
//		Due Date:		September 16, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	User enters seed and generates an
//						addition problem with numbers less than 500
//
//
//***************************************************************

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	const int MAXRANGE = 500;
	unsigned seed;
	double sum;
	char aChar;
	cout << "Enter a number and hit the enter \nkey to display an addition problem:" << endl;
	cin >> seed;
	srand(seed);
	int random1 = 1+rand() % MAXRANGE;
	int random2 = 1 + rand() % MAXRANGE;
	sum = random1 + random2;
	cin.ignore();
	cout << "Press enter when you are ready to see the answer." << endl; 
	cout << setw(4) << random1 << endl;
	cout << "+" << setw(3) << random2 << endl;
	cout << setw(2) << "-----";
	cin.get(aChar);
	cout << setw(4) << sum << endl;
	cout << "Press any key to continue" << endl;
	return 0;
}

/*
Enter a number and hit the enter
key to display an addition problem:
12
Press enter when you are ready to see the answer.
  78
+129
-----
 207
Press any key to continue

C:\Users\stone\source\repos\Assignment6\Debug\Assignment6.exe (process 14328) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/