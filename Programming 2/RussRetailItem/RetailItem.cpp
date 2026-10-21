//*******************************************************************************************************
//
//		File:					RetailItem.cpp
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
//		This program holds the functions for the RetailItem class 
//		which get/set description, price, and quantity.
//	
//		Other files required: 
//			1.	RetailItemApplication.cpp
//			2.  RetailItem.h
//			
//*******************************************************************************************************

#include "RetailItem.h"
#include  <iostream>
#include <iomanip>
#include <string>

using namespace std;

//*******************************************************************************************************

RetailItem::RetailItem(string d, int q, double p)
{
	description = d;
	quantity = q;
	price = p;
}

//*******************************************************************************************************

RetailItem::RetailItem()
{
	description = "none";
	quantity = 0;
	price = 0;
}

//*******************************************************************************************************

string RetailItem::getDescription() const
{
	return description;
}

//*******************************************************************************************************

int RetailItem::getQuantity() const
{
	return quantity;
}

//*******************************************************************************************************

double RetailItem::getPrice() const
{
	return price;
}

//*******************************************************************************************************

void RetailItem::setDescription(string d)
{
	description = d;
}

//*******************************************************************************************************

void RetailItem::setQuantity(int q)
{
	quantity = q;
}

//*******************************************************************************************************

void RetailItem::setPrice(double p)
{
	price = p;
}