//*******************************************************************************************************
//
//		File:					Car.h
//
//		Student:				Ryan Russell
//
//		Assignment:				Week 14 Practice
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 14
//
//		Due:					4/21/23
//
//
//		The Header for the Car class.
//	
//		Other files required: 
//			1.	Car.cpp
//			
//*******************************************************************************************************

#ifndef CAR_H
#define CAR_H

class Car
{
private:
	string make;
	string model;
	int year;
public:
	void setMake(string);
	void setModel(string);
	void setYear(int);
	string getMake() const;
	string getModel() const;
	int getYear() const;
};

#endif