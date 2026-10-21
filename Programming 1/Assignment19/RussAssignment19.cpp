//***************************************************************
//
//		Assignment:		#19
// 
//		File:			RussAssignment19.cpp
// 
//		Due Date:		November 28, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Rock Paper Scissors against computer.
//
//
//***************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//*****************************************************************************************************

int getComputerChoice();
int getUserChoice();
void determineWinner( int, int );

//*****************************************************************************************************

int main()
{
	int userChoice = 0;
	int compChoice = 0;

	do
	{
		userChoice = 0;
		compChoice = 0;

		userChoice = getUserChoice();
		compChoice = getComputerChoice();
		determineWinner(compChoice, userChoice);
	}
	while (userChoice != 4);
}

//*****************************************************************************************************

int getComputerChoice()
{
	int num = 0;
	int MAXRANGE = 3;

	srand(time(0));
	num = 1 + rand() % MAXRANGE;
	return num;
}

//*****************************************************************************************************

int getUserChoice()
{
	int num = 0;

	do
	{
		cout << "Game Menu\n-----------\n1) Rock\n2) Paper\n3) Scissors\n4) Quit" << endl;
		cout << "\nEnter your choice: ";
		cin >> num;
	}
	while ((num > 4) || (num < 1));
	return num;
}

//*****************************************************************************************************

void determineWinner(int compNum, int userNum)
{
	if (userNum == 1)
	{
		cout << "You selected: Rock" << endl;
		if (compNum == 2)
		{
			cout << "The computer selected: Paper " << endl;
			cout << "Computer wins. Paper wraps rock. \n";
		}
		else if (compNum == 3)
		{
			cout << "The computer selected: Scissors " << endl;
			cout << "You win! Rock smashes scissors. \n";
		}
		else
		{
			cout << "The computer selected: Rock " << endl;
			cout << "Tie. No winner. \n";
		}
	}

	else if (userNum == 2)
	{
		cout << "You selected: Paper" << endl;
		if (compNum == 1)
		{
			cout << "The computer selected: Rock " << endl;
			cout << "You win! Paper wraps rock. \n";
		}
		else if (compNum == 3)
		{
			cout << "The computer selected: Scissors " << endl;
			cout << "Computer wins. Scissors cut paper. \n";
		}
		else
		{
			cout << "The computer selected: Paper " << endl;
			cout << "Tie. No winner. \n";
		}
	}

	else if (userNum == 3)
	{
		cout << "You selected: Scissors" << endl;
		if (compNum == 1)
		{
			cout << "The computer selected: Rock " << endl;
			cout << "Computer wins. Rock smashes scissors. \n";
		}
		else if (compNum == 2)
		{
			cout << "The computer selected: Paper " << endl;
			cout << "You win! Scissors cut paper. \n";
		}
		else
		{
			cout << "The computer selected: Scissors " << endl;
			cout << "Tie. No winner. \n";
		}
	}
}

//*****************************************************************************************************

/*
Game Menu
-----------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 0
Game Menu
-----------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 1
You selected: Rock
The computer selected: Scissors
You win! Rock smashes scissors.
Game Menu
-----------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 2
You selected: Paper
The computer selected: Rock
You win! Paper wraps rock.
Game Menu
-----------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 3
You selected: Scissors
The computer selected: Rock
Computer wins. Rock smashes scissors.
Game Menu
-----------
1) Rock
2) Paper
3) Scissors
4) Quit

Enter your choice: 4

C:\Users\stone\source\repos\Assignment19\Debug\Assignment19.exe (process 34800) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/