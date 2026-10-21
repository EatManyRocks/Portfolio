//*****************************************************************************************************
//
//		File:					qDriver.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #7
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					3/28/24
//
//
//		This program is the driver that proves the correctness of the queue class.
//	
//		Other files required: 
//			1.	queue.h
//			2.  node.h
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "queue.h"

//*****************************************************************************************************

int main()
{
	Queue<double> doubleQ;
	double num = 0;

	if (doubleQ.dequeue(num))
		cout << "dequeued " << num << endl;
	else
		cout << "failed to dequeue" << endl;

	if (doubleQ.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;

	num = 5;
	if (doubleQ.enqueue(num))
		cout << "enqueued " << num << endl;
	else
		cout << "failed to enqueue" << endl;

	num = 6;
	if (doubleQ.enqueue(num))
		cout << "enqueued " << num << endl;
	else
		cout << "failed to enqueue" << endl;

	num = 7;
	if (doubleQ.enqueue(num))
		cout << "enqueued " << num << endl;
	else
		cout << "failed to enqueue" << endl;

	if (doubleQ.viewFront(num))
		cout << "viewed front: " << num << endl;
	else
		cout << "failed to view front" << endl;

	if (doubleQ.viewRear(num))
		cout << "viewed rear: " << num << endl;
	else
		cout << "failed to view rear" << endl;

	cout << "Number of values: " << doubleQ.getNumValues() << endl;

	if (doubleQ.isFull())
		cout << "Queue is full" << endl;
	else
		cout << "Queue is not full" << endl;

	if (doubleQ.isEmpty())
		cout << "Queue is empty" << endl;
	else
		cout << "Queue is not empty" << endl;

	if (doubleQ.dequeue(num))
		cout << "dequeued " << num << endl;
	else
		cout << "failed to dequeue" << endl;

	if (doubleQ.dequeue(num))
		cout << "dequeued " << num << endl;
	else
		cout << "failed to dequeue" << endl;

	if (doubleQ.viewFront(num))
		cout << "viewed front: " << num << endl;
	else
		cout << "failed to view front" << endl;

	if (doubleQ.viewRear(num))
		cout << "viewed rear: " << num << endl;
	else
		cout << "failed to view rear" << endl;

	cout << "Number of values: " << doubleQ.getNumValues() << endl;

	return 0;
}

//*****************************************************************************************************

/*
failed to dequeue
Queue is empty
enqueued 5
enqueued 6
enqueued 7
viewed front: 5
viewed rear: 7
Number of values: 3
Queue is not full
Queue is not empty
dequeued 5
dequeued 6
viewed front: 7
viewed rear: 7
Number of values: 1
*/