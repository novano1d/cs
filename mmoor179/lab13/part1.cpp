// Modified by Matthew Moore
// 12-8-2022

// mediator-based air traffic control
// Mikhail Nesterenko
// 11/30/2022

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <map>
#include <algorithm>

// for timed sleep
#include <thread>
#include <chrono>


using std::cout; using std::cin; using std::endl;
using std::string;

/*/////////////////////////////
    Added flyweight classes
*//////////////////////////////

enum class airline {Delta, United, JetBlue, AirFrance, KLM, Aeroflot, Lufthansa};
//abstract flyweight
class Airline 
{
public:
    virtual string image() = 0;
};

//concrete flyweights
class Delta : public Airline
{
public:
    string image() override { return "DELTA"; };
};
class United : public Airline
{
public:
    string image() override { return "UNITED"; };
};
class JetBlue : public Airline
{
public:
    string image() override { return "JETBLUE"; };
};
class AirFrance : public Airline
{
public:
    string image() override { return "AIRFRANCE"; };
};
class KLM : public Airline
{
public:
    string image() override { return "KLM"; };
};
class Aeroflot : public Airline
{
public:
    string image() override { return "AEROFLOT"; };
};
class Lufthansa : public Airline
{
public:
    string image() override { return "LUFTHANSA"; };
};

class Factory
{
public:
    static Airline *makeAirline(airline a)
    {
        if (airlines_.find(a) == airlines_.end())
        {
            switch (a)
            {
            case airline::Delta:
                airlines_[a] = new Delta; break;
            case airline::United:
                airlines_[a] = new United; break;
            case airline::JetBlue:
                airlines_[a] = new JetBlue; break;
            case airline::AirFrance:
                airlines_[a] = new AirFrance; break;
            case airline::KLM:
                airlines_[a] = new KLM; break;
            case airline::Aeroflot:
                airlines_[a] = new Aeroflot; break;
            case airline::Lufthansa:
                airlines_[a] = new Lufthansa; break;
            }
        }
        return airlines_[a];
    }
private:
    static std::map<airline, Airline*> airlines_;
};
std::map<airline, Airline*> Factory::airlines_;
//client
class Aircraft
{
public:
    Aircraft(airline a, int fltnum) : num_(fltnum) { airline_ = Factory::makeAirline(a); };
    string report()
    {
        return (airline_->image() + std::to_string(num_));
    }
private:
    const int num_;
    Airline *airline_;
};

///////////////////////////////////////////////////////


// abstract mediator
class Controller{
public:
   virtual void join(class Flight*)=0;
   virtual void leave(class Flight*)=0;
   virtual void broadcast() = 0;
   virtual void observe() = 0;
};


// concrete mediator
// tower, runway clearance
class Tower: public Controller{
public:
   void join(class Flight*) override; 
   void leave(class Flight*) override;
   void broadcast() override;
   void observe() override;
private:
   std::set<class Flight*> waiting_;
};


// abstract colleague
class Flight {
public:
   Flight(Controller *controller):controller_(controller), status_(Status::waiting){
      task_ = rand() % 2 ? Task::taxiing : Task::approaching;
      controller_->join(this);
   }
   void receive(const string &msg){
      if (msg.find(flightNo_) != string::npos || msg.find("all") != string::npos){
	 if(msg.find("clear") != string::npos){
	    cout << flightNo_ << " roger that, ";
	    cout << (task_ == Task::taxiing ? "taking off" : "landing") << endl;
	    status_ = Status::cleared;
	 } else if(msg.find("status") != string::npos) {
	    cout << flightNo_
		 << (status_ == Status::waiting ? " waiting to " : " cleared to ")   
	         << (task_ == Task::taxiing ? "take off" : "land") << endl;
	 } else
	    cout << "Tower, this is " << flightNo_ << " please repeat." << endl;
      }
   }
   bool isCleared() const {return status_ == Status::cleared;}
   void proceed(){
      std::this_thread::sleep_for(std::chrono::seconds(rand()%3+1)); // wait a while    
      cout << "..." << aircraft_->report() << (task_ == Task::taxiing ? " takes off" : " lands") << "...\n"; //modified
      controller_->leave(this);
   }

protected:
   Aircraft *aircraft_; //added
   string flightNo_;
   Controller *controller_;
   enum class Task {taxiing, approaching};  Task task_;
   enum class Status {waiting, cleared};    Status status_;
};

// concrete colleagues
class Airbus: public Flight{
public:
   Airbus(Tower *tower): Flight(tower){
      static const std::vector<string> companies = 
	 {"AirFrance", "KLM", "Aeroflot", "Lufthansa"};
      string company = companies[rand() % companies.size()];
      int fltnum = rand() % 1000;
      airline comapnyenum;
      flightNo_ = company + std::to_string(fltnum);
      if (company == "AirFrance")
      {
        comapnyenum = airline::AirFrance;
      }
      else if (company == "KLM") comapnyenum = airline::KLM;
      else if (company == "Aeroflot") comapnyenum = airline::Aeroflot;
      else comapnyenum = airline::Lufthansa;
      aircraft_ = new Aircraft(comapnyenum, fltnum);
      cout << flightNo_ << " requesting "
	   << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
   }
};

class Boeing: public Flight{
public:
   Boeing(Tower *tower): Flight(tower){
      static const std::vector<string> companies = 
	 {"Delta", "United", "JetBlue"};
      string company = companies[rand() % companies.size()];
      int fltnum = rand() % 1000;
      airline comapnyenum;
      if (company == "Delta")
      {
         comapnyenum = airline::Delta;
      }
      else if (company == "United") comapnyenum = airline::United;
      else comapnyenum = airline::JetBlue;
      aircraft_ = new Aircraft(comapnyenum, fltnum);
      flightNo_ = company + std::to_string(fltnum);
      cout << flightNo_ << " requesting "
	   << (task_ == Task::taxiing ? "takeoff" : "landing") << endl;
   }
};


// member functions for Tower
void Tower::broadcast() {
   cout << "Tower: ";
   string msg;
   getline(cin,msg);
   if(!msg.empty())
      for(auto f: waiting_) f->receive(msg);
}


void Tower::observe() {
   auto findCleared = [](Flight *f){return f->isCleared();};
   
   auto toProceed = std::find_if(waiting_.begin(),waiting_.end(), findCleared);
   
   while (toProceed != waiting_.end()){ // found a cleared flight
      (*toProceed) -> proceed();
      toProceed = std::find_if(waiting_.begin(), waiting_.end(), findCleared);
      if(toProceed != waiting_.end())
	 cout << "MAYDAY! MAYDAY! MAYDAY! " << endl; // more than a single flight cleared
   }
}


void Tower::join(Flight *f) {
   waiting_.insert(f);
}


void Tower::leave(Flight *f) {
   waiting_.erase(f);
   delete f;
}

int main(){
   srand(time(nullptr));
   Tower jfk;

   new Boeing(&jfk);
   new Airbus(&jfk);
   new Boeing(&jfk);
   new Airbus(&jfk);

   while(true){
      jfk.broadcast();
      jfk.observe();
      if(rand() % 2){
	 if (rand() % 2)
	    new Boeing(&jfk);
	 else
	    new Airbus(&jfk);
      }
   }
}