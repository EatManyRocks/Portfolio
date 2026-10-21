//*****************************************************************************************************
//
//		File:					Stock.h
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
//		This is the header for the Stock class.
//	
//		Other files required: 
//			1.	List.h
//			2.  Node.h
//			3.  Stock.cpp
//			4.  main.cpp
//			
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <string>

//*****************************************************************************************************

class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;
public:
	Stock(const std::string& n = "", const std::string& s = "", double p = 0);
	Stock(const Stock& s);
	void display() const;
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	friend ostream& operator << (ostream& out, const Stock& data);
	bool operator == (const Stock& rhs) const;
	bool operator != (const Stock& rhs) const;
	bool operator > (const Stock& rhs) const;
	bool operator >= (const Stock& rhs) const;
	bool operator < (const Stock& rhs) const;
	bool operator <= (const Stock& rhs) const;
};

//*****************************************************************************************************

#endif