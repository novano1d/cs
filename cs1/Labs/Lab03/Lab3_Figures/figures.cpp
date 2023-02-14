//Matthew Moore
//Prints various figures
//9-15-2021


#include <iostream>
using namespace std;

int main()
{
	int size;
	char paint;
	cout << "Input figure size: ";
	cin >> size;
	cout << "Input paint character: ";
	cin >> paint;
	cout << endl;

	//print square
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << paint;
		}
		cout << endl;
	}
	cout << endl;

	//print diagonal left to right
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << paint << endl;
	}
	cout << endl;

	//print diagonal right to left
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			cout << " ";
		}
		cout << paint << endl;
	}
	cout << endl;

	//square hollow
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == size - 1 || i == 0)
			{
				cout << paint;
			}
			else
			{
				if (j == size - 1 || j == 0)
				{
					cout << paint;
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	cout << endl;

	//hollow diamond
	for (int i = 0; i < size * 2 - 1; i++)
	{
		//very top and bottom line of diamond
		if (i == 0 || i == size * 2 - 2)
		{
			for (int j = 0; j < size - 1; j++)
			{
				cout << " ";
			}
			cout << paint << endl;
		}
		//top of diamond
		else if (i < size)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				cout << " ";
			}
			cout << paint;
			for (int j = 0; j < i * 2 - 1; j++)
			{
				cout << " ";
			}
			cout << paint << endl;
		}
		//bottom of diamond
		else
		{
			for (int j = 0; j < i - size + 1; j++)
			{
				cout << " ";
			}
			cout << paint;
			for (int j = 0; j < (size * 2 - 5) - (i - size) * 2; j++)
			{
				cout << " ";
			}
			cout << paint << endl;
		}
	}
}
