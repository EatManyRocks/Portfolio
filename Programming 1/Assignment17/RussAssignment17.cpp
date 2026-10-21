//***************************************************************
//
//		Assignment:		#17
// 
//		File:			RussAssignment17.cpp
// 
//		Due Date:		November 11, 2022
//
//		Author:			Ryan Russell
//
//
//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Generates random number and has user
//						continue guessing the number until they get it
//
//
//***************************************************************

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int getRandomNumber()
{
	srand(time(0));
	int MAXRANGE = 100;
	int random = 1 + rand() % MAXRANGE;
	return random;
}

int guessAgain()
{
	int guess = 0;
	cout << "Guess again: ";
	cin >> guess;
	return guess;
}

int main()
{
	int guessCount = 0;
	int userGuess = 0;
	int randomNum = getRandomNumber();
	int count = 0;

	cout << "I'm thinking of a number. Can you guess what it is? (1-100): ";
	cin >> userGuess;
	while (userGuess != randomNum)
	{
		count++;
		if (userGuess >= 1 && userGuess <= 100)
		{
			if (userGuess > randomNum)
			{
				cout << "Sorry, that's too high." << endl;
				userGuess = guessAgain();
			}
			else if (userGuess < randomNum)
			{
				cout << "Sorry, that's too low." << endl;
				userGuess = guessAgain();
			}
		}
		else
		{
			cout << "Enter a number between 1-100." << endl;
			userGuess = guessAgain();
		}
		
	}

	cout << "Congratulations! You guessed it!\nI was thinking of the number " << randomNum << "." << endl;
	cout << "You got it right in " << count << " guesses.";

}

/*
I'm thinking of a number. Can you guess what it is? (1-100): 42
Sorry, that's too high.
Guess again: 0
Enter a number between 1-100.
Guess again: 30
Sorry, that's too high.
Guess again: 20
Sorry, that's too high.
Guess again: 10
Sorry, that's too high.
Guess again: 1
Sorry, that's too low.
Guess again: 4
Sorry, that's too high.
Guess again: 2
Congratulations! You guessed it!
I was thinking of the number 2.
You got it right in 7 guesses.
C:\Users\stone\source\repos\Assignment17\Debug\Assignment17.exe (process 22232) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/

