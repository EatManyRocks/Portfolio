//*****************************************************************************************************
//
//		File:					main.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					9/16/24
//
//
//		This program is the driver.
//	
//		Other files required: 
//			1.	ArrayList.h
//			2.  Stock.h
//			3.  Stock.cpp
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "ArrayList.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{
	int index;
	ArrayList<int> intList;
	ArrayList<Stock> stockList(5);
	Stock stock1("Stock1", "a", 5.5),
		stock2("Stock2", "ab", 10.7),
		stock3("Stock3", "ac", 6.2),
		stock4("Stock4", "d", 8.6),
		stock5("Stock5", "e", 8.9),
		stock6("Stock6", "f", 1.1);

	intList.insert(1);
	intList.insert(2);
	intList.insert(3);
	intList.insert(4);
	cout << "int list:" << endl;
	index = intList.binarySearch(2);
	cout << "Index: " << index << endl;
	intList.print();

	ArrayList<int> intListCopy(intList);
	cout << "copied list:" << endl;
	intListCopy.print();

	stockList.insert(stock1);
	stockList.insert(stock2);
	stockList.insert(stock3);
	stockList.insert(stock4);
	stockList.insert(stock5);
	cout << "Stock list:" << endl;
	index = stockList.binarySearch(stock1);
	cout << "Index: " << index << endl;
	stockList.print();

	if (stockList.isEmpty())
	{
		cout << "Stock list is empty." << endl;
	}

	if (stockList.isFull())
	{
		cout << "Stock list is full." << endl;
	}

	cout << "Stock list's length is " << stockList.listSize() << endl;

	stockList.insert(stock6);

	stockList.print();

	if (stockList.isEmpty())
	{
		cout << "Stock list is empty." << endl;
	}

	if (stockList.isFull())
	{
		cout << "Stock list is full." << endl;
	}

	cout << "Stock list's length is " << stockList.listSize() << endl;

	return 0;
}

//*****************************************************************************************************

/*
int list:
Index: 2
[4]  [3]  [2]  [1]
copied list:
[4]  [3]  [2]  [1]
Stock list:
Index: 4
[Stock5]  [Stock4]  [Stock3]  [Stock2]  [Stock1]
Stock list is full.
Stock list's length is 5
[Stock6]  [Stock5]  [Stock4]  [Stock3]  [Stock2]  [Stock1]
Stock list's length is 6
*/