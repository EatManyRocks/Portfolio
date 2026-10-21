//*****************************************************************************************************
//
//		File:					main.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Assignment 8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100
//
//		Due:					11/11/24
//
//
//		This program is the driver.
//	
//		Other files required: 
//			1.	Node.h
//			2.  Stock.h
//			3.  Stock.cpp
//			4.  HuffmanStock.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

#include "Node.h"
#include "Stock.h"

//*****************************************************************************************************

int readStocks(const string& fileName, Stock*& stocks, double*& freqs);
Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size);
void printArray(int path[], int pathLen, Node<Stock>* leaf);
void printPaths(Node<Stock>* root);
void printPaths(Node<Stock>* node, int path[], int pathLen, int lr);
void displayStockList(Node<Stock>* rootPtr, const string& sentence);
void clearTree(Node<Stock>* root);

//*****************************************************************************************************

int main()
{
	Stock* stocks;
	double* freqs;
	int size;
	Node<Stock>* root;

	size = readStocks("HuffmanStocks.txt", stocks, freqs);
	root = createHuffmanTree(stocks, freqs, size);

	printPaths(root);

	string sentence = "0001010";
	displayStockList(root, sentence);
	
	clearTree(root);
	delete[] stocks;
	delete[] freqs;

	return 0;
}

//*****************************************************************************************************

int readStocks(const string& fileName, Stock*& stocks, double*& freqs)
{
	fstream stockFile(fileName, ios::in);
	string name, 
		symbol, 
		price, 
		freq;
	int index = 0;
	int size = 0;

	if (stockFile.is_open())
	{
		getline(stockFile, symbol);
		size = stoi(symbol);

		stocks = new Stock[size];
		freqs = new double[size];

		while (getline(stockFile, name))
		{
			getline(stockFile, symbol);
			getline(stockFile, price);
			getline(stockFile, freq);

			Stock newStock(name, symbol, stod(price));
			stocks[index] = newStock;
			freqs[index] = stod(freq);
			index++;
		}

		stockFile.close();
	}

	return size;
}

//*****************************************************************************************************

Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size)
{
	Node<Stock>** elements = new Node<Stock>*[size];

	for (int i = 0; i < size; i++)
	{
		elements[i] = new Node<Stock>(stocks[i], freqs[i]);
	}

	int index1,
		index2;
	double freq1,
		freq2;

	while (size > 1) {
		index1 = index2 = -1;
		freq1 = freq2 = numeric_limits<double>::max();

		for (int i = 0; i < size; i++)
		{
			if (elements[i]->frequency < freq1)
			{
				freq2 = freq1;
				index2 = index1;
				freq1 = elements[i]->frequency;
				index1 = i;
			}
			else if ((elements[i]->frequency < freq2) && (i != index1))
			{
				freq2 = elements[i]->frequency;
				index2 = i;
			}
		}

		Node<Stock>* parent = new Node<Stock>();
		parent->frequency = freq1 + freq2;
		parent->left = elements[index1];
		parent->right = elements[index2];


		elements[index1] = parent;

		for (int i = index2; i < size - 1; i++)
		{
			elements[i] = elements[i + 1];
		}

		--size;
	}

	Node<Stock>* root = elements[0];

	delete[] elements;

	return root;
}

//*****************************************************************************************************

void printArray(int path[], int pathLen, Node<Stock>* leaf)
{
	cout << leaf->data << " ";
	for (int i = 0; i < pathLen; i++) 
	{
		cout << path[i] << " ";
	}
	cout << endl;
}

//*****************************************************************************************************

void printPaths(Node<Stock>* root)
{
	int path[100];
	printPaths(root, path, 0, -1);
}

//*****************************************************************************************************

void printPaths(Node<Stock>* node, int path[], int pathLen, int lr)
{
	if (node != nullptr) 
	{
		if (lr != -1) 
		{
			path[pathLen] = lr;
			++pathLen;
		}
		if ((node->left == nullptr) && (node->right == nullptr)) 
		{
			printArray(path, pathLen, node);
		}
		else 
		{
			printPaths(node->left, path, pathLen, 0);
			printPaths(node->right, path, pathLen, 1);
		}
	}
}

//*****************************************************************************************************

void displayStockList(Node<Stock>* rootPtr, const string& sentence)
{
	Node<Stock>* curr = rootPtr;

	cout << endl << "Stocks from Sentence:" << endl;

	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == '0' && curr->left)
			curr = curr->left;
		else if (sentence[i] == '1' && curr->right)
			curr = curr->right;

		if (!curr->left && !curr->right)
		{
			cout << curr->data << endl;
			curr = rootPtr;
		}
	}
	
	cout << endl;
}

//*****************************************************************************************************

void clearTree(Node<Stock>* r)
{
	if (r != nullptr)
	{
		clearTree(r->left);
		clearTree(r->right);
		delete r;
		r = nullptr;
	}
}

//*****************************************************************************************************

/*
Home Depot Inc
HD
279.57
 0 0
Coca-Cola Co
KO
53.85
 0 1 0
Cisco Systems Inc
CSCO
42.54
 0 1 1 0
Caterpillar Inc
CAT
173.19
 0 1 1 1 0
Boeing Co
BA
202.4
 0 1 1 1 1 0
Johnson & Johnson
JNJ
150.85
 0 1 1 1 1 1
Goldman Sachs Group Inc
GS
222.38
 1 0
Apple Inc
AAPL
120.3
 1 1 0
Intel Corp
INTC
46.19
 1 1 1 0
American Express Co
AXP
118.67
 1 1 1 1

Stocks from Sentence:
Home Depot Inc
HD
279.57

Coca-Cola Co
KO
53.85

Goldman Sachs Group Inc
GS
222.38
*/