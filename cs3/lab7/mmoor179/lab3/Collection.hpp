// Modified by Matthew Moore 9/15/2022
// Added Collection class
#ifndef LIST_HPP_
#define LIST_HPP_

// the pointer part of every list is the same
// lists differ by data part
template<typename T>
class Collection;
template <typename T>
bool equal(const Collection<T>& one, const Collection<T>& two);

template <typename T>
class node{
public:

  node(): next_(nullptr) {}

  // functions can be inlined
  T getData() const {return data_;}
  void setData(const T& data){data_=data;}

  // or can be defined outside
  node<T>* getNext() const;
  void setNext(node<T> *const);

private:
  T data_;
  node<T> *next_;
};

template <typename T>
class Collection
{
public:
  Collection() { head = nullptr; };
  void add(const T& toAdd)
  {
    node<T> *newNode = new node<T>();
    newNode->setData(toAdd);
    if (head == nullptr)
    {
      head = newNode;
      return;
    }
    node<T> *temp = head;
    while (temp->getNext() != nullptr)
    {
      temp = temp->getNext();
    }
    temp->setNext(newNode);
  }
  void print() const
  {
    if (head == nullptr) return;
    node<T> *current = head;
    while (current->getNext() != nullptr)
    {
      std::cout << current->getData() << std::endl;
      current = current->getNext();
    }
    std::cout << current->getData() << std::endl;
  }
  void remove(const T& toRemove) //I have a feeling I overcomplicated this? Maybe not.
  {
    if (head == nullptr) return;
    node<T> *current = head;
    node<T> *prev = head;
    while (current->getNext() != nullptr)
    {
      if (current->getData() == toRemove)
      {
        node<T> *temp = current;
        current = current->getNext();
        if (prev != head || temp != head) prev->setNext(current);
        else
        {
          prev = head = current;
        }
        delete temp;
      }
      else
      {
        prev = current;
        current = current->getNext();
      }
    }
    if(current->getData() == toRemove)
    {
      if (current == head && prev == head) head = nullptr;
      else
      {
        delete current;
        prev->setNext(nullptr);
      }
    }
  }
  T last() const 
  {
    //if (head == nullptr) return NULL;
    //was giving error? What should I return if nothing is in the collection?
    if (head == nullptr) return T(); //decided on default... whatever that is but still creates the problem because the default could be an item in the collection and there is no way to know
    //looks like you'd have to return a pointer to return null? not sure
    node<T> *current = head;
    while (current->getNext() != nullptr)
    {
      current = current->getNext();
    }
    return current->getData();
  }
  friend bool equal<T>(const Collection& one, const Collection& two);
private:
  node<T> *head;
};

template <typename T>
bool equal(const Collection<T>& one, const Collection<T>& two)
{
  node<T> *cur1 = one.head;
  node<T> *cur2 = two.head;
  while (cur1 != nullptr && cur2 != nullptr)
  {
    if (cur1->getData() != cur2->getData()) return false;
    cur1 = cur1->getNext();
    cur2 = cur2->getNext();
  }
  if ((cur1 == nullptr && cur2 != nullptr) || (cur2 == nullptr && cur1 != nullptr )) return false;
  return true;
}
//
// member functions for node
//
template <typename T>
node<T>* node<T>::getNext() const {
  return next_;
}

template<typename T>
void node<T>::setNext(node<T> *const next){
   next_=next;
}

#endif // LIST_HPP_