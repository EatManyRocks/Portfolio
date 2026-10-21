//*******************************************************************************************************
//
//		File:					NumberArray.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #15
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 15
//
//		Due:					5/8/23
//
//
//		This is the header for the NumberArray class.
//	
//		Other files required: 
//			1.	NumberArrayDriver.cpp
//			2.  NumberArray.cpp
//			
//*******************************************************************************************************

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

//*******************************************************************************************************

class NumberArray
{
private:
	double *arrayPtr;
	int size;
public:
	NumberArray(int = 5);
	~NumberArray();
	void setCell(int, double);
	double getCell(int) const;
	double getAverage() const;
	double getHighest() const;
	double getLowest() const;
};

//*******************************************************************************************************

#endif
