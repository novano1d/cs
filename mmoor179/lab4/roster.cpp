//Modified by Matthew Moore
//9-23-2022

// vector and list algorithms
// Mikhail Nesterenko
// 3/11/2014

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

// reading a list from a fileName
void readRoster(vector<list<string>>& roster, string fileName);  

// printing a list out
void printRoster(const vector<list<string>>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl;
      exit(1);
   }

   // vector of courses of students
   vector<list<string>> courseStudents; 

   for(int i=1; i < argc-1; ++i){
      list<string> roster;
      readRoster(courseStudents, argv[i]);  
   }
   cout << "All Students\n";
    printRoster(courseStudents);

    //sort
    std::sort(courseStudents.begin(), courseStudents.end(), [](const list<string>& a, const list<string>& b) {
        return a.front() < b.front();
    });
    
    //read dropouts into vector
    vector<string> dropouts;
    ifstream course(argv[argc-1]);
    string first, last;
    while(course >> first >> last)
      dropouts.push_back(first + ' ' + last);
    course.close();

    //remove dropouts
    for (int i = 0; i < courseStudents.size(); i++)
    {
        if (std::find(dropouts.begin(), dropouts.end(), courseStudents[i].front()) != dropouts.end())
        {
            courseStudents.erase(courseStudents.begin() + i);
        } 
    }
    

    cout << "All students, dropouts removed and sorted\n";
   printRoster(courseStudents);
}

// reading in a file of names into a list of strings
void readRoster(vector<list<string>>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
   {
        bool alreadythere = false; //flag
        for (int i = 0; i < roster.size(); i++)
        {
            if (roster[i].front() == first + ' ' + last)
            {
                roster[i].push_back(fileName.substr(0, fileName.length() - fileName.find('.') - 1));
                alreadythere = true;
            }
        }
        if (!alreadythere)
        {
            list<string> newStudent;
            newStudent.push_back(first + ' ' + last);
            newStudent.push_back(fileName.substr(0, fileName.length() - fileName.find('.') - 1));
            roster.push_back(newStudent);
        }
   }
      
   course.close();
}

// printing a list out
void printRoster(const vector<list<string>>& roster){
    cout << "first name last name: courses enrolled\n";
   for (int i = 0; i < roster.size(); i++)
   {
        cout << roster[i].front() << ':';
        auto j = roster[i].begin();
        j++;
        while (j != roster[i].end())
        {
            cout << *j + ' ';
            j++;
        }
        cout << endl;
   }
}