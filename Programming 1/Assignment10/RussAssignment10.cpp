//***************************************************************
//
//		Assignment:		#10
// 
//		File:			RussAssignment10.cpp
// 
//		Due Date:		September 26, 2022
//
//		Author:			Ryan Russell
//

//		Course Name:	Programming I
//
//		Course Number:	COSC 1550
//
//		Description:	A geometry calculator that has a menu
//
//
//***************************************************************


#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	int userChoice = 0;
	cout << "Geometry Calculator\n	1.Calculate the Area of a Circle\n	2.Calculate the Area of a Rectangle\n	3. Calculate the Area of a Triangle\n	4. Quit\n\n	Enter your choice (1-4):";
	cin >> userChoice;

	if (userChoice < 1 || userChoice > 4)
	{
		cout << "Enter a valid number (1, 2, 3, 4)\nEnter choice again: ";
		cin >> userChoice;
	}

	if (userChoice == 1)
	{
		double radiusCircle = 0;
		cout << "Enter the radius of the circle: ";
		cin >> radiusCircle;
		double areaCircle = (pow(radiusCircle, 2)) * 3.14159;
		cout << "The area of the circle is: " << areaCircle;

	}
	else if (userChoice == 2)
	{
		double length = 0;
		double width = 0;
		cout << "Enter the length of the rectangle: ";
		cin >> length;
		cout << "\nEnter the width of the rectangle: ";
		cin >> width;
		double areaRectangle = length * width;
		cout << "The area of the rectangle is: " << areaRectangle;
	}
	else if (userChoice == 3)
	{
		double base = 0;
		double height = 0;
		cout << "Enter the base of the traingle: ";
		cin >> base;
		cout << "\nEnter the height of the triangle: ";
		cin >> height;
		double areaTriangle = (base * height) * 0.5;
		cout << "The area of the triangle is: " << areaTriangle;
	}
	else if (userChoice == 4)
	{
		
	}
	else
	{
		cout << "Please enter a number between 1-4." << endl;
	}
	return 0;
}

/*
Geometry Calculator
		1.Calculate the Area of a Circle
		2.Calculate the Area of a Rectangle
		3. Calculate the Area of a Triangle
		4. Quit

		Enter your choice (1-4):1
Enter the radius of the circle: 4
The area of the circle is: 50.2654
C:\Users\stone\source\repos\Assignment10\Debug\Assignment10.exe (process 18740) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

--------------------------------------------

Geometry Calculator
		1.Calculate the Area of a Circle
		2.Calculate the Area of a Rectangle
		3. Calculate the Area of a Triangle
		4. Quit

		Enter your choice (1-4):2
Enter the length of the rectangle: 4

Enter the width of the rectangle: 5
The area of the rectangle is: 20
C:\Users\stone\source\repos\Assignment10\Debug\Assignment10.exe (process 15344) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

-------------------------------------------

Geometry Calculator
		1.Calculate the Area of a Circle
		2.Calculate the Area of a Rectangle
		3. Calculate the Area of a Triangle
		4. Quit

		Enter your choice (1-4):3
Enter the base of the traingle: 4

Enter the height of the triangle: 5
The area of the triangle is: 10
C:\Users\stone\source\repos\Assignment10\Debug\Assignment10.exe (process 10300) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/