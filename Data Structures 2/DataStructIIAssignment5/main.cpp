//*****************************************************************************************************
//
//		File:					main.cpp
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
//		This program is the driver.
//	
//		Other files required: 
//			1.	ArrayList.h
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  Stock.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "ArrayList.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{
	ArrayList<Stock> stockList(10);
	ifstream stockFile("Stock.txt");
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

			stockList.insert(newStock);
		}

		stockList.print();
		cout << endl;

		stockFile.close();
		stockFile.open("Stock.txt");

		getline(stockFile, name);
		getline(stockFile, symbol);
		getline(stockFile, price);

		Stock firstStock(name, symbol, stod(price));

		stockList.remove(firstStock);

		stockList.print();
		cout << endl;

		stockList.removeRange(1, 3);

		stockList.print();
		cout << endl;

		stockFile.close();
	}

	return 0;
}

//*****************************************************************************************************

/*
(1)     [Apple/AAPL]
(2)     [Advanced Micro Devices/AMD]
(3)     [Ford Motor/F]
(4)     [General Electric/GE]
(5)     [Intel/INTC]
(6)     [NVIDIA/NVDA]
(7)     [Sony/SNE]
(8)     [Tesla/TSLA]
(9)     [Microsoft Corp./MSFT]
(10)    [Motorola Inc./MOT]

(1)     [Apple/AAPL]
(2)     [Advanced Micro Devices/AMD]
(3)     [Ford Motor/F]
(4)     [General Electric/GE]
(5)     [Intel/INTC]
(6)     [NVIDIA/NVDA]
(7)     [Sony/SNE]
(8)     [Tesla/TSLA]
(9)     [Microsoft Corp./MSFT]

(1)     [General Electric/GE]
(2)     [Intel/INTC]
(3)     [NVIDIA/NVDA]
(4)     [Sony/SNE]
(5)     [Tesla/TSLA]
(6)     [Microsoft Corp./MSFT]
*/