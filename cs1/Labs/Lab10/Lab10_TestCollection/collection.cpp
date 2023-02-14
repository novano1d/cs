#include "collection.hpp"
#include <iostream>

using std::cin; using std::cout; using std::endl;

void output(double* colPtr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(colPtr + i) << " ";
	}
}

int check(double* colPtr, double number, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (*(colPtr + i) == number)
		{
			return i;
		}
	}
	return -1;
}

void addNumber(double*& colPtr, double number, int& size)
{
	if (check(colPtr, number, size) != -1)
	{
		return;
	}
	double* temp = new double[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = colPtr[i];
	}
	temp[size] = number;
	delete[] colPtr;
	colPtr = temp;
	size++;
}

void removeNumber(double*& colPtr, double number, int& size)
{
	int pos = check(colPtr, number, size);
	if (pos == -1)
	{
		return;
	}
	double* temp = new double[--size];
	int indexSkip = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == pos)
		{
			indexSkip++;
		}
		temp[i] = colPtr[indexSkip];
		indexSkip++;
	}
	delete[] colPtr;
	colPtr = temp;
}