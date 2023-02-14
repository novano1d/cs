// collection of doubles class
// Mikhail Nesterenko
// 11/09/2020


#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_

class Collection {
public:
	Collection(); // void constructor
	int size() const { return size_; } // returns the size of the array

	int check(double number); // returns index of element containg "number" or -1 if none
	void addNumber(double);    // adds number to the collection
	void removeNumber(double); // deletes the number from the collection
	void output();      // prints the values of the collection

	// big three
	Collection(const Collection&); // copy constructor
	Collection& operator=(const Collection&); // overloaded assignment
	~Collection(); // destructor

private:
	double* col_; // pointer to the dynamically allocated array holding collection of doubles
	int size_;   // array size
};

#endif /* COLLECTION_HPP_ */