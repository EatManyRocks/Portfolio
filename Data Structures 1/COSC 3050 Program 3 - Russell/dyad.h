//*****************************************************************************************************
//
//		File:					dyad.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					2/11/24
//
//
//		This is the header for the Dyad class which has 2 private data members, functions to return
//		first, second, or both values, and a function that swaps the two values. This is using a
//		class template that will be able to take int, double, and char data types.
//	
//		Other files required: 
//			1.	dyadDriver.cpp
//			
//*****************************************************************************************************

#ifndef DYAD_H
#define DYAD_H

//*****************************************************************************************************

template <typename TYPE>
class Dyad
{
private:
	TYPE val1;
	TYPE val2;

public:
	Dyad(TYPE v1 = 0, TYPE v2 = 0);
	~Dyad();
	TYPE getFirst() const;
	TYPE getSecond() const;
	void get2Values(TYPE& v1, TYPE& v2) const;
	void swapValues();
};

//*****************************************************************************************************

template <typename TYPE>
Dyad<TYPE>::Dyad(TYPE v1, TYPE v2)
{
	val1 = v1;
	val2 = v2;
}

//*****************************************************************************************************

template <typename TYPE>
Dyad<TYPE>::~Dyad()
{
	val1 = 0;
	val2 = 0;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getFirst() const
{
	return val1;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getSecond() const
{
	return val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::get2Values(TYPE& v1, TYPE& v2) const
{
	v1 = val1;
	v2 = val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::swapValues()
{
	TYPE temp;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

//*****************************************************************************************************

#endif