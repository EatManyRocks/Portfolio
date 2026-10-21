//*******************************************************************************************************
//
//		File:					CustomerRecord2.cpp
//
//		Student:				Ryan Russell
//
//		Assignment:				Program #11
//
//		Course Name:			Programming II
//
//		Course Number:			COSC 1560-Week 11
//
//		Due:					4/10/23
//
//
//		This program allows a user to add, display, edit, and delete customer records using read and write from a binary file.
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

//*******************************************************************************************************

int getChoice();
void handleMenu(fstream& fin);
void addRecord(fstream& fout);
void displayOneCustomer(fstream& fin);
void deleteRecord(fstream& fin);
void editRecord(fstream& fin);
void displayAllCustomer(fstream& fin);

//*******************************************************************************************************

struct Customer
{
	char name[51];
	char address[51];
	double accountBalance;
	int id;
};

//*******************************************************************************************************

int main()
{
	ofstream ofs;
	ofs.open("CustomerRecords.dat", ofstream::out | ofstream::trunc);
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
	cout << "1. Enter new records into the file." << endl;
	cout << "2. Display a selected record." << endl;
	cout << "3. Edit a selected record." << endl;
	cout << "4. Delete a selected record." << endl;
	cout << "5. Display all records." << endl;
	cout << "6. Quit." << endl;
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
			editRecord(fin);
			break;
		case 4:
			deleteRecord(fin);
			break;
		case 5:
			displayAllCustomer(fin);
			break;
		case 6:
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
	}
	else
	{
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

		fout.close();
	}
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
	}
	else
	{
		cout << "Enter the record number: ";
		cin >> custNum;

		cout << "Here is record ";
		cout << custNum  << ":" << endl;

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
}

//*******************************************************************************************************

void deleteRecord(fstream& fin)
{
	Customer info;
	long custNum = 0;

	fin.open("CustomerRecords.dat", ios::in | ios::out | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
	}
	else
	{
		cout << "Enter the record number: ";
		cin >> custNum;

		long byteNum = (sizeof(info) * custNum);

		cout << "Current information: ";

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

		Customer temp;
		temp.name[0] = '-';

		fin.seekp(byteNum, ios::beg);

		fin.write(reinterpret_cast<char*>(&temp), sizeof(temp));

		fstream fout;
		fout.open("CustomerRecords_COPY.dat", ios::out | ios::binary);

		if (!fout)
		{
			cout << "Error opening file.\n";
		}
		else
		{
			fin.seekg(0L, ios::beg);
			while (fin.read(reinterpret_cast<char*>(&info), sizeof(info)))
			{
				fout.write(reinterpret_cast<char*>(&info), sizeof(info));
			}

			fin.close();
			fout.close();

			fin.open("CustomerRecords.dat", ios::out | ios::binary);
			fout.open("CustomerRecords_COPY.dat", ios::in | ios::binary);

			while (fout.read(reinterpret_cast<char*>(&info), sizeof(info)))
			{
				if (info.name[0] != '-')
				{
					fin.write(reinterpret_cast<char*>(&info), sizeof(info));
				}
			}

			fin.close();
			fout.close();
		}
	}
}

//*******************************************************************************************************

void editRecord(fstream& fin)
{
	Customer info;
	long custNum = 0;

	fin.open("CustomerRecords.dat", ios::in | ios::out | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
	}
	else
	{
		cout << "Enter the record number: ";
		cin >> custNum;

		long byteNum = (sizeof(info) * custNum);

		cout << "Current information: ";

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

		cin.ignore();

		cout << "\nEnter new customer name: ";
		cin.getline(info.name, 50);
		cout << "Enter new customer address: ";
		cin.getline(info.address, 50);
		cout << "Enter new customer ID: ";
		cin >> info.id;
		cin.ignore();
		cout << "Enter new account balance: ";
		cin >> info.accountBalance;
		cin.ignore();

		fin.seekp(byteNum, ios::beg);

		fin.write(reinterpret_cast<char*>(&info), sizeof(info));

		fin.close();
	}
}

//*******************************************************************************************************

void displayAllCustomer(fstream& fin)
{
	Customer info;

	fin.open("CustomerRecords.dat", ios::in | ios::binary);
	if (!fin)
	{
		cout << "Error opening file.\n";
	}
	else
	{
		cout << "Here are all customers in the file:" << endl;
		fin.clear();
		fin.seekg(0L, ios::beg); 

		while (fin.read(reinterpret_cast<char*>(&info), sizeof(info)))
		{
			cout << "\nName: ";
			cout << info.name << endl;
			cout << "Address: ";
			cout << info.address << endl;
			cout << "Id: ";
			cout << info.id << endl;
			cout << "Account Balance: ";
			cout << info.accountBalance << endl;
		}
		fin.close();
	}
}

//*******************************************************************************************************

/*
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 1
Customer Name: Janet Doe
Customer Address: Webster st.
Customer Id: 1009
Account Balance: 10.5
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 1
Customer Name: Jane Doe
Customer Address: 1002 Second st.
Customer Id: 1002
Account Balance: 0
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 1
Customer Name: Newer Doe
Customer Address: new address
Customer Id: 1003
Account Balance: 25
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 5
Here are all customers in the file:

Name: Janet Doe
Address: Webster st.
Id: 1009
Account Balance: 10.5

Name: Jane Doe
Address: 1002 Second st.
Id: 1002
Account Balance: 0

Name: Newer Doe
Address: new address
Id: 1003
Account Balance: 25
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 3
Enter the record number: 0
Current information: Name: Janet Doe
Address: Webster st.
Id: 1009
Account Balance: 10.5

Enter new customer name: Janet Doe
Enter new customer address: New Webster st.
Enter new customer ID: 1009
Enter new account balance: 12

****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 2
Enter the record number: 0
Here is record 0:
Name: Janet Doe
Address: New Webster st.
Id: 1009
Account Balance: 12
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 4
Enter the record number: 2
Current information: Name: Newer Doe
Address: new address
Id: 1003
Account Balance: 25
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 5
Here are all customers in the file:

Name: Janet Doe
Address: New Webster st.
Id: 1009
Account Balance: 12

Name: Jane Doe
Address: 1002 Second st.
Id: 1002
Account Balance: 0
****************************************
1. Enter new records into the file.
2. Display a selected record.
3. Edit a selected record.
4. Delete a selected record.
5. Display all records.
6. Quit.

Please Enter: 6
Goodbye!

C:\Users\stone\source\repos\RussCustomerRecord2\Debug\RussCustomerRecord2.exe (process 2280) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/