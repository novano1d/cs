//Matthew Moore
//Figures lab using methods
//9-29-2021

#include <iostream>
#include "figures.hpp"
using namespace std;

int main()
{
	int size, selection;
	char inputChar;
	while (true)
	{
		cout << "Select size: ";
		cin >> size;
		cout << "Select paint character: ";
		cin >> paint;
		cout << "1. Square\n2. Slash\n3. Diamond\nSelect figure: ";
		cin >> selection;
		if (selection == 1)
		{
			cout << "Filled, hollow [f/h]: ";
			cin >> inputChar;
			cout << endl;
			if (inputChar == 'f' || inputChar == 'F')
			{
				filledSquare(size);
			}
			else if (inputChar == 'h' || inputChar == 'H')
			{
				hollowSquare(size);
			}
			else
			{
				cout << "Invalid selection!\n";
			}
		}
		else if (selection == 2)
		{
			cout << "Forward, backward [f/b]: ";
			cin >> inputChar;
			cout << endl;
			if (inputChar == 'f' || inputChar == 'F')
			{
				slash(size);
			}
			else if (inputChar == 'b' || inputChar == 'B')
			{
				backslash(size);
			}
			else
			{
				cout << "Invalid selection!\n";
			}
		}
		else if (selection == 3)
		{
			cout << endl;
			diamond(size);
			cout << endl;
		}
		else
		{
			return 0;
		}
	}
}