//*****************************************************************************************************
//
//		File:					SortedList.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 10
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/25/24
//
//
//		This is the header for the sorted list class which contains options to use selection sort,
//		quick sort, and heap sort both in ascending and descending order.
//	
//		Other files required: 
//			1.	main.cpp
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  Stock.txt
//			
//			
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//*****************************************************************************************************

#include <new>
#include <cstdlib>
#include <ctime>

//*****************************************************************************************************

template <typename TYPE>
class SortedList
{
private:
	TYPE* array;
	int size;
	int numValues;

	void _resize();
	int partition(TYPE arr[], int low, int high, bool ascending);
	void quickSort(TYPE arr[], int low, int high, bool ascending);
	void heapify(TYPE arr[], int n, int root, bool ascending);
	void heapSort(TYPE arr[], int n, bool ascending);
public:
	SortedList(int s = 10);
	SortedList(const SortedList<TYPE>& a);
	~SortedList();
	void insert(const TYPE& item);
	void randomize();
	void selectionSortA();
	void selectionSortD();
	void quickSortA();
	void quickSortD();
	void heapSortA();
	void heapSortD();
	void display(ostream& os = cout) const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
SortedList<TYPE>::SortedList(int s)
{

	if (s < 1)
		s = 1;

	size = s;
	array = new TYPE[size];
	numValues = 0;
}

//*****************************************************************************************************


template <typename TYPE>
SortedList<TYPE>::SortedList(const SortedList<TYPE>& a)
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
SortedList<TYPE>::~SortedList()
{
	delete[] array;
	size = 0;
	numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::insert(const TYPE& item)
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
void SortedList<TYPE>::randomize()
{
	int randNum = 0;
	srand(static_cast<unsigned int>(time(nullptr)));

	for (int i = 0; i < (numValues - 1); i++)
	{
		randNum = rand() % (numValues - i);
		swap(array[i], array[randNum]);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::selectionSortA()
{
	int min = 0;

	for (int i = 0; i < numValues - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < numValues; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		swap(array[i], array[min]);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::selectionSortD()
{
	int max = 0;

	for (int i = 0; i < numValues - 1; i++)
	{
		max = i;

		for (int j = i + 1; j < numValues; j++)
		{
			if (array[j] > array[max])
				max = j;
		}

		swap(array[i], array[max]);
	}
}

//*****************************************************************************************************

template <typename TYPE>
int SortedList<TYPE>::partition(TYPE arr[], int low, int high, bool ascending)
{
	TYPE pivot = arr[(low + high) / 2];
	swap(arr[low], arr[(low + high) / 2]);
	int smallIndex = low;

	for (int i = low + 1; i <= high; ++i) 
	{
		if ((ascending && arr[i] < pivot) || (!ascending && arr[i] > pivot))
		{
			++smallIndex;
			swap(arr[smallIndex], arr[i]);
		}
	}

	std::swap(arr[low], arr[smallIndex]);

	return smallIndex;
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::quickSortA()
{
	quickSort(array, 0, numValues - 1, true);
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::quickSortD()
{
	quickSort(array, 0, numValues - 1, false);
}

//*****************************************************************************************************


template <typename TYPE>
void SortedList<TYPE>::quickSort(TYPE arr[], int low, int high, bool ascending)
{
	if (low < high) {
		int pivotLoc = partition(arr, low, high, ascending);
		quickSort(arr, low, pivotLoc - 1, ascending);
		quickSort(arr, pivotLoc + 1, high, ascending);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::heapify(TYPE arr[], int n, int root, bool ascending)
{
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (ascending)
	{
		if ((l < n) && (arr[l] > arr[largest])) 
		{
			largest = l;
		}
		if ((r < n) && (arr[r] > arr[largest])) 
		{
			largest = r;
		}
	}
	else
	{
		if ((l < n) && (arr[l] < arr[largest]))
		{
			largest = l;
		}
		if ((r < n) && (arr[r] < arr[largest]))
		{
			largest = r;
		}
	}
	if (largest != root) 
	{
		swap(arr[root], arr[largest]);
		heapify(arr, n, largest, ascending);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::heapSort(TYPE arr[], int n, bool ascending)
{
	for (int i = n / 2 - 1; i >= 0; i--) 
	{ 
		heapify(arr, n, i, ascending);
	}
	for (int i = n - 1; i >= 0; i--) 
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0, ascending);
	}
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::heapSortA()
{
	heapSort(array, numValues, true);
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::heapSortD()
{
	heapSort(array, numValues, false);
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::display(ostream& os) const
{
	for (int i = 0; i < numValues; i++)
	{
		os << array[i] << endl;
	}
}

//*****************************************************************************************************

template <typename TYPE>
inline bool SortedList<TYPE>::isFull() const
{
	return (numValues == size);
}

//*****************************************************************************************************

template <typename TYPE>
inline bool SortedList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

template <typename TYPE>
void SortedList<TYPE>::_resize()
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