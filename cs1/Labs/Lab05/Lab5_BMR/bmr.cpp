//Matthew Moore
//BMR
//9-27-2021
#include <iostream>
using namespace std;

double bmrWomen(double, double, double);
double bmrMen(double, double, double);

int main()
{
	char gender;
	double weight;
	double heightFeet;
	double heightInches;
	double age;
	double calculatedBMR;
	const double caloriesInCookie = 150;
	cout << "Please enter your gender (M for male and F for female) : ";
	cin >> gender; 
	cout << "Please enter your weight in pounds : ";
	cin >> weight;
	cout << "Please enter your height in the format 'feet inches' : ";
	cin >> heightFeet >> heightInches;
	cout << "Please enter your age in years: ";
	cin >> age;
	if (gender == 'f' || gender == 'F')
	{
		calculatedBMR = bmrWomen(weight, heightFeet * 12 + heightInches, age);
		cout << "The computed BMR is : " << calculatedBMR << endl << "The number of cookies that can be consumed per day is : " << (int)(calculatedBMR / caloriesInCookie);
	}
	else if (gender == 'm' || gender == 'M')
	{
		calculatedBMR = bmrMen(weight, heightFeet * 12 + heightInches, age);
		cout << "The computed BMR is : " << calculatedBMR << endl << "The number of cookies that can be consumed per day is : " << (int)(calculatedBMR / caloriesInCookie);
	}
	else
	{
		cout << "Invalid gender entered.";
	}
}

double bmrWomen(double weight, double height, double age)
{
	return 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
}

double bmrMen(double weight, double height, double age)
{
	return 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
}