//***************************************************************
//
//		Assignment:		#16
// 
//		File:			RussAssignment16.cpp
// 
//		Due Date:		November 4, 2022
//
//		Author:			Ryan Russell
//
//
//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Calculates the occupancy rate for a hotel
//						using a for loop.
//
//
//***************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float totalRoomNum = 0;
	double userRoomNum = 0;
	int floorNum = 0;
	float totalOccupancy = 0;
	double userOccupancy = 0;
	double occupyRate;

	cout << "How many floors does the hotel have? ";
	cin >> floorNum;
	while (floorNum < 1)
	{
		cout << "Please enter a number greater than 0: ";
		cin >> floorNum;
	}
	for (int f = 1; f <= floorNum; f++)
	{
		userOccupancy = 0;
		userRoomNum = 0;
		cout << "How many rooms on floor " << f << "? ";
		cin >> userRoomNum;
		while (userRoomNum < 1)
		{
			cout << "Please enter a number greater than 0: ";
			cin >> userRoomNum;
		}
		cout << "How many of those rooms are occupied? ";
		cin >> userOccupancy;
		while (userOccupancy > userRoomNum || userOccupancy < 0)
		{
			cout << "Please enter a valid number: ";
			cin >> userOccupancy;
		}
		totalOccupancy += userOccupancy;
		totalRoomNum += userRoomNum;
	}
	cout << "The hotel has total of " << totalRoomNum << " rooms." << endl;
	cout << totalOccupancy << " are occupied." << endl;
	cout << (totalRoomNum - totalOccupancy) << " are unoccupied." << endl;
	cout << fixed << setprecision(2);
	occupyRate = (totalOccupancy / totalRoomNum)*100;
	cout << "The occupancy rate is " << occupyRate << "%" << endl;
	return 0;

}

/*
How many floors does the hotel have? -1
Please enter a number greater than 0: 5
How many rooms on floor 1? 10
How many of those rooms are occupied? 4
How many rooms on floor 2? 5
How many of those rooms are occupied? 2
How many rooms on floor 3? 10
How many of those rooms are occupied? 8
How many rooms on floor 4? 5
How many of those rooms are occupied? 5
How many rooms on floor 5? 10
How many of those rooms are occupied? 2
The hotel has total of 40 rooms.
21 are occupied.
19 are unoccupied.
The occupancy rate is 52.50% 

C:\Users\stone\source\repos\Assignment16\Debug\Assignment16.exe (process 28048) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/