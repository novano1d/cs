// Modified by Matthew Moore
// 11-18-2022
// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/7/2022

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::string; using std::cin; using std::cout; using std::endl;
enum class DrinkType {small, medium, large};



//component (not sure if this was necessary)
class DrinkForSale{
public:
   virtual int getPrice() const = 0;
   virtual std::string getName() const = 0;
};

// concrete component
class Drink : DrinkForSale{
public:
   Drink(DrinkType type=DrinkType::small, int price=0):
                 type_(type), price_(price){}
   int getPrice() const override
   {
      if (type_ == DrinkType::large) return 10;
      else if (type_ == DrinkType::medium) return 7;
      else return 5;
   }
   string getName() const override 
   {
      if (type_ == DrinkType::large) return "large coffee with ";
      else if (type_ == DrinkType::medium) return "medium coffee with ";
      else return "small coffee with ";
   }
private:
   int price_;
   DrinkType type_;
};

// decorator
class Sugar : public Drink
{
public:
   Sugar(const Drink* wrapped) : wrapped_(wrapped) {};
   int getPrice() const override
   {
      return wrapped_->getPrice() + 1;
   }
   string getName() const override 
   {
      return wrapped_->getName() + "sugar ";
   }
private:
   const Drink *wrapped_;
};

// decorator
class Cream : public Drink
{
public:
   Cream(const Drink* wrapped) : wrapped_(wrapped) {};
   int getPrice() const override
   {
      return wrapped_->getPrice() + 2;
   }
   string getName() const override 
   {
      return wrapped_->getName() + "cream ";
   }
private:
   const Drink *wrapped_;
};

// decorator
class MilkFoam : public Drink
{
public:
   MilkFoam(const Drink* wrapped) : wrapped_(wrapped) {};
   int getPrice() const override
   {
      return wrapped_->getPrice() + 3;
   }
   string getName() const override 
   {
      return wrapped_->getName() + "foam ";
   }
private:
   const Drink *wrapped_;
};


//Chain of responsibility Barista

//abstract
class Barista
{
public:
   Barista(Barista *successor=nullptr) : successor_(successor) {};
   virtual void handleRequest(const Drink* drink)
   {
      if (successor_ != nullptr)
      {
         successor_->handleRequest(drink);
      }
      else
      {  //never will occur in this situation
         cout << "Nobody can make this drink.";
      }
   }
private:
   Barista *successor_;
};

//no ingredients
class JuniorBarista: public Barista
{
public:
   JuniorBarista(Barista *successor=nullptr): Barista(successor){};
   void handleRequest(const Drink* drink) override
   {
      if ((drink->getName().find("foam") == string::npos) && (drink->getName().find("cream") == string::npos) && (drink->getName().find("sugar") == string::npos))
      {
         cout << "A Junior Barista is preparing your order...\n";
      }
      else Barista::handleRequest(drink);
   }
};

//everything except foam
class SeniorBarista: public Barista
{
public:
   SeniorBarista(Barista *successor=nullptr): Barista(successor){};
   void handleRequest(const Drink* drink) override
   {
      if ((drink->getName().find("foam") == std::string::npos))
      {
         cout << "A Senior Barista is preparing your order...\n";
      }
      else Barista::handleRequest(drink);
   }
};

//everything
class Manager: public Barista
{
public:
   Manager(Barista *successor=nullptr): Barista(successor){};
   void handleRequest(const Drink* drink) override
   {
      cout << "A Manager is preparing your order...\n";
   }
};

//Observer part


//observer
class Customer
{
public:
   Customer(string name, Drink* drink) : name_(name), drink_(drink) {};
   void notify()
   {
      cout << endl << name_ << ", your " << drink_->getName() << "is ready. It will be $" << drink_->getPrice() << ", please." << endl;
   }
private:
   string name_;
   Drink* drink_;
};

//subject
class BaristaSubject
{
public:
   BaristaSubject() {};
   void registerCustomer(Customer* c) {views_.push_back(c);};
   void deregisterCustomer(Customer* c) {views_.erase(std::remove(views_.begin(), views_.end(), c), views_.end()); };
   void deregisterAllCustomers() {views_.clear();};
   void notifyCustomers() const
   {
      for (auto e: views_)
      {
         e->notify();
      }
   }
private:
   vector<Customer*> views_;
};

