//*****************************************************************************************************
//
//		File:					Stock.h
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
//		This is the header for the Stock class.
//	
//		Other files required: 
//			1.	ArrayList.h
//			2.  Stock.cpp
//			3.  main.cpp
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
	~Stock();
	void display() const;
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	int hash(int size) const;
	friend ostream& operator << (ostream& out, const Stock& data);
	bool operator == (const Stock& rhs) const;
	bool operator != (const Stock& rhs) const;
	bool operator > (const Stock& rhs) const;
	bool operator >= (const Stock& rhs) const;
	bool operator < (const Stock& rhs) const;
	bool operator <= (const Stock& rhs) const;
};

//*****************************************************************************************************

inline string Stock::getName() const
{
	return name;
}

//*****************************************************************************************************

inline string Stock::getSymbol() const
{
	return symbol;
}

//*****************************************************************************************************

inline double Stock::getPrice() const
{
	return price;
}

inline ostream& operator << (ostream& out, const Stock& data)
{
	out << data.name;
	return out;
}

//*****************************************************************************************************

inline bool Stock::operator == (const Stock& rhs) const
{
	return (this->symbol == rhs.symbol);
}

//*****************************************************************************************************

inline bool Stock::operator != (const Stock& rhs) const
{
	return (this->symbol != rhs.symbol);
}

//*****************************************************************************************************

inline bool Stock::operator > (const Stock& rhs) const
{
	return (this->symbol > rhs.symbol);
}

//*****************************************************************************************************

inline bool Stock::operator >= (const Stock& rhs) const
{
	return (this->symbol >= rhs.symbol);
}

//*****************************************************************************************************

inline bool Stock::operator < (const Stock& rhs) const
{
	return (this->symbol < rhs.symbol);
}

//*****************************************************************************************************

inline bool Stock::operator <= (const Stock& rhs) const
{
	return (this->symbol <= rhs.symbol);
}

//*****************************************************************************************************

#endif