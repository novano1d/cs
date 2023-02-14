#include <iostream>
#include <vector>
#include <algorithm>

using std::vector; using std::cin; using std::cout; using std::endl;

void print(vector<double> i);

int main()
{
	vector<double> collection;
	char input;
	double input2;
	vector<double>::iterator found;
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
			for (int i = 0; i < collection.size(); i++)
			{
				if (collection[i] == input2)
				{
					cout << "duplicate!\n";
					goto start;
				}
			}
			collection.push_back(input2);
			print(collection);
		}
		else if (input == 'r' || input == 'R')
		{
			found = find(collection.begin(), collection.end(), input2);
			if (found == collection.end())
			{
				cout << "not present!\n";
			}
			else
			{
				collection.erase(found);
			}
			print(collection);
		}
		else
		{
			cout << "invalid input!\n";
		}
	}
}

void print(vector<double> c)
{
	cout << "your numbers: ";
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}