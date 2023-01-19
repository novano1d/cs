#include <iostream>
#include "header.hpp"

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    BaristaSubject *baristasubject = new BaristaSubject(); // subject for observer
    Barista *barista = new JuniorBarista(new SeniorBarista(new Manager())); //chain of command
    while (true) //keeps running until the user exits the program... I felt it made sense it this context
    {
        char selection;
        cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee? ";
        cin >> selection;
        Drink* drink;
        if (selection == 's') drink = new Drink(DrinkType::small);
        else if (selection == 'm') drink = new Drink(DrinkType::medium);
        else drink = new Drink(DrinkType::large);
        while (selection != 'd')
        {
            cout << "Would you like to add [s]ugar, [c]ream, milk [f]oam, or [d]one? ";
            cin >> selection;
            if (selection == 's') drink = new Sugar(drink);
            else if (selection == 'c') drink = new Cream(drink);
            else if (selection == 'f') drink = new MilkFoam(drink);
        }
        string name;
        cout << "Can I get your name? ";
        cin >> name;
        barista->handleRequest(drink);
        Customer *customer = new Customer(name, drink);
        baristasubject->registerCustomer(customer);
        if (rand() % 3 == 0)
        {
            baristasubject->notifyCustomers();
            baristasubject->deregisterAllCustomers();

        }
        else
        {
            cout << "Next order!\n";
        }
    }

}