//***************************************************************
//
//		Assignment:		#18
// 
//		File:			RussAssignment18.cpp
// 
//		Due Date:		November 21, 2022
//
//		Author:			Ryan Russell
//
//
//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	Calculates markups using functions
//
//
//***************************************************************


#include <iostream>
#include <iomanip>

using namespace std;

//**************************************************************

double GetWholeSale();
double GetMark();
void Report(double&);
void CalculateRetail(double&, double, double);

//***************************************************************

int main()
{

	char loop = 'Y';

	do
	{
		double wholeSale = 0;
		double markup = 0;
		double retailPrice = 0;
		wholeSale = GetWholeSale();
		markup = GetMark();
		CalculateRetail(retailPrice, wholeSale, markup);
		Report(retailPrice);
		cout << "Do you want to do another markup? Enter Y to continue, N to stop: ";
		cin >> loop;
		loop = toupper(loop);
	} while (loop == 'Y');

	return 0;
}

//************************************************************

double GetWholeSale()
{
	double num = 0;
	while (num < 1)
	{
		cout << "Enter the item's whole sale (positive): ";
		cin >> num;
	}
	return num;
}

//************************************************************

double GetMark()
{
	double num = 0;
	while (num < 1)
	{
		cout << "Enter the markup (positive): ";
		cin >> num;
	}
	return num;
}

//***********************************************************

void CalculateRetail(double& rP, double wS, double mu)
{
	rP = wS + (wS * (mu / 100));
}

//************************************************************

void Report(double& rP)
{
	cout << fixed << setprecision(2) << endl;
	cout << "The retail price is $" << rP << endl;
}

//***********************************************************

/*
Enter the item's whole sale (positive): -5
Enter the item's whole sale (positive): 5
Enter the markup (positive): 50

The retail price is $7.50
Do you want to do another markup? Enter Y to continue, N to stop: y
Enter the item's whole sale (positive): 5
Enter the markup (positive): 100

The retail price is $10.00
Do you want to do another markup? Enter Y to continue, N to stop: n

C:\Users\stone\source\repos\Assignment18Fixed\Debug\Assignment18Fixed.exe (process 35124) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/