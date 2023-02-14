//Matthew Moore
//Figures lab using methods
//9-29-2021

#include "figures.hpp"
#include <iostream>
using namespace std;

char paint;

void filledSquare(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << paint;
		}
		cout << endl;
	}
	cout << endl;
}

void hollowSquare(int size)
{
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
}

void slash(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			cout << " ";
		}
		cout << paint << endl;
	}
	cout << endl;
}

void backslash(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << paint << endl;
	}
	cout << endl;
}

void diamond(int size)
{
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