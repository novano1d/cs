#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: Matthew Moore
// Date:       Spring 2022
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>

////////////////////////////////////////////////////////////////////////////
//           
template <typename T>
class node 
{
public:
    node()           : next(0) {};
    node(const T& x) : data(x), next(0) {};
    T        data;    //The data (element)
    node<T>* next;    //Pointer to a node
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T>
class stack {
public:
              stack     () : tos(0) {};
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      empty     () const { return tos == 0; };
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);

private:
	node<T>   *tos;
};

template <typename T>
void stack<T>::push(const T& item)
{
    assert(!full());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}

template <typename T>
T stack<T>::top() const
{
    assert(!empty());
    return tos->data;
}

template <typename T>
T stack<T>::pop()
{
    assert(!empty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
stack<T>::~stack()
{
    node<T> *temp;
    while (tos != 0)
    {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() //sets tos to zero
{
    // node<T> *temp = actual.tos;
    // node<T> *bottom = 0;
    // while (temp != 0)
    // {
    //     if (tos == 0)
    //     {
    //         tos = new node<T>(temp->data);
    //         bottom = tos;
    //     }
    //     else
    //     {
    //         bottom->next = new node<T>(temp->data);
    //     }
    //     temp = temp->next;
    // }
    //idk why but the lecture copy contructor wasn't working for me
    if(actual.empty()) tos = 0;
    else
    {
        node<T> *ptr = actual.tos;
        node<T> *temp = new node<T>(ptr->data);
        tos = temp;
        node<T> *tail = temp;
        while(ptr->next != 0)
        {
            ptr = ptr->next;
            temp = new node<T>(ptr->data);
            tail->next = temp;
            tail = temp;
        }
    }
}

template <typename T>
void stack<T>::swap(stack<T>& rhs)
{
    node<T> *temp = rhs.tos;
    rhs.tos = tos;
    tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs)
{
    swap(rhs);
    return *this;
}

template <typename T>
bool stack<T>::full() const
{
    node<T> *temp = new(std::nothrow) node<T>(); //returns 0 if not enough memory to create the object
    if (temp == 0) return true; //object not created
    delete temp; //deallocate if we did create the object
    return false;
}

#endif
