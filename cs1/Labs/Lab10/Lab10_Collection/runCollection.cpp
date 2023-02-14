#include "collection.hpp"
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
	int size = 0;
	double* nums = new double[size];
	char input;
	double input2;
	while (true)
	{
		start:
		cout << "enter operation [a/r/q] and number: ";
		cin >> input >> input2;
		if (input == 'a' || input == 'A')
		{
			if (check(nums, input2, size) != -1)
			{
				cout << "duplicate!\n";
				goto start;
			}
			addNumber(nums, input2, size);
			output(nums, size);
			cout << endl;
		}
		else if (input == 'r' || input == 'R')
		{
			if (check(nums, input2, size) == -1)
			{
				cout << "not present!\n";
				goto start;
			}
			removeNumber(nums, input2, size);
			output(nums, size);
			cout << endl;
		}
		else if (input == 'q' || input == 'Q')
		{
			delete[] nums;
			return 0;
		}
		else
		{
			cout << "invalid input!\n";
		}
	}
	
}