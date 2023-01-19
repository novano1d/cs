// Modified by Matthew Moore
// 9/30/2022

// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>

using std::ifstream; using std::map;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;


class Student{
public:
   Student(string firstName, string lastName): 
      firstName_(firstName), lastName_(lastName) {}
 
   // move constructor, not really needed, generated automatically
   Student(Student && org):
      firstName_(move(org.firstName_)),
      lastName_(move(org.lastName_))
   {}
  
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
  string print() const {return firstName_ + ' ' + lastName_;}

    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.lastName_ == right.lastName_ &&
	     left.firstName_ == right.firstName_;
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.firstName_ + ' ' + left.lastName_ < right.firstName_ + ' ' + right.lastName_;
   }
private:
   string firstName_;
   string lastName_;
};




// reading a list from a fileName
void readRoster(map<Student, list<string>> &roster, string fileName);  
// printing a list out
void printRoster(const map<Student, list<string>>& roster);

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // map of courses of students
   map<Student, list<string>> courseStudents; 

   for(int i=1; i < argc-1; ++i){
      readRoster(courseStudents, argv[i]);  
   }
 
    vector<Student> dropouts;
   {
        string fileName = argv[argc-1];
        ifstream course(fileName);
        string first, last;
        while(course >> first >> last)
        {
            dropouts.push_back(Student(first, last));
        }
        course.close();
   }
 
   for (auto it = dropouts.begin(); it != dropouts.end(); it++)
   {
        courseStudents.erase(*it);
   }

   cout << "All Students" << endl << "First name Last name:  courses enrolled\n";
   printRoster(courseStudents);
}


void readRoster(map<Student, list<string>> &roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
   {
        auto temp = roster.insert({Student(first, last), {fileName.substr(0, fileName.length() - fileName.find('.') - 1)}});
        if (!temp.second)
        {
            auto it = roster.find(Student(first, last));
            it->second.push_back(fileName.substr(0, fileName.length() - fileName.find('.') - 1));
        }
   }
   course.close();
}

// printing a list out
void printRoster(const map<Student, list<string>>& roster){
   for(auto i = roster.begin(); i != roster.end(); i++)
   {
        cout << i->first.print() << ':';
        for (auto it = i->second.begin(); it != i->second.end(); it++)
        {
            cout << *it << ' ';
        }
        cout << endl;
   }
}