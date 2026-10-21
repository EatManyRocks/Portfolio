//*****************************************************************************************************
//
//		File:					LDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/29/24
//
//
//		This program is the driver that proves the correctness of the LList class.
//	
//		Other files required: 
//			1.	List.h
//			2.  Node.h
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "LList.h"

//*****************************************************************************************************

int main()
{
	LList<double> doubleList;
	double dataIn = 0;
	double dataOut = 0;

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataIn = 1;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	dataIn = 2;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	dataIn = 3;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataIn = 0.5;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	dataIn = 2.5;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataOut = 0.5;
	if (doubleList.remove(dataOut))
	{
		cout << "Removed " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to remove " << dataOut << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataOut = 2.5;
	if (doubleList.remove(dataOut))
	{
		cout << "Removed " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to remove " << dataOut << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataOut = 2;
	if (doubleList.remove(dataOut))
	{
		cout << "Removed " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to remove " << dataOut << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	dataIn = 2;
	if (doubleList.insert(dataIn))
	{
		cout << "Inserted " << dataIn << "." << endl;
	}
	else
	{
		cout << "Failed to insert " << dataIn << "." << endl;
	}

	dataOut = 4;
	if (doubleList.remove(dataOut))
	{
		cout << "Removed " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to remove " << dataOut << "." << endl;
	}

	dataOut = 2.5;
	if (doubleList.remove(dataOut))
	{
		cout << "Removed " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to remove " << dataOut << "." << endl;
	}

	dataOut = 1;
	if (doubleList.retrieve(dataOut))
	{
		cout << "Retrieved " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to retrieve " << dataOut << "." << endl;
	}

	dataOut = 2;
	if (doubleList.retrieve(dataOut))
	{
		cout << "Retrieved " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to retrieve " << dataOut << "." << endl;
	}

	dataOut = 3;
	if (doubleList.retrieve(dataOut))
	{
		cout << "Retrieved " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to retrieve " << dataOut << "." << endl;
	}

	dataOut = 4;
	if (doubleList.retrieve(dataOut))
	{
		cout << "Retrieved " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to retrieve " << dataOut << "." << endl;
	}

	dataOut = 2.5;
	if (doubleList.retrieve(dataOut))
	{
		cout << "Retrieved " << dataOut << "." << endl;
	}
	else
	{
		cout << "Failed to retrieve " << dataOut << "." << endl;
	}

	if (doubleList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		cout << "Contents of the list:" << endl;
		doubleList.display();
		cout << "Number of Values: " << doubleList.getNumValues() << endl;
	}

	if (doubleList.isFull())
	{
		cout << "The list is full." << endl;
	}
	else
	{
		cout << "The list is not full" << endl;
	}
}

//*****************************************************************************************************

/*
The list is empty.
Inserted 1.
Inserted 2.
Inserted 3.
Contents of the list:
1       2       3
Number of Values: 3
Inserted 0.5.
Inserted 2.5.
Contents of the list:
0.5     1       2       2.5     3
Number of Values: 5
Removed 0.5.
Contents of the list:
1       2       2.5     3
Number of Values: 4
Removed 2.5.
Contents of the list:
1       2       3
Number of Values: 3
Removed 2.
Contents of the list:
1       3
Number of Values: 2
Inserted 2.
Failed to remove 4.
Failed to remove 2.5.
Retrieved 1.
Retrieved 2.
Retrieved 3.
Failed to retrieve 4.
Failed to retrieve 2.5.
Contents of the list:
1       2       3
Number of Values: 3
The list is not full
*/