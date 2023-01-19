#ifndef WORD_TRACKING_HPP
#define WORD_TRACKING_HPP
#include <string>
#include <iostream>
#include <algorithm>
using std::string;
class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;
    bool operator<(const WordOccurrence&) const; //added less than operator for sorting
private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList() { size_ = 0; }; //default constructor for the sake of it
    //copy constructor
    WordList(const WordList&);
    //destructor
    ~WordList();
    //overloaded assignment
    WordList& operator=(const WordList& other);

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();
private:
    WordOccurrence *wordArray_ = new WordOccurrence[0]; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};
#endif