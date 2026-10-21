//*******************************************************************************************************
//
//		File:					RetailItemApplication.cpp
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
//		This program holds retail items' data in a retail store.
//	
//		Other files required: 
//			1.	RetailItem.cpp
//			2.  RetailItem.h
//			
//*******************************************************************************************************

#include "RetailItem.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//*******************************************************************************************************

int main()
{
	const int count = 5;
	RetailItem items[count];

	string description;
	double price;
	int quantity;

	for (int i = 0; i < count; i++)
	{
		cout << "Enter description for item " << i+1 << ": ";
		getline(cin, description);
		cout << "Enter price for item " << i + 1 << ": ";
		cin >> price;
		cin.ignore();
		cout << "Enter quantity for item " << i + 1 << ": ";
		cin >> quantity;
		cin.ignore();
		items[i].setDescription(description);
		items[i].setPrice(price);
		items[i].setQuantity(quantity);
	}
	cout << "Webster Grocery" << endl;
	cout << count << " items in stock" << endl;
	cout << string(45, '*') << endl;
	cout << left << setw(16) << "Description";
	cout << left << setw(8) << "Price";
	cout << "Quantity" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << left << setw(16) << items[i].getDescription();
		cout << left << setw(8) << setprecision(3) << items[i].getPrice();
		cout << items[i].getQuantity() << endl;
	}
	return 0;
}

//*******************************************************************************************************
/*
Enter description for item 1: paper
Enter price for item 1: 4.99
Enter quantity for item 1: 120
Enter description for item 2: notebook
Enter price for item 2: 1.99
Enter quantity for item 2: 200
Enter description for item 3: pencil
Enter price for item 3: 0.99
Enter quantity for item 3: 120
Enter description for item 4: staples
Enter price for item 4: 4.99
Enter quantity for item 4: 30
Enter description for item 5: blue ink pen
Enter price for item 5: 2.59
Enter quantity for item 5: 10
Webster Grocery
5 items in stock
*********************************************
Description     Price   Quantity
paper           4.99    120
notebook        1.99    200
pencil          0.99    120
staples         4.99    30
blue ink pen    2.59    10

C:\Users\stone\source\repos\RussRetailItem\Debug\RussRetailItem.exe (process 52040) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/