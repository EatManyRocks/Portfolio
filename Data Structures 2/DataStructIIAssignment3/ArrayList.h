//*****************************************************************************************************
//
//		File:					ArrayList.h
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
//		This is the header for the array list class that stores items in an array.
//	
//		Other files required: 
//			1.	main.cpp
//			2.  Stock.cpp
//			3.  Stock.h
//			
//			
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H

//*****************************************************************************************************

#include <new>

//*****************************************************************************************************

template <typename TYPE>
class ArrayList
{
private:
	TYPE* array;
	int size;
	int numValues;

	void _binarySearchRec(const TYPE& item, int first = 0, int last = size, int& loc = 0) const;
	void _resize();
public:
	ArrayList(int s = 10);
	ArrayList(const ArrayList<TYPE>& a);
	~ArrayList();
	void insert(const TYPE& item);
	bool isFull() const;
	bool isEmpty() const;
	int listSize() const;
	void print() const;
	int binarySearch(const TYPE& item) const;
};

//*****************************************************************************************************

template <typename TYPE>
ArrayList<TYPE>::ArrayList(int s)
{
	
	if (s < 1)
		s = 1;

	size = s;
	array = new TYPE[size];
	numValues = 0;
}

//*****************************************************************************************************


template <typename TYPE>
ArrayList<TYPE>::ArrayList(const ArrayList<TYPE>& a)
{
	size = a.size;
	numValues = a.numValues;
	array = new TYPE[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = a.array[i];
	}
}

//*****************************************************************************************************

template <typename TYPE>
ArrayList<TYPE>::~ArrayList()
{
	delete[] array;
	size = 0;
	numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
void ArrayList<TYPE>::insert(const TYPE& item)
{
	int loc = 0;
	bool found = false;

	for (int i = 0; (i < numValues) && (!found); i++)
	{
		if (item < array[i])
		{
			loc = i;
			found = true;
		}
	}

	if (numValues >= size)
	{
		_resize();
	}

	for (int i = numValues; i > loc; i--)
	{
		array[i] = array[i - 1];
	}

	array[loc] = item;
	numValues++;
}

//*****************************************************************************************************

template <typename TYPE>
inline bool ArrayList<TYPE>::isFull() const
{
	return (numValues == size);
}

//*****************************************************************************************************

template <typename TYPE>
inline bool ArrayList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

template <typename TYPE>
inline int ArrayList<TYPE>::listSize() const
{
	return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
void ArrayList<TYPE>::print() const
{
	for (int i = 0; i < numValues; i++)
	{
		cout << "[" << array[i] << "]  ";
	}

	cout << endl;
}

//*****************************************************************************************************

template <typename TYPE>
int ArrayList<TYPE>::binarySearch(const TYPE& item) const
{
	int loc;

	_binarySearchRec(item, 0, numValues, loc);

	return loc;
}

//*****************************************************************************************************

template <typename TYPE>
void ArrayList<TYPE>::_binarySearchRec(const TYPE& item, int first, int last, int& loc) const
{
	{
		if (first > last) {
			loc = -1;
		}
		else {
			loc = (first + last) / 2;
			if (item > array[loc]) {
				_binarySearchRec(item, first, loc - 1, loc);
			}
			else if (item < array[loc]) {
				_binarySearchRec(item, loc + 1, last, loc);
			}
		}
	}
}

//*****************************************************************************************************

template <typename TYPE>
void ArrayList<TYPE>::_resize()
{
	TYPE* newArray;

	size += 10;
	newArray = new TYPE[size];

	for (int i = 0; i < numValues; i++)
	{
		newArray[i] = array[i];
	}

	delete[] array; 
	array = newArray;
}

//*****************************************************************************************************

#endif