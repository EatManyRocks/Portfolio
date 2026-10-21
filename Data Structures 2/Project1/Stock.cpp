//*****************************************************************************************************
//
//		File:					Stock.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 2
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					9/9/24
//
//
//		This program stores all of the function definitions for the stock class.
//	
//		Other files required: 
//			1.	List.h
//			2.  Node.h
//			3.  Stock.h
//			4.  main.cpp
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

string Stock::getName() const
{
	return name;
}

//*****************************************************************************************************

string Stock::getSymbol() const
{
	return symbol;
}

//*****************************************************************************************************

double Stock::getPrice() const
{
	return price;
}

ostream& operator << (ostream& out, const Stock& data)
{
	out << data.name;
	return out;
}

//*****************************************************************************************************

bool Stock::operator == (const Stock& rhs) const
{
	return (this->symbol == rhs.symbol);
}

//*****************************************************************************************************

bool Stock::operator != (const Stock& rhs) const
{
	return (this->symbol != rhs.symbol);
}

//*****************************************************************************************************

bool Stock::operator > (const Stock& rhs) const
{
	return (this->symbol > rhs.symbol);
}

//*****************************************************************************************************

bool Stock::operator >= (const Stock& rhs) const
{
	return (this->symbol >= rhs.symbol);
}

//*****************************************************************************************************

bool Stock::operator < (const Stock& rhs) const
{
	return (this->symbol < rhs.symbol);
}

//*****************************************************************************************************

bool Stock::operator <= (const Stock& rhs) const
{
	return (this->symbol <= rhs.symbol);
}

//*****************************************************************************************************