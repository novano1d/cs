//Matthew Moore
//12-2-2022
// traversing genealogical tree using Composite and Visitors
// Mikhail Nesterenko
// 11/17/2022

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl;
using std::string; 
using std::vector;

class Person{ // component
public:
   Person(string firstName, Person *spouse, Person *father, Person *mother):
      firstName_(firstName), spouse_(spouse), father_(father), mother_(mother){}
   const string & getFirstName(){return firstName_;}
   Person *getSpouse(){return spouse_;}
   void setSpouse(Person *spouse){spouse_=spouse;}
   Person *getFather(){return father_;}
   virtual const string & getLastName() const = 0;
   virtual void accept(class PersonVisitor *)=0;  
   virtual ~Person(){}
protected:
   const string firstName_;
   Person *spouse_;
   Person *father_;
   Person *mother_;
};


// leaf
// man has a last name
class Man: public Person{
public:
   Man(string lastName, string firstName, Person *spouse, 
       Person *father, Person *mother): 
      lastName_(lastName), 
      Person(firstName, spouse, father, mother){}
   const string & getLastName() const override {return lastName_;}
   void accept(class PersonVisitor *visitor) override;
private:
   const string lastName_;
};

// composite
// woman has a list of children
class Woman: public Person{
public: 
   Woman(vector<Person *> children, 
       string firstName, 
       Person *spouse, 
       Person *father, Person *mother): 
       children_(children),
       Person(firstName, spouse, father, mother){}
   const vector<Person *> & getChildren() const {return children_;}
   void setChildren(const vector<Person *> &children){ children_ = children;}
   void accept(class PersonVisitor *visitor) override;
   const string & getLastName() const override
   {
    if(spouse_ != nullptr) return static_cast<Man*>(spouse_)->getLastName();
    else if (father_ != nullptr) return static_cast<Man*>(father_)->getLastName();
    return "Smith";
   }
private:
   vector<Person *> children_;
}; 

// abstract visitor
class PersonVisitor{
public:
   virtual void visit(Man*)=0;
   virtual void visit(Woman*)=0;
   virtual ~PersonVisitor(){}
};

// composite methods that define traversal
void Man::accept(PersonVisitor *visitor) {
    visitor->visit(this);
}

void Woman::accept(PersonVisitor *visitor){ 
   // children traversal through mother only
   // father's children are not traversed so as not 
   // to traverse them twice: for mother and father

   visitor->visit(this);

   // traversing descendants
   for(auto child : children_) 
      child->accept(visitor);   
}

// concrete visitors
// the last name for a man is stored in object
// the last name a woman is determined by her 
// spouse if she is married
// or by her father if she is not
class NamePrinter: public PersonVisitor{
public:
   void visit(Man *m) override {
      cout << m->getFirstName() << " " << m->getLastName() << endl;
   }
   void visit(Woman *w) override {
      cout << w->getFirstName() << " ";
      if (w->getSpouse() != nullptr)
	 cout << static_cast<Man *>(w->getSpouse())->getLastName();
      else if (w->getFather() != nullptr)
	 cout << static_cast<Man *> (w->getFather())->getLastName();
      else
	 cout << "Doe";
      cout << endl;
   }
};


class ChildrenPrinter: public PersonVisitor{
public:
   void visit(Man *m) override {
      cout << m->getFirstName() << ": ";
      Woman *spouse = static_cast<Woman *>(m->getSpouse());
      if(spouse != nullptr)
	 printNames(spouse->getChildren());
      cout << endl;
   }
   void visit(Woman *w) override {
      cout << w->getFirstName() << ": ";
      printNames(w->getChildren());
      cout << endl;
   }
private:
   void printNames(const vector<Person *> &children){
      for(const auto c: children)
	 cout << c->getFirstName() << ", ";
   }
};

//There is almost certainly a better way to do this
class RelationshipPrinter : public PersonVisitor
{
public:
    RelationshipPrinter(string firstPerson, string secondPerson) : firstPerson_(firstPerson), secondPerson_(secondPerson) {};
    void visit(Man *m) override 
    {
        if (firstPerson_ == secondPerson_)
        {
            isRelated = true;
            return;
        }
        else if((m->getFirstName() + " " + m->getLastName()) == firstPerson_)
        {
            //check children
            if (m->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman *>(m->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + m->getLastName() == secondPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
                //check mom's siblings
                if (m->getSpouse()->getFather() != nullptr && m->getSpouse()->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getSpouse()->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == secondPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
            }
            //check parents
            if (m->getFather() != nullptr)
            {
                if (m->getFather()->getFirstName() + " " + m->getLastName() == secondPerson_ || m->getFather()->getSpouse()->getFirstName() + " " + m->getLastName() == secondPerson_)
                {
                    isRelated = true;
                    return;
                }
                //siblings
                if (m->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == secondPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
                //check dad's siblings
                if (m->getFather()->getFather() != nullptr && m->getFather()->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getFather()->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == secondPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
            }
        }
        else if ((m->getFirstName() + " " + m->getLastName()) == secondPerson_)
        {
                        //check children
            if (m->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman *>(m->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + m->getLastName() == firstPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
                //check mom's siblings
                if (m->getSpouse()->getFather() != nullptr && m->getSpouse()->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getSpouse()->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == firstPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
            }
            //check parents
            if (m->getFather() != nullptr)
            {
                if (m->getFather()->getFirstName() + " " + m->getLastName() == firstPerson_ || m->getFather()->getSpouse()->getFirstName() + " " + m->getLastName() == firstPerson_)
                {
                    isRelated = true;
                    return;
                }
                //siblings
                if (m->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == firstPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
                //check dad's siblings
                if (m->getFather()->getFather() != nullptr && m->getFather()->getFather()->getSpouse() != nullptr)
                {
                    auto siblings = static_cast<Woman *>(m->getFather()->getFather()->getSpouse())->getChildren();
                    for (Person* p : siblings)
                    {
                        if (p->getFirstName() + " " + m->getLastName() == firstPerson_)
                        {
                            isRelated = true;
                            return;
                        }
                    }
                }
            }
        }
    }
    //fix problems with invalid string read if possible
    void visit(Woman *w) override 
    {
        if (firstPerson_ == secondPerson_)
        {
            isRelated = true;
            return;
        }
        else if (w->getSpouse() != nullptr && (w->getFirstName() + " " + static_cast<Man *>(w->getSpouse())->getLastName()) == firstPerson_)
        {
            //check siblings
            if (w->getFather() != nullptr && w->getFather()->getSpouse() != nullptr)
            {
                auto siblings = static_cast<Woman *>(w->getFather()->getSpouse())->getChildren();
                for (Person* p : siblings)
                {
                    if (p->getFirstName() + " " + p->getLastName() == secondPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //check parents
            if (w->getFather() != nullptr)
            {
                if (w->getFather()->getFirstName() + " " + w->getLastName() == secondPerson_)
                {
                    isRelated = true;
                    return;
                }
            }
            if (w->getFather() != nullptr && w->getFather()->getSpouse() != nullptr)
            {
                if(w->getFather()->getSpouse()->getFirstName() + " " + w->getLastName() == secondPerson_)
                {
                    isRelated = true;
                    return;
                }
            }
            //check children
            {
                auto children = w->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == secondPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //aunts and uncles
            //dad's side
            if (w->getFather() != nullptr && w->getFather()->getFather() != nullptr && w->getFather()->getFather()->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman*>(w->getFather()->getFather()->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == secondPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //mom's side
            if (w->getFather() != nullptr && w->getFather()->getSpouse() != nullptr && w->getFather()->getSpouse()->getFather() != nullptr && w->getFather()->getSpouse()->getFather()->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman*>(w->getFather()->getSpouse()->getFather()->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == secondPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
        }
        else if (w->getSpouse() != nullptr && (w->getFirstName() + " " + static_cast<Man *>(w->getSpouse())->getLastName()) == secondPerson_)
        {
            //check siblings
            if (w->getFather() != nullptr && w->getFather()->getSpouse() != nullptr)
            {
                auto siblings = static_cast<Woman *>(w->getFather()->getSpouse())->getChildren();
                for (Person* p : siblings)
                {
                    if (p->getFirstName() + " " + p->getLastName() == firstPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //check parents
            if (w->getFather() != nullptr)
            {
                if (w->getFather()->getFirstName() + " " + static_cast<Man*>(w->getFather())->getLastName() == firstPerson_)
                {
                    isRelated = true;
                    return;
                }
            }
            if (w->getFather()->getSpouse() != nullptr)
            {
                if(w->getFather()->getSpouse()->getFirstName() + " " + static_cast<Man*>(w->getFather())->getLastName() == firstPerson_)
                {
                    isRelated = true;
                    return;
                }
            }
            //check children
            {
                auto children = w->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == firstPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //aunts and uncles
            //dad's side
            if (w->getFather() != nullptr && w->getFather()->getFather() != nullptr && w->getFather()->getFather()->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman*>(w->getFather()->getFather()->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == firstPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
            //mom's side
            if (w->getFather() != nullptr && w->getFather()->getSpouse() != nullptr && w->getFather()->getSpouse()->getFather() != nullptr && w->getFather()->getSpouse()->getFather()->getSpouse() != nullptr)
            {
                auto children = static_cast<Woman*>(w->getFather()->getSpouse()->getFather()->getSpouse())->getChildren();
                for (Person* p : children)
                {
                    if (p->getFirstName() + " " + p->getLastName() == firstPerson_)
                    {
                        isRelated = true;
                        return;
                    }
                }
            }
        }
    }
    void printRelation()
        {
            if (isRelated)
            {
                cout << "They are close relatives.";
            }
            else cout << "They are just friends.";
        }
private:
    bool isRelated = false;
    string firstPerson_;
    string secondPerson_;
};

// demonstrating the operation
int main(){

   // setting up the genealogical tree      
   // the tree is as follows
   //    
   //
   //       James Smith  <--spouse-->   Mary 
   //	                                  |
   //	                                 children -------------------------
   //	                                  |              |                |
   //	                                  |              |                |
   //	   William Johnson <--spouse-> Patricia      Robert Smith       Linda
   //	                                  |
   //	                                 children------------
   //	                                  |                 |
   //                                     |                 |
   //	   Jennifer  <--spouse-->  Michael Johnson      Barbara
   //	       |
   //	     children
   //	       |
   //          |
   //	     Susan


   // first generation
   Man *js = new Man("Smith", "James", nullptr, nullptr, nullptr);
   Woman *ms = new Woman({}, "Mary", nullptr, nullptr, nullptr);
   ms->setSpouse(js); js->setSpouse(ms);

   // second generation
   Woman *ps = new Woman({}, "Patricia",  nullptr, js, ms);
   Man *wj = new Man("Johnson", "William", nullptr, nullptr, nullptr);
   ps->setSpouse(wj); wj->setSpouse(ps);

   vector<Person *> marysKids  = {ps,
			          new Man("Smith", "Robert", nullptr, js, ms),
			          new Woman({}, "Linda", nullptr, js, ms)};
   ms->setChildren(marysKids);

   // third generation
   Man *mj = new Man("Johnson", "Michael", nullptr, wj, ps);
   vector<Person *> patsKids   = {mj, new Woman({}, "Barbara", nullptr, wj, ps)}; 
   ps->setChildren(patsKids);

   Woman *jj = new Woman({}, "Jennifer", nullptr, nullptr, nullptr);
   vector<Person *> jensKids = {new Woman({}, "Susan", nullptr, mj ,jj)};

   jj->setSpouse(mj); mj->setSpouse(jj);
   jj->setChildren(jensKids);
   

   // defining two visitors
   ChildrenPrinter *cp = new ChildrenPrinter;
   NamePrinter *np = new NamePrinter;
    
   // executing the traversal with the composite
   // and the specific visitor

   /*
   cout << "\nNAME LIST\n";
   ms->accept(np);
   cout << endl << endl;
   

   cout << "CHILDREN LIST\n";
   ms->accept(cp);
   */
  
  string s1, s2;
  cout << "Enter first candidate: ";
  std::getline(std::cin, s1);
  cout << "Enter second candidate: ";
  std::getline(std::cin, s2);
  RelationshipPrinter *rp = new RelationshipPrinter(s1, s2);
  ms->accept(rp);
  rp->printRelation();
  cout << endl;
}