//*****************************************************************************************************
//
//		File:					driverAList.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #4
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/22/24
//
//
//		This program is the driver that proves the correctness of the AList class.
//	
//		Other files required: 
//			1.	AList.h
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//*****************************************************************************************************

int main()
{
	AList<short> shortList(3);
	short min;
	short dataIn;
	short dataOut;
	int index;

	dataIn = 3;
	if (shortList.insertFront(dataIn))
	{
		cout << "\nInserted " << dataIn << " at front." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to insert the value " << dataIn << "." << endl;

	dataIn = 1;
	if (shortList.insertBack(dataIn))
	{
		cout << "\nInserted " << dataIn << " at back." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to insert the value " << dataIn << "." << endl;

	dataIn = 1;
	if (shortList.insertFront(dataIn))
	{
		cout << "\nInserted " << dataIn << " at front." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to insert the value " << dataIn << "." << endl;

	dataIn = 8;
	index = 1;
	if (shortList.insertAtIndex(dataIn, index))
	{
		cout << "\nInserted " << dataIn << " at [" << index << "]." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to insert the value " << dataIn << " at [" << index << "]." << endl;

	if (shortList.isFull())
	{
		cout << "\nList is full" << endl;
	}
	else
		cout << "\nList is not full" << endl;

	if (shortList.isEmpty())
	{
		cout << "\nList is empty" << endl;
	}
	else
		cout << "\nList is not empty" << endl;

	if (shortList.removeFront(dataOut))
	{
		cout << "\nRemoved " << dataOut << " at front." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to remove the front value" << endl;

	dataOut = 3;
	if (shortList.remove(dataOut))
	{
		cout << "\nRemoved first " << dataOut << "." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to remove the first " << dataOut << endl;

	index = 1;
	if (shortList.removeAtIndex(dataOut, index))
	{
		cout << "\nRemoved " << dataOut << " at [" << index << "]." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to remove the value at [" << index << "]" << endl;

	index = 2;
	if (shortList.removeAtIndex(dataOut, index))
	{
		cout << "\nRemoved " << dataOut << " at [" << index << "]." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to remove the value at [" << index << "]" << endl;

	if (shortList.removeBack(dataOut))
	{
		cout << "\nRemoved " << dataOut << " at back." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to remove the back value" << endl;

	if (shortList.isEmpty())
	{
		cout << "\nList is empty" << endl;
	}
	else
		cout << "\nList is not empty" << endl;

	shortList.insertBack(1);
	shortList.insertBack(2);
	shortList.insertBack(3);
	shortList.insertBack(4);
	shortList.insertBack(5);
	shortList.insertBack(6);
	cout << "\nInserted values from 1 to 6." << endl;
	shortList.display();

	if (shortList.isFull())
	{
		cout << endl << "\nList is full" << endl;
	}
	else
		cout << endl << "\nList is not full" << endl;

	if (shortList.retrieveFront(dataOut))
	{
		cout << "\nRetrieved " << dataOut << " at front." << endl;
	}
	else
		cout << "\nUnable to retrieve." << endl;

	if (shortList.retrieveBack(dataOut))
	{
		cout << "\nRetrieved " << dataOut << " at back." << endl;
	}
	else
		cout << "\nUnable to retrieve." << endl;

	index = 7;
	if (shortList.retrieveAtIndex(dataOut, index))
	{
		cout << "\nRetrieved " << dataOut << " at [" << index << "]." << endl;
	}
	else
		cout << "\nUnable to retrieve." << endl;

	index = 4;
	if (shortList.retrieveAtIndex(dataOut, index))
	{
		cout << "\nRetrieved " << dataOut << " at [" << index << "]." << endl;
	}
	else
		cout << "\nUnable to retrieve." << endl;

	dataOut = 3;
	if (shortList.retrieve(dataOut))
	{
		cout << "\nRetrieved " << dataOut << "." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to retrieve." << endl;

	dataIn = 3;
	if (shortList.updateFront(dataIn))
	{
		cout << "\nUpdated " << dataIn << " at front." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to update the value " << dataIn << "." << endl;

	dataIn = 0;
	if (shortList.updateBack(dataIn))
	{
		cout << "\nUpdated " << dataIn << " at back." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to update the value " << dataIn << "." << endl;

	dataIn = 12;
	index = 2;
	if (shortList.updateAtIndex(dataIn, index))
	{
		cout << "\nUpdated " << dataIn << " at [" << index << "]." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to update the value " << dataIn << " at [" << index << "]." << endl;

	dataIn = 17;
	index = 8;
	if (shortList.updateAtIndex(dataIn, index))
	{
		cout << "\nUpdated " << dataIn << " at [" << index << "]." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to update the value " << dataIn << " at [" << index << "]." << endl;

	dataIn = 5;
	if (shortList.update(dataIn))
	{
		cout << "\nUpdated " << dataIn << "." << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nUnable to update the value " << dataIn << "." << endl;

	if (shortList.clear())
	{
		cout << "\nCleared list!" << endl;
		shortList.display();
		if (!shortList.getSmallest(min))
		{
			min = 0;
		}
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
		cout << "\nCouldn't clear list." << endl;

	if (shortList.isEmpty())
	{
		cout << "\nList is empty" << endl;
	}
	else
		cout << "\nList is not empty" << endl;

	return 0;
}

//*****************************************************************************************************

/*

Inserted 3 at front.
[0] 3
capacity is 3    numValues is 1  smallest value is 3

Inserted 1 at back.
[0] 3   [1] 1
capacity is 3    numValues is 2  smallest value is 1

Inserted 1 at front.
[0] 1   [1] 3   [2] 1
capacity is 3    numValues is 3  smallest value is 1

Inserted 8 at [1].
[0] 1   [1] 8   [2] 3   [3] 1
capacity is 6    numValues is 4  smallest value is 1

List is not full

List is not empty

Removed 1 at front.
[0] 8   [1] 3   [2] 1
capacity is 6    numValues is 3  smallest value is 1

Removed first 3.
[0] 8   [1] 1
capacity is 6    numValues is 2  smallest value is 1

Removed 1 at [1].
[0] 8
capacity is 6    numValues is 1  smallest value is 8

Unable to remove the value at [2]

Removed 8 at back.

capacity is 6    numValues is 0  smallest value is 0

List is empty

Inserted values from 1 to 6.
[0] 1   [1] 2   [2] 3   [3] 4   [4] 5   [5] 6

List is full

Retrieved 1 at front.

Retrieved 6 at back.

Unable to retrieve.

Retrieved 5 at [4].

Retrieved 3.
[0] 1   [1] 2   [2] 3   [3] 4   [4] 5   [5] 6
capacity is 6    numValues is 6  smallest value is 1

Updated 3 at front.
[0] 3   [1] 2   [2] 3   [3] 4   [4] 5   [5] 6
capacity is 6    numValues is 6  smallest value is 2

Updated 0 at back.
[0] 3   [1] 2   [2] 3   [3] 4   [4] 5   [5] 0
capacity is 6    numValues is 6  smallest value is 0

Updated 12 at [2].
[0] 3   [1] 2   [2] 12  [3] 4   [4] 5   [5] 0
capacity is 6    numValues is 6  smallest value is 0

Unable to update the value 17 at [8].

Updated 5.
[0] 3   [1] 2   [2] 12  [3] 4   [4] 5   [5] 0
capacity is 6    numValues is 6  smallest value is 0

Cleared list!

capacity is 6    numValues is 0  smallest value is 0

List is empty

*/