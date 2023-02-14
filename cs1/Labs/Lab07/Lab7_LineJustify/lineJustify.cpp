//Matthew Moore
//10-23-2021
//Line justification lab
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void justify(string& s);

const int lineLength = 80;
int main()
{
	string input;
	cout << "input line:\n";
	getline(cin, input);
	justify(input);
	cout << "your line justified:" << endl << input;
}

void justify(string& s)
{
	int index = s.find_first_of(",.!?;");
	if (s.length() <= 40)
	{
		return;
	}
	while (index != string::npos)
	{
		if (s.length() == lineLength)
		{
			return;
		}
		s.insert(index + 1, " ");
		index = s.find_first_of(",.!?;", index + 1);
		if (index == s.length() - 1)
		{
			break;
		}
	}
	srand(time(nullptr));
	int pos;
	while (s.length() < lineLength)
	{
		pos = rand() % (s.length() + 1);
		pos = s.find(" ", pos + 1);
		if (pos == string::npos || pos == s.length() - 1)
		{
			continue;
		}
		s.insert(pos + 1, " ");
	}
}
