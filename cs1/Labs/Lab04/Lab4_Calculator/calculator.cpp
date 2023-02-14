//Scientific Calculator
//Matthew Moore
//9-20-2021
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int choice;
	double input;
	double power;
	bool keepRunning = true;
	cout << "1. absolute value\n2. square root\n3. floor\n4. power\n";
	do
	{
		cout << "Select an operation : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Insert number to take absolute value of: ";
			cin >> input;
			cout << "The result is: " << abs(input) << endl;
			break;
		case 2:
			cout << "Insert number to take the square root of: ";
			cin >> input;
			cout << "The result is: " << sqrt(input) << endl;
			break;
		case 3:
			cout << "Insert number you want to find the floor of: ";
			cin >> input;
			cout << "The result is: " << floor(input) << endl;
			break;
		case 4:
			cout << "Enter base: ";
			cin >> input;
			cout << "Enter exponent: ";
			cin >> power;
			cout << "The result is: " << pow(input, power) << endl;
			break;
		default:
			keepRunning = false;
			break;
		}
	} 
	while (keepRunning);
}