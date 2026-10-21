//*****************************************************************************************************
//
//		File:					Stock.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/11/24
//
//
//		This program stores most of the function definitions for the stock class.
//	
//		Other files required: 
//			1.	Node.h
//			2.  Stock.h
//			3.  main.cpp
//			4.  HuffmanStock.txt
//			
//*****************************************************************************************************

#include <iostream>

using namespace std;

#include "Stock.h"

//*****************************************************************************************************

Stock::Stock(const string& n, const string& s, double p)
{
	name = n;
	symbol = s;
	price = p;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

//*****************************************************************************************************

void Stock::display() const
{
	cout << "Name: " << name << endl;
	cout << "Symbol: " << symbol << endl;
	cout << "Price: " << price << endl;
}

//*****************************************************************************************************

