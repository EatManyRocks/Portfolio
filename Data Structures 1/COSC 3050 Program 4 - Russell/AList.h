//*****************************************************************************************************
//
//		File:					AList.h
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
//		This is the header for the AList class which has 4 private data members, 3 insert functions
//		and 1 private "helper" function, 4 remove functions, 4 retrieve functions, 4 update functions,
//		and 7 "utility" functions. Uses a dynamic array to store items. 
//	
//		Other files required: 
//			1.	driverAList.cpp
//			
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H

//*****************************************************************************************************

#include <new>

//*****************************************************************************************************

template <typename TYPE>
class AList
{
private:
	TYPE* list;
	int capacity;
	int numValues;
	bool _resize();
public:
	AList(int cap = 5);
	~AList();
	bool insertFront(const TYPE& dataIn);
	bool insertBack(const TYPE& dataIn);
	bool insertAtIndex(const TYPE& dataIn, int index);
	bool removeFront(TYPE& dataOut);
	bool removeBack(TYPE& dataOut);
	bool removeAtIndex(TYPE& dataOut, int index);
	bool remove(TYPE& dataOut);
	bool retrieveFront(TYPE& dataOut) const;
	bool retrieveBack(TYPE& dataOut) const;
	bool retrieveAtIndex(TYPE& dataOut, int index) const;
	bool retrieve(TYPE& dataOut) const;
	bool updateFront(const TYPE& dataIn);
	bool updateBack(const TYPE& dataIn);
	bool updateAtIndex(const TYPE& dataIn, int index);
	bool update(const TYPE& dataIn);
	bool display() const;
	bool getSmallest(TYPE& dataOut) const;
	int getCapacity() const;
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;
	bool clear();
};

//*****************************************************************************************************

template <typename TYPE>
AList<TYPE>::AList(int cap)
{
	if (cap < 2)
		cap = 2;

	capacity = cap;
	numValues = 0;
	list = new TYPE[capacity];
}


//*****************************************************************************************************

template <typename TYPE>
AList<TYPE>::~AList()
{
	delete[] list;
	numValues = 0;
	capacity = 0;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::_resize()
{
	bool success = false;
	int newCap;
	TYPE* newList;

	newCap = 2 * capacity;
	newList = new(nothrow) TYPE[newCap];

	if (newList != nullptr)
	{
		for (int i = 0; i < numValues; i++)
		{
			newList[i] = list[i];
		}

		capacity = newCap;
		delete[] list;
		list = newList;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertFront(const TYPE& dataIn)
{
	bool success = true;

	if (numValues >= capacity)
	{
		success = _resize();
	}

	if (success)
	{
		for (int i = numValues; i > 0; i--)
		{
			list[i] = list[i - 1];
		}

		list[0] = dataIn;
		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertBack(const TYPE& dataIn)
{
	bool success = true;

	if (numValues >= capacity)
	{
		success = _resize();
	}

	if (success)
	{
		list[numValues] = dataIn;
		numValues++;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::insertAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ((index >= 0) && (index <= numValues))
	{
		success = true;

		if (numValues >= capacity)
		{
			success = _resize();
		}

		if (success)
		{
			for (int i = numValues; i > index; i--)
			{
				list[i] = list[i - 1];
			}

			list[index] = dataIn;
			numValues++;
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeFront(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];
		numValues--;

		for (int i = 0; i < numValues; i++)
		{
			list[i] = list[i + 1];
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeBack(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues - 1];
		numValues--;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::removeAtIndex(TYPE& dataOut, int index)
{
	bool success = false;

	if (numValues > 0)
	{
		if ((index >= 0) && (index < numValues))
		{
			dataOut = list[index];
			numValues--;

			for (int i = index; i < numValues; i++)
			{
				list[i] = list[i + 1];
			}

			success = true;
		}

		return success;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::remove(TYPE& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; (i < numValues) && (!success); i++)
		{
			if (list[i] == dataOut)
			{
				dataOut = list[i];
				numValues--;

				for (int j = i; j < numValues; j++)
				{
					list[j] = list[j + 1];
				}

				success = true;
			}
		}

		return success;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveFront(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[0];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveBack(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = list[numValues - 1];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieveAtIndex(TYPE& dataOut, int index) const
{
	bool success = false;

	if (numValues > 0)
	{
		if ((index >= 0) && (index < numValues))
		{
			dataOut = list[index];
			success = true;
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::retrieve(TYPE& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; (i < numValues) && (!success); i++)
		{
			if (list[i] == dataOut)
			{
				dataOut = list[i];
				success = true;
			}
		}

		return success;
	}
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateFront(const TYPE& dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		list[0] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateBack(const TYPE& dataIn)
{
	bool success = false;

	if (numValues > 0)
	{
		list[numValues - 1] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::updateAtIndex(const TYPE& dataIn, int index)
{
	bool success = false;

	if ((index >= 0) && (index < numValues))
	{
		list[index] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::update(const TYPE& dataIn)
{
	bool success = false;

	for (int i = 0; (i < numValues) && (!success); i++)
	{
		if (list[i] == dataIn)
		{
			list[i] = dataIn;
			success = true;
		}
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::display() const
{
	bool success = false;

	if (numValues > 0)
	{
		for (int i = 0; i < numValues; i++)
		{
			cout << "[" << i << "] " << list[i] << "\t";
		}

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::getSmallest(TYPE& dataOut) const
{
	bool success = false;
	int smallestIndex;

	if (numValues > 0)
	{
		smallestIndex = 0;

		for (int i = 1; i < numValues; i++)
		{
			if (list[i] < list[smallestIndex])
			{
				smallestIndex = i;
			}
		}

		dataOut = list[smallestIndex];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename TYPE>
int AList<TYPE>::getCapacity() const
{
	return capacity;
}

//*****************************************************************************************************

template <typename TYPE>
int AList<TYPE>::getNumValues() const
{
	return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isEmpty() const
{
	return (numValues == 0);
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isFull() const
{
	return (numValues == capacity);
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::clear()
{
	numValues = 0;

	return true;
}

//*****************************************************************************************************

#endif