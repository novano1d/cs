#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

Location pick()
{
	int a, b;
	char c = ' ';
	a = rand() % (fieldSize) + 1;
	b = rand() % (fieldSize) + 1;
	switch (b)
	{
	case 1:
		c = 'a';
		break;
	case 2:
		c = 'b';
		break;
	case 3:
		c = 'c';
		break;
	case 4:
		c = 'd';
		break;
	case 5: 
		c = 'e';
		break;
	case 6: 
		c = 'f';
		break;
	}
	return { a, c };
}

Location fire()
{
	int a;
	char b;
	cout << "Please enter the coordinate you would like to fire at: ";
	cin >> b >> a;
	return { a, b };
}

void printShip(const Ship& s)
{
	cout << s.loc.y << s.loc.x << " ";
	if (s.sunk)
	{
		cout << "sunk";
		return;
	}
	cout << "up";
}

void printFleet(const Ship s[])
{
	for (int i = 0; i < fleetSize; i++)
	{
		printShip(s[i]);
		if (i != fleetSize - 1)
		{
			cout << ", ";
		}
	}
}

bool match(const Ship& s, const Location& l)
{
	if (s.loc.x == l.x && s.loc.y == l.y)
	{
		return true;
	}
	return false;
}

void sink(Ship& s)
{
	s.sunk = true;
}

bool operational(const Ship s[])
{
	for (int i = 0; i < fleetSize; i++)
	{
		if (!s[i].sunk)
		{
			return true;
		}
	}
	return false;
}

void initialize(Ship s[])
{
	for (int i = 0; i < fleetSize; i++)
	{
		s[i].loc.x = -1;
		s[i].loc.y = '*';
	}
}

int check(const Ship s[], const Location& l)
{
	for (int i = 0; i < fleetSize; i++)
	{
		if (match(s[i], l))
		{
			return i;
		}
	}
	return -1;
}

void deploy(Ship s[])
{
	for (int i = 0; i < fleetSize; i++)
	{
		start:
		Location l = pick();
		if (check(s, l) == -1)
		{
			s[i].loc = l;
			s[i].sunk = false;
		}
		else
		{
			goto start;
		}
	}
}

void play()
{
	Ship fleet[fleetSize];
	deploy(fleet);
	char input;
	bool printShips = false;
	cout << "Would you like to see the locations of the ships? (Y/N) ";
	cin >> input;
	if (input == 'y' || input == 'Y')
	{
		printShips = true;
		printFleet(fleet);
		cout << endl;
	}
	while (operational(fleet))
	{
		Location currentShot;
		currentShot = fire();
		if (check(fleet, currentShot) != -1)
		{
			sink(fleet[check(fleet, currentShot)]);
			cout << "Hit!\n";
		}
		else
		{
			cout << "Miss!\n";
		}
		if (printShips)
		{
			printFleet(fleet);
			cout << endl;
		}
	}
	cout << "Congrats! You've sunk all the battleships! You win.";
}