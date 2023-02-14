#include <iostream>
#include "battleship.hpp"

using std::cin; using std::cout; using std::endl;

Location::Location()
{
	x_ = -1;
	y_ = '*';
}
void Location::pick()
{
	int a, b;
	char c = ' ';
	a = rand() % (fieldSize_)+1;
	b = rand() % (fieldSize_)+1;
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
	x_ = a;
	y_ = c;
}
void Location::fire()
{
	cout << "Please enter the coordinate you would like to fire at: ";
	cin >> y_ >> x_;
}
void Location::print() const
{
	cout << y_ << x_;
}
bool compare(const Location& l1, const Location& l2)
{
	return l1.x_ == l2.x_ && l1.y_ == l2.y_;
}
Ship::Ship()
{
	sunk_ = false;
}
bool Ship::match(const Location& l) const
{
	return compare(l, loc_);
}
void Ship::sink()
{
	sunk_ = true;
}
void Ship::setLocation(const Location& l)
{
	loc_ = l;
}
void Ship::printShip() const
{
	loc_.print();
	cout << " ";
	if (sunk_)
	{
		cout << "sunk";
		return;
	}
	cout << "up";
}
int Fleet::check(const Location& l) const
{
	for (int i = 0; i < fleetSize_; i++)
	{
		if (ships_[i].match(l))
		{
			return i;
		}
	}
	return -1;
}
void Fleet::deployFleet()
{
	for (int i = 0; i < fleetSize_; i++)
	{
	start:
		Location l;
		l.pick();
		if (check(l) == -1)
		{
			ships_[i].setLocation(l);
		}
		else
		{
			goto start;
		}
	}
}
bool Fleet::operational() const
{
	for (int i = 0; i < fleetSize_; i++)
	{
		if (!ships_[i].isSunk())
		{
			return true;
		}
	}
	return false;
}
bool Fleet::isHitNSink(const Location& l)
{
	for (int i = 0; i < fleetSize_; i++)
	{
		if (ships_[i].match(l))
		{
			ships_[i].sink();
			return true;
		}
	}
	return false;
}
void Fleet::printFleet() const
{
	for (int i = 0; i < fleetSize_; i++)
	{
		ships_[i].printShip();
		if (i != fleetSize_ - 1)
		{
			cout << ", ";
		}
	}
}