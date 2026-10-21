//*******************************************************************************************************
//
//		File:					CustomerRecord.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #10
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 10
//
//		Due:					4/2/23
//
//
//		This program stores, displays, and counts customer records using read and write from a binary file.
//	
//		Other files required: 
//			1.	none
//			
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int getChoice();
void handleMenu(fstream& fin);
void addRecord(fstream& fout);
void displayOneCustomer(fstream& fin);
double countRecord(fstream& fin);
void displayAllCustomer(fstream& fin);

//*******************************************************************************************************

struct Customer
{
	char name[50];
	char address[50];
	double accountBalance;
	int id;
};

//*******************************************************************************************************

int main()
{
	ofstream ofs;
	ofs.open("CustomerRecords.dat", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	fstream CustFile;


	handleMenu(CustFile);

	return 0;
}

//*******************************************************************************************************

int getChoice()
{
	int ch = 0;
	cout << string(40, '*') << endl;
	cout << "1. Enter new records into the file" << endl;
	cout << "2. Search for a particular customer record and display it" << endl;
	cout << "3. Count customer record" << endl;
	cout << "4. Display the contents of the entire file." << endl;
	cout << "5. Quit" << endl;
	cout << "\nPlease Enter: ";
	cin >> ch;
	return ch;
}

//*******************************************************************************************************

void handleMenu(fstream& fin)
{
	bool running = true;
	while (running)
	{
		double cnt = 0;
		int choice = getChoice();
		switch (choice)
		{
		case 1:
			addRecord(fin);
			break;
		case 2:
			displayOneCustomer(fin);
			break;
		case 3:
			cnt = countRecord(fin);
			if (cnt == -1)
			{
				cout << "Error opening file.\n";
				break;
			}
			cout << "There are ";
			cout << cnt;
			cout << " customer records in the file." << endl;
			break;
		case 4:
			displayAllCustomer(fin);
			break;
		case 5:
			running = false;
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "\nERROR: Invalid Input" << endl;
		}
		cin.ignore();
	}
}

//*******************************************************************************************************

void addRecord(fstream& fout)
{
	Customer info;
	fout.open("CustomerRecords.dat", ios::out | ios::app | ios::binary);
	if (!fout)
	{
		cout << "Error opening file.\n";
		return;
	}

	cin.ignore();
	cout << "Customer Name: ";
	cin.getline(info.name, 50);
	cout << "Customer Address: ";
	cin.getline(info.address, 50);
	cout << "Customer Id: ";
	cin >> info.id;
	cout << "Account Balance: ";
	cin >> info.accountBalance;

	fout.write(reinterpret_cast<char*>(&info), sizeof(info));

	cin.ignore();

	fout.close();
}

//*******************************************************************************************************

void displayOneCustomer(fstream& fin)
{
	Customer info;
	long custNum = 0;

	fin.open("CustomerRecords.dat", ios::in | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
		return;
	}


	cout << "Enter the record number: ";
	cin >> custNum;

	cout << "Here is record ";
	cout << custNum << endl;

	long byteNum = (sizeof(info) * custNum);

	fin.seekg(byteNum, ios::beg);

	fin.read(reinterpret_cast<char*>(&info), sizeof(info));
	cout << "Name: ";
	cout << info.name << endl;
	cout << "Address: ";
	cout << info.address << endl;
	cout << "Id: ";
	cout << info.id << endl;
	cout << "Account Balance: ";
	cout << info.accountBalance << endl;

	fin.close();
}

//*******************************************************************************************************

double countRecord(fstream& fin)
{
	Customer info;
	fin.open("CustomerRecords.dat", ios::in | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
		return -1;
	}

	fin.seekg(0L, ios::end);
	double bytes = fin.tellg();
	double recordNum = bytes / (sizeof(info));

	fin.close();
	return recordNum;
}

//*******************************************************************************************************

void displayAllCustomer(fstream& fin)
{
	Customer info;

	fin.open("CustomerRecords.dat", ios::in | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
		return;
	}

	cout << "Here are all customers in the file:" << endl;

	fin.seekg(0L, ios::beg); //just in case the file isn't at the start
	

	//The last customer entry is repeated again.
	//I'm not sure how to fix this problem.

	do 
	{
		fin.read(reinterpret_cast<char*>(&info), sizeof(info));
		cout << "\nName: ";
		cout << info.name << endl;
		cout << "Address: ";
		cout << info.address << endl;
		cout << "Id: ";
		cout << info.id << endl;
		cout << "Account Balance: ";
		cout << info.accountBalance << endl;
	} while (!fin.eof());

	fin.close();
}

//*******************************************************************************************************

/*****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 1
Customer Name: John Doe
Customer Address: 123 Webster St.
Customer Id: 1001
Account Balance: 10.5

****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 3
There are 1 customer records in the file.
****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 1
Customer Name: Jane Doe
Customer Address: 123 Gorlok St.
Customer Id: 1002
Account Balance: 0

****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 3
There are 2 customer records in the file.
****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 2
Enter the record number: 1
Here is record 1
Name: Jane Doe
Address: 123 Gorlok St.
Id: 1002
Account Balance: 0
****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 4
Here are all customers in the file:

Name: John Doe
Address: 123 Webster St.
Id: 1001
Account Balance: 10.5

Name: Jane Doe
Address: 123 Gorlok St.
Id: 1002
Account Balance: 0

Name: Jane Doe
Address: 123 Gorlok St.
Id: 1002
Account Balance: 0
****************************************
1. Enter new records into the file
2. Search for a particular customer record and display it
3. Count customer record
4. Display the contents of the entire file.
5. Quit

Please Enter: 5
Goodbye!

C:\Users\stone\source\repos\RussCustomerReport\Debug\RussCustomerReport.exe (process 29836) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/