#include "wordtracking.hpp"

//WordOccurence definitions
WordOccurrence::WordOccurrence(const string& word, int num)
{
    word_ = word;
    num_ = num;
}

bool WordOccurrence::matchWord(const string &word)
{
    if (word == word_)
    {
        return true;
    }
    return false;
}

void WordOccurrence::increment()
{
    num_++;
}

string WordOccurrence::getWord() const { return word_; };

int WordOccurrence::getNum() const { return num_; };

bool WordOccurrence::operator<(const WordOccurrence& other) const
{
    return num_ < other.num_;
}

//WordList definitions
bool equal(const WordList& one, const WordList& two)
{
    if (one.size_ != two.size_) return false; //if not same size can't be equal
    for (int i = 0; i < one.size_; i++)
    {
        if (one.wordArray_[i].getWord() != two.wordArray_[i].getWord() || one.wordArray_[i].getNum() != two.wordArray_[i].getNum()) //make sure each element has the same words and word occurences
        {
            return false;
        }
    }
    return true;
}

void WordList::addWord(const string &word)
{
    string s = word;
    for (int i = 0, len = s.size(); i < len; i++)
    {
        // check whether character is punctuation or not
        if (ispunct(s[i]))
        {
            s.erase(i--, 1);
            len = s.size();
        }
    }
    for (int i = 0; i < size_; i++)
    {
        if (wordArray_[i].getWord() == s)
        {
            wordArray_[i].increment();
            std::sort(wordArray_, wordArray_ + size_);
            return;
        }
    }
    WordOccurrence *tempWordArray = new WordOccurrence[++size_];
    for (int i = 0; i < size_ - 1; i++)
    {
        tempWordArray[i] = wordArray_[i];
    }
    tempWordArray[size_ - 1] = WordOccurrence(s, 1);
    delete [] wordArray_;
    wordArray_ = tempWordArray;
    std::sort(wordArray_, wordArray_ + size_); //make sure array is sorted each time a new word is added
}

void WordList::print()
{
    for (int i = 0; i < size_; i++)
    {
        std::cout << "Word: " << wordArray_[i].getWord() << " , Count: " << wordArray_[i].getNum() << std::endl;
    }
}

WordList::~WordList()
{
    delete [] wordArray_;
}

WordList::WordList(const WordList& other)
{
    size_ = other.size_;
    wordArray_ = new WordOccurrence[size_];
    for (int i = 0; i < size_; i++)
    {
        wordArray_[i] = other.wordArray_[i];
    }
}

WordList& WordList::operator=(const WordList& other)
{
    if (this != &other)
    {
        size_ = other.size_;
        wordArray_ = new WordOccurrence[size_];
        for (int i = 0; i < size_; i++)
        {
            wordArray_[i] = other.wordArray_[i];
        }
    }
    return *this;
}