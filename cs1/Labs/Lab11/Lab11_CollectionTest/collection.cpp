#include "collection.hpp"
#include <iostream>

using std::cout;

Collection::Collection()
{
	size_ = 0;
	col_ = new double[size_];
}

int Collection::check(double number)
{
	for (int i = 0; i < size_; i++)
	{
		if (*(col_ + i) == number)
		{
			return i;
		}
	}
	return -1;
}

void Collection::addNumber(double number)
{
	if (check(number) != -1)
	{
		return;
	}
	double* temp = new double[size_ + 1];
	for (int i = 0; i < size_; i++)
	{
		temp[i] = col_[i];
	}
	temp[size_] = number;
	delete[] col_;
	col_ = temp;
	size_++;
}

void Collection::removeNumber(double number)
{
	int pos = check(number);
	if (pos == -1)
	{
		return;
	}
	double* temp = new double[--size_];
	int indexSkip = 0;
	for (int i = 0; i < size_; i++)
	{
		if (i == pos)
		{
			indexSkip++;
		}
		temp[i] = col_[indexSkip];
		indexSkip++;
	}
	delete[] col_;
	col_ = temp;
}

void Collection::output()
{
	for (int i = 0; i < size_; i++)
	{
		cout << *(col_ + i) << " ";
	}
}

Collection::Collection(const Collection& c)
{
	size_ = c.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; i++)
	{
		col_[i] = c.col_[i];
	}
}

Collection::~Collection()
{
	delete[] col_;
}

Collection& Collection::operator= (const Collection& t)
{
	if (this != &t)
	{
		size_ = t.size_;
		delete[] col_;
		col_ = new double[size_];
		for (int i = 0; i < size_; i++)
		{
			col_[i] = t.col_[i];
		}
	}
	return *this;
}