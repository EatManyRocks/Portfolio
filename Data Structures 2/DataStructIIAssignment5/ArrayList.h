//*****************************************************************************************************
//
//		File:					ArrayList.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 5
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					9/30/24
//
//
//		This is the header for the array list class that stores items in an array.
//	
//		Other files required: 
//			1.	main.cpp
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  Stock.txt
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
	void print(ostream& os = cout) const;
	int binarySearch(const TYPE& item) const;
	bool remove(const TYPE& item);
	bool removeRange(int a, int b);
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
void ArrayList<TYPE>::print(ostream& os) const
{
	for (int i = 0; i < numValues; i++)
	{
		os << "(" << i + 1 << ")\t[" << array[i] << "]  " << endl;
	}
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

template<typename TYPE>
bool ArrayList<TYPE>::remove(const TYPE& item)
{
	bool success = false;
	int loc;

	loc = binarySearch(item);

	if (loc != -1)
	{
		numValues--;

		for (int i = loc; i < numValues; i++)
		{
			array[i] = array[i + 1];
		}
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool ArrayList<TYPE>::removeRange(int a, int b)
{
	bool success = false;
	int prevVals = numValues;

	if (a < b && b <= numValues)
	{
		numValues -= b - a + 1;

		for (int i = a - 1; b < prevVals; i++)
		{
			array[i] = array[b];
			b++;
		}

		success = true;
	}

	return success;
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