#include "collection.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main()
{
	Collection col;
	char input;
	double input2;
	while (true)
	{
		start:
		cout << "enter operation [a/r/q] and number: ";
		cin >> input;
		if (input == 'q' || input == 'Q')
		{
			return 0;
		}
		cin >> input2;
		if (input == 'a' || input == 'A')
		{
			if (col.check(input2) != -1)
			{
				cout << "duplicate!\n";
				goto start;
			}
			col.addNumber(input2);
			col.output();
			cout << endl;
		}
		else if (input == 'r' || input == 'R')
		{
			if (col.check(input2) == -1)
			{
				cout << "not present!\n";
				goto start;
			}
			col.removeNumber(input2);
			col.output();
			cout << endl;
		}
		else
		{
			cout << "invalid input!\n";
		}
	}
}