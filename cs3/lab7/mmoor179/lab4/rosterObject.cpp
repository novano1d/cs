// Modified by Matthew Moore
// 9-23-2022

// vector and list algorithms with objects in containers
// Mikhail Nesterenko
// 9/10/2018

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::ifstream;
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
   
  string print() const 
    {
        string out = firstName_ + ' ' + lastName_ + ':';
        for (int i = 0; i < classes.size(); i++)
        {
            out += classes[i] + ' ';
        }
        
        return out;
    }

  void addClass(const string &s)
  {
    classes.push_back(s);
  }

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
   vector<string> classes;
};




// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);  
// printing a list out
void printRoster(const list<Student>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // vector of courses of students
   list<Student> courseStudents; 
   for(int i=1; i < argc-1; ++i){
      readRoster(courseStudents, argv[i]);  
   }


   // reading in dropouts
   list<Student> dropouts;
   readRoster(dropouts, argv[argc-1]); 

   cout << "All students\n"; 
           printRoster(courseStudents);

   courseStudents.sort(); // sorting master list

   courseStudents.unique(); // eliminating duplicates
   
   for (const auto& str : dropouts)  // removing individual dropouts
      courseStudents.remove(str);
   cout << "\nAll students, dropouts removed and sorted\n"; printRoster(courseStudents);

}


void readRoster(list<Student>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
   {
        Student s = Student(first, last);
        auto it = std::find(roster.begin(), roster.end(), s);
        if (it == roster.end())
        {
            s.addClass(fileName.substr(0, fileName.length() - fileName.find('.') - 1));
            roster.push_back(s);
        }
        else
        {
            it->addClass(fileName.substr(0, fileName.length() - fileName.find('.') - 1));
        }
        
   }
   course.close();
}

// printing a list out
void printRoster(const list<Student>& roster){
   for(const auto& student : roster)
      cout << student.print() << endl;
}