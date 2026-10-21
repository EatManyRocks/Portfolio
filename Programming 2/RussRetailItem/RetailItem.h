//*******************************************************************************************************
//
//		File:					RetailItem.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #13
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 13
//
//		Due:					4/24/23
//
//
//		This header is for the RetailItem class.
//	
//		Other files required: 
//			1.	RetailItem.cpp
//			2.  RetailItemApplication.cpp
//			
//*******************************************************************************************************

#ifndef RETAILITEM_H
#define RETAILITEM_H

#include <string>

//*******************************************************************************************************

class RetailItem
{
private:
	std::string description;
	int quantity;
	double price;
public:
	RetailItem(std::string, int, double);
	RetailItem();
	std::string getDescription() const;
	int getQuantity() const;
	double getPrice() const;
	void setDescription(std::string);
	void setQuantity(int);
	void setPrice(double);
};

//*******************************************************************************************************

#endif