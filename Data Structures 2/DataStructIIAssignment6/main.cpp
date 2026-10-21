//*****************************************************************************************************
//
//		File:					main.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					10/7/24
//
//
//		This program is the driver.
//	
//		Other files required: 
//			1.	BinarySearchTree.h
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

#include "BinarySearchTree.h"
#include "Stock.h"

//*****************************************************************************************************

char getChoice();
void displayStockName(BinarySearchTree<Stock>& StockTree);
void displayStockPrice(BinarySearchTree<Stock>& StockTree);
void userInsertStock(BinarySearchTree<Stock>& stockTree);

//*****************************************************************************************************

int main()
{
	BinarySearchTree<Stock> stockTree;
	BinarySearchTree<int> intTree;
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

void displayStockName(BinarySearchTree<Stock>& stockTree)
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

void displayStockPrice(BinarySearchTree<Stock>& stockTree)
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

void userInsertStock(BinarySearchTree<Stock>& stockTree)
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
21
26
393
580
1442
3330
3510
3707
3827
4374

preorder:
3707
3510
1442
580
26
21
393
3330
4374
3827

postorder:
21
393
26
580
3330
1442
3510
3827
4374
3707

height:6
height after destroying:0
======== MENU ========
 a)  Display a stocks name given its symbol
 b)  Display a stocks price given its symbol
 c)  Insert a new stock
 d)  Display all stocks
 e)  Quit
Enter your choice: c
Enter stock symbol: BOB
Enter stock name: Bob Inc.
Enter stock price: 11.11
======== MENU ========
 a)  Display a stocks name given its symbol
 b)  Display a stocks price given its symbol
 c)  Insert a new stock
 d)  Display all stocks
 e)  Quit
Enter your choice: e
*/