//Matthew Moore
//11-4-2022

#include <iostream>
#include <cstdlib>
using std::cout; using std::endl; using std::cin;

// abstract body
class Fill {
public:
        Fill(char fillChar, char borderChar ) :fillChar_(fillChar), borderChar_(borderChar) {}  // change for it takes fill and border
        virtual char getBorder() = 0;
        virtual char getInternal() = 0;
        virtual ~Fill() {}
protected:
        char fillChar_;
        char borderChar_;
};

// concrete body
class Hollow : public Fill {
public:
        Hollow(char fillChar) :Fill(fillChar, ' ') {}
        char getBorder() override { return fillChar_; }
        char getInternal() override { return ' '; }
        ~Hollow() {}
};


// another concrete body
class Filled : public Fill {
public:
        Filled(char fillChar) :Fill(fillChar, fillChar) {}
        char getBorder() override { return fillChar_; }
        char getInternal() override { return fillChar_; }
        ~Filled() {}
};

class FullyFilled : public Filled
{
public:
   FullyFilled(char FillChar, char BorderChar) : Filled(FillChar) {borderChar_ = BorderChar;};
   char getBorder() override { return fillChar_; }
   char getInternal() override { return borderChar_; }
   ~FullyFilled() {}
};

class RandomFilled : public Filled
{
public:
   RandomFilled(char FillChar, char BorderChar) : Filled(FillChar) {borderChar_ = BorderChar;};
   char getBorder() override
   {
      if (rand()%2==0) return borderChar_;
      else return fillChar_;
   }
   char getInternal() override {
      if (rand()%2==0) return borderChar_;
      else return fillChar_;
   }
   ~RandomFilled() {};
};

// abstract handle
class Figure {
public:
        Figure(int size, Fill* fill) : size_(size), fill_(fill) {}
        virtual void draw() = 0;
        virtual ~Figure() {}

        void changeFill(Fill* c) {  // changes fill
                delete fill_;  //deletes
                fill_ = c;         //then changes
        }

protected:
        int size_;
        Fill* fill_;
};

// concrete handle
class Square : public Figure {
public:
        Square(int size, Fill* fill) : Figure(size, fill) {}
        void draw() override;

};


void Square::draw() {
        for (int i = 0; i < size_; ++i) {
                for (int j = 0; j < size_; ++j)
                        if (i == 0 || j == 0 || i == size_ - 1 || j == size_ - 1)
                                cout << fill_->getBorder();
                        else
                                cout << fill_->getInternal();
                cout << endl;
        }
}


int main() {
        //first filled square
        Square *userBox = new Square(10, static_cast<Fill*>(new Filled('h')));
        userBox->draw();
        cout << endl;
        //hollow square
        userBox = new Square(10, static_cast<Fill*>(new Hollow('h')));
        userBox->draw();
        cout << endl;
        //filled with different character for border and internal
        userBox = new Square(10, static_cast<Fill*>(new FullyFilled('b', 'i')));
        userBox->draw();
        cout << endl;
        //Random character filling
        srand(time(nullptr));
        userBox = new Square(10, static_cast<Fill*>(new RandomFilled('b', 'i')));
        userBox->draw();
        cout << endl;
}