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

#ifndef HASHTABLE_H
#define HASHTABLE_H

//*****************************************************************************************************

#include "HTElement.h"

//*****************************************************************************************************

template <typename TYPE>
class HashTable
{
private:
	HTElement<TYPE>* table;
	int size;
public:
	HashTable(int s = 10);
	~HashTable();
	void remove(const TYPE& item);
	void insert(const TYPE& item);
	void display() const;
	TYPE* search(const TYPE& item) const;
};

//*****************************************************************************************************

template <typename TYPE>
HashTable<TYPE>::HashTable(int s)
{
	if (s < 5)
		s = 5;

	size = s;
	table = new HTElement<TYPE>[size];
}

//*****************************************************************************************************

template <typename TYPE>
HashTable<TYPE>::~HashTable()
{
	size = 0;
	delete[] table;
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::remove(const TYPE& item)
{
	int hash;
	int index;
	int count = 0;
	hash = item.hash(size);
	index = hash % 10;

	while (table[index].status != 0 && table[index].item != item);
	{
		count++;
		index = (hash + (count * count)) % 10;
	}

	if (table[index].status == 1 && table[index].item == item)
	{
		table[index].status = -1;
	}
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::insert(const TYPE& item)
{
	int hash;
	int index;
	int count = 0;
	hash = item.hash(size);
	index = hash % 10;

	cout << "insert loop begins" << endl;

	while (table[index].status == 1);
	{
		cout << "curr index: " << index << endl;
		count++;
		index = (hash + (count * count)) % 10;
	}
	
	if (table[index].status != 1)
	{
		table[index].item = item;
		table[index].status = 1;
	}

	cout << "insert loop ends" << endl;
}

//*****************************************************************************************************

template <typename TYPE>
void HashTable<TYPE>::display() const
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].status == 1)
		{
			cout << table[i].item << "\t";
		}
	}

	cout << endl;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE* HashTable<TYPE>::search(const TYPE& item) const
{
	int hash;
	int index;
	int count = 0;
	TYPE* itemPtr = nullptr;
	hash = item.hash(size);
	index = hash % 10;

	while (table[index].status != 0 && table[index].item != item);
	{
		count++;
		index = (hash + (count * count)) % 10;
	}

	if (table[index].status == 1 && table[index].item == item)
	{
		itemPtr = &(table[index].item);
	}

	return nullptr;
}

//*****************************************************************************************************

#endif