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
//		This program is the driver.
//	
//		Other files required: 
//			1.	SortedList.h
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  Stock.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#include "SortedList.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{
	SortedList<Stock> sortedStocks(10);
	fstream stockFile("Stock.txt", ios::in);
	string name;
	string symbol;
	string price;

	if (stockFile.is_open())
	{
		while (getline(stockFile, name))
		{
			getline(stockFile, symbol);
			getline(stockFile, price);

			Stock newStock(name, symbol, stod(price));

			sortedStocks.insert(newStock);
		}

		stockFile.close();

		cout << "Initial Array: " << endl;
		sortedStocks.display();

		cout << "\n\nRandomized Array: " << endl;
		sortedStocks.randomize();
		sortedStocks.display();

		cout << "\n\nSelection Sort Ascending: " << endl;
		sortedStocks.randomize();
		sortedStocks.selectionSortA();
		sortedStocks.display();

		cout << "\n\nSelection Sort Descending: " << endl;
		sortedStocks.randomize();
		sortedStocks.selectionSortD();
		sortedStocks.display();

		cout << "\n\nQuick Sort Ascending: " << endl;
		sortedStocks.randomize();
		sortedStocks.quickSortA();
		sortedStocks.display();

		cout << "\n\nQuick Sort Descending: " << endl;
		sortedStocks.randomize();
		sortedStocks.quickSortD();
		sortedStocks.display();

		cout << "\n\nHeap Sort Ascending: " << endl;
		sortedStocks.randomize();
		sortedStocks.heapSortA();
		sortedStocks.display();

		cout << "\n\nHeap Sort Descending: " << endl;
		sortedStocks.randomize();
		sortedStocks.heapSortD();
		sortedStocks.display();
	}

	return 0;
}

//*****************************************************************************************************

/*
Initial Array:
Tesla
TSLA
564.33

Sony
SNE
105.81

NVIDIA
NVDA
548.58

Microsoft Corp.
MSFT
28.11

Motorola Inc.
MOT
17.49

Intel
INTC
60.78

General Electric
GE
12.54

Ford Motor
F
11.7

Bob Inc.
BOB
11.11

Advanced Micro Devices
AMD
84.51

Apple
AAPL
121.73



Randomized Array:
Advanced Micro Devices
AMD
84.51

NVIDIA
NVDA
548.58

Ford Motor
F
11.7

Intel
INTC
60.78

Sony
SNE
105.81

Motorola Inc.
MOT
17.49

Bob Inc.
BOB
11.11

General Electric
GE
12.54

Microsoft Corp.
MSFT
28.11

Tesla
TSLA
564.33

Apple
AAPL
121.73



Selection Sort Ascending:
Apple
AAPL
121.73

Advanced Micro Devices
AMD
84.51

Bob Inc.
BOB
11.11

Ford Motor
F
11.7

General Electric
GE
12.54

Intel
INTC
60.78

Motorola Inc.
MOT
17.49

Microsoft Corp.
MSFT
28.11

NVIDIA
NVDA
548.58

Sony
SNE
105.81

Tesla
TSLA
564.33



Selection Sort Descending:
Tesla
TSLA
564.33

Sony
SNE
105.81

NVIDIA
NVDA
548.58

Microsoft Corp.
MSFT
28.11

Motorola Inc.
MOT
17.49

Intel
INTC
60.78

General Electric
GE
12.54

Ford Motor
F
11.7

Bob Inc.
BOB
11.11

Advanced Micro Devices
AMD
84.51

Apple
AAPL
121.73



Quick Sort Ascending:
Apple
AAPL
121.73

Advanced Micro Devices
AMD
84.51

Bob Inc.
BOB
11.11

Ford Motor
F
11.7

General Electric
GE
12.54

Intel
INTC
60.78

Motorola Inc.
MOT
17.49

Microsoft Corp.
MSFT
28.11

NVIDIA
NVDA
548.58

Sony
SNE
105.81

Tesla
TSLA
564.33



Quick Sort Descending:
Tesla
TSLA
564.33

Sony
SNE
105.81

NVIDIA
NVDA
548.58

Microsoft Corp.
MSFT
28.11

Motorola Inc.
MOT
17.49

Intel
INTC
60.78

General Electric
GE
12.54

Ford Motor
F
11.7

Bob Inc.
BOB
11.11

Advanced Micro Devices
AMD
84.51

Apple
AAPL
121.73



Heap Sort Ascending:
Apple
AAPL
121.73

Advanced Micro Devices
AMD
84.51

Bob Inc.
BOB
11.11

Ford Motor
F
11.7

General Electric
GE
12.54

Intel
INTC
60.78

Motorola Inc.
MOT
17.49

Microsoft Corp.
MSFT
28.11

NVIDIA
NVDA
548.58

Sony
SNE
105.81

Tesla
TSLA
564.33



Heap Sort Descending:
Tesla
TSLA
564.33

Sony
SNE
105.81

NVIDIA
NVDA
548.58

Microsoft Corp.
MSFT
28.11

Motorola Inc.
MOT
17.49

Intel
INTC
60.78

General Electric
GE
12.54

Ford Motor
F
11.7

Bob Inc.
BOB
11.11

Advanced Micro Devices
AMD
84.51

Apple
AAPL
121.73
*/