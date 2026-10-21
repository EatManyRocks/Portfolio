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

#include "HashTable.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{
	HashTable<Stock> hashStock(10);

	Stock stock1("Stock1", "a", 5.5),
		stock2("Stock2", "b", 10.7),
		stock3("Stock3", "c", 6.2),
		stock4("Stock4", "d", 8.6);

	Stock* stockPtr;

	hashStock.insert(stock1);
	//hashStock.insert(stock2);
	//hashStock.insert(stock3);
	hashStock.insert(stock4);

	hashStock.display();

	hashStock.remove(stock1);

	hashStock.display();

	stockPtr = hashStock.search(stock4);

	return 0;
}

//*****************************************************************************************************

/*
insert loop begins
curr index: 7
insert loop ends
insert loop begins
curr index: 0
insert loop ends
Stock4  Stock1
Stock4
*/