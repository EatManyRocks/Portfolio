//*****************************************************************************************************
//
//		File:					main.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/4/24
//
//
//		This program is the driver.
//	
//		Other files required: 
//			1.	AVLTree.h
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  Stock.txt
//			5.	Node.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "AVLTree.h"
#include "Stock.h"

//*****************************************************************************************************

char getChoice();
void displayStockName(AVLTree<Stock>& StockTree);
void displayStockPrice(AVLTree<Stock>& StockTree);
void userInsertStock(AVLTree<Stock>& stockTree);

//*****************************************************************************************************

int main()
{
	AVLTree<Stock> stockTree;
	AVLTree<int> intTree;
	fstream stockFile("Stock.txt", ios::in);
	string name;
	string symbol;
	string price;
	char choice;

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		intTree.insert(rand() % 5000 + 1);
	}

	cout << "inorder:" << endl;
	intTree.inorder();
	cout << endl;
	cout << "preorder:" << endl;
	intTree.preorder();
	cout << endl;
	cout << "postorder:" << endl;
	intTree.postorder();
	cout << endl;

	cout << "height:" << intTree.height() << endl;

	intTree.destroy();

	cout << "height after destroying:" << intTree.height() << endl;

	if (stockFile.is_open())
	{
		while (getline(stockFile, name))
		{
			getline(stockFile, symbol);
			getline(stockFile, price);

			Stock newStock(name, symbol, stod(price));

			stockTree.insert(newStock);
		}

		stockFile.close();

		do
		{
			choice = getChoice();

			switch (choice)
			{
			case 'A':
				displayStockName(stockTree);
				break;
			case 'B':
				displayStockPrice(stockTree);
				break;
			case 'C':
				userInsertStock(stockTree);
				break;
			case 'D':
				stockTree.inorder();
				break;
			case 'E':
				stockFile.open("Stock.txt", ios::out);

				stockTree.inorder(stockFile);

				stockFile.close();
				break;
			}
		} while (choice != 'E');
	}

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "======== MENU ========\n"
		<< " a)  Display a stocks name given its symbol\n"
		<< " b)  Display a stocks price given its symbol\n"
		<< " c)  Insert a new stock\n"
		<< " d)  Display all stocks\n"
		<< " e)  Quit\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
			valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice\n"
				<< "Please try again: ";
			break;
		}
	} while (!valid);

	return choice;
}

//*****************************************************************************************************

void displayStockName(AVLTree<Stock>& stockTree)
{
	bool valid = false;
	string symbol;
	Stock* tempStockPtr;
	int strLen;

	cin.ignore();
	cout << "Enter stock symbol: ";
	getline(cin, symbol);

	strLen = symbol.length();

	for (int i = 0; i < strLen; i++)
	{
		symbol[i] = toupper(symbol[i]);
	}

	Stock tempStock("", symbol);
	tempStockPtr = stockTree.search(tempStock);

	if (tempStockPtr != nullptr)
	{
		cout << "Stock name: " << tempStockPtr->getName() << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

//*****************************************************************************************************

void displayStockPrice(AVLTree<Stock>& stockTree)
{
	bool valid = false;
	string symbol;
	Stock* tempStockPtr;
	int strLen;

	cin.ignore();
	cout << "Enter stock symbol: ";
	getline(cin, symbol);

	strLen = symbol.length();

	for (int i = 0; i < strLen; i++)
	{
		symbol[i] = toupper(symbol[i]);
	}

	Stock tempStock("", symbol);
	tempStockPtr = stockTree.search(tempStock);

	if (tempStockPtr != nullptr)
	{
		cout << "Stock price: " << tempStockPtr->getPrice() << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

//*****************************************************************************************************

void userInsertStock(AVLTree<Stock>& stockTree)
{
	string symbol;
	string name;
	double price;
	int strLen;
	bool valid = false;

	cin.ignore();
	cout << "Enter stock symbol: ";
	getline(cin, symbol);

	strLen = symbol.length();

	for (int i = 0; i < strLen; i++)
	{
		symbol[i] = toupper(symbol[i]);
	}

	cout << "Enter stock name: ";
	getline(cin, name);

	while (!valid)
	{
		cout << "Enter stock price: ";
		cin >> price;

		if (cin.fail())
		{
			cout << "\nERROR" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			valid = true;
	}

	Stock newStock(name, symbol, price);
	stockTree.insert(newStock);
}

//*****************************************************************************************************

/*
inorder:
Value: 18        Balance Factor: 0
Value: 360       Balance Factor: 1
Value: 502       Balance Factor: 0
Value: 1226      Balance Factor: 0
Value: 2131      Balance Factor: 1
Value: 2303      Balance Factor: 0
Value: 2365      Balance Factor: 0
Value: 2765      Balance Factor: -1
Value: 4239      Balance Factor: 0
Value: 4414      Balance Factor: 1

preorder:
Value: 2303      Balance Factor: 0
Value: 502       Balance Factor: 0
Value: 360       Balance Factor: 1
Value: 18        Balance Factor: 0
Value: 2131      Balance Factor: 1
Value: 1226      Balance Factor: 0
Value: 2765      Balance Factor: -1
Value: 2365      Balance Factor: 0
Value: 4414      Balance Factor: 1
Value: 4239      Balance Factor: 0

postorder:
Value: 18        Balance Factor: 0
Value: 360       Balance Factor: 1
Value: 1226      Balance Factor: 0
Value: 2131      Balance Factor: 1
Value: 502       Balance Factor: 0
Value: 2365      Balance Factor: 0
Value: 4239      Balance Factor: 0
Value: 4414      Balance Factor: 1
Value: 2765      Balance Factor: -1
Value: 2303      Balance Factor: 0

height:4
height after destroying:0
======== MENU ========
 a)  Display a stocks name given its symbol
 b)  Display a stocks price given its symbol
 c)  Insert a new stock
 d)  Display all stocks
 e)  Quit
Enter your choice: d
Value: Apple
AAPL
121.73
		 Balance Factor: 0
Value: Advanced Micro Devices
AMD
84.51
		 Balance Factor: 1
Value: Ford Motor
F
11.7
		 Balance Factor: 0
Value: General Electric
GE
12.54
		 Balance Factor: 0
Value: Intel
INTC
60.78
		 Balance Factor: 0
Value: Motorola Inc.
MOT
17.49
		 Balance Factor: 0
Value: Microsoft Corp.
MSFT
28.11
		 Balance Factor: 1
Value: NVIDIA
NVDA
548.58
		 Balance Factor: 0
Value: Sony
SNE
105.81
		 Balance Factor: 0
Value: Tesla
TSLA
564.33
		 Balance Factor: 0
======== MENU ========
 a)  Display a stocks name given its symbol
 b)  Display a stocks price given its symbol
 c)  Insert a new stock
 d)  Display all stocks
 e)  Quit
Enter your choice: e
*/