//Matthew Moore
//12-2-2022
// adding/removing lines of text, demos Memento Design Pattern
// Mikhail Nesterenko
// 11/22/2014

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <vector>

using std::vector; using std::string;
using std::cout; using std::cin; using std::endl;

// originator
class Document {
public:
   Document(vector <string> lines={}): lines_(lines){}

   void insert(int line, const string &str) {
      int index = line-1;
      if (index <= lines_.size()+1)
	 lines_.insert(lines_.begin()+index, str); 
      else
	 cout << "line out of range" << endl;
   }

   string remove(int line) {
      const int index = line-1;
      string deletedLine="";
      if(index < lines_.size()){
	 deletedLine = lines_[index];
	 lines_.erase(lines_.begin() + index); 
      }else
	 cout << "line out of range" << endl; 
      return deletedLine;
   } 

   void show() {
      for(int i = 0; i < lines_.size(); ++i)
	 cout << i + 1 << ". " << lines_[i] << endl; 
   }

   class Memento *createMemento() const;  
   void rollBack(class Memento *); 

private:
   vector<string> lines_; 
};

// abstract command
class Command{
public:
   Command(Document *doc) : doc_(doc){}
   virtual void execute() = 0; 
   virtual void unexecute() = 0; 
   virtual ~Command(){}
   virtual void show() const = 0;
protected:
   Document *doc_; 
}; 

// two concrete commands
class InsertCommand : public Command {
public:
   InsertCommand(Document *doc, int line, const string &str): 
      Command(doc), line_(line),  str_(str) {}
   void execute() override { doc_->insert(line_, str_);}
   void unexecute() override {doc_->remove(line_);}
   void show() const override
   {
    cout << "insert \"" << str_ << "\" at line" << line_ << endl;
   }
private:
   int line_; 
   string str_; 
}; 


class EraseCommand : public Command {
public:
   EraseCommand(Document *doc, int line): 
      Command(doc), line_(line), str_("") {}
   void execute() override {str_ = doc_->remove(line_);}
   void unexecute() override {doc_->insert(line_, str_);}
   void show() const override
   {
    cout << "erase line " << line_ << endl;
   }
private:
   int line_;
   string str_;
};

// client
class DocumentWithHistory{
public:
   DocumentWithHistory(const vector<string> & text={}) : doc_(text){}

   void insert(int line, string str) {
      Command *com = new InsertCommand(&doc_, line, str); 
      com->execute(); 
      doneCommands_.push(com); 
      commandsInOrder_.push_back(com);
   }

   void erase(int line){
      Command *com = new EraseCommand(&doc_, line);
      com->execute();
      doneCommands_.push(com);
      commandsInOrder_.push_back(com);
   }

   void undo() {
      if(doneCommands_.size() != 0) {
	 Command *com = doneCommands_.top(); 
	 doneCommands_.pop(); 
     commandsInOrder_.pop_back();
	 com->unexecute();
	 delete com; // don't forget to delete command
      }else
	 cout << "no commands to undo" << endl; 
   }
    class Memento *createMemento() const;  
   void rollBack(class Memento *); 
   void show() {doc_.show();}

    void history()
    {
        for (int i = 0; i < commandsInOrder_.size(); i++)
        {
            if (i == 0) cout << endl;
            cout << (i+1) << ". ";
            commandsInOrder_[i]->show();
        }
        cout << endl;
    }

    void redo(int comNum)
    {
        if (commandsInOrder_.empty())
        {
            cout << "No commands to redo." << endl;
            return;
        }
        Command* commandToRedo = commandsInOrder_[comNum-1];
        commandToRedo->execute();
        doneCommands_.push(commandToRedo);
        commandsInOrder_.push_back(commandToRedo);
    }

private:
   Document doc_;
   std::stack<Command*> doneCommands_; 
   std::vector<Command*> commandsInOrder_;
}; 


class Memento {
public:
   Memento(const DocumentWithHistory& doc): doc_(doc) {}
   const DocumentWithHistory& getState() const {return doc_;}
private:
   const DocumentWithHistory doc_;
};
 
Memento *DocumentWithHistory::createMemento() const{
   return new Memento(*this); // copying the Document itself
}

void DocumentWithHistory::rollBack(Memento *mem){
   *this = mem->getState();  // copying back
}

// client and caretaker
int main() {

   DocumentWithHistory doc({
         "Lorem Ipsum is simply dummy text of the printing and typesetting",
         "industry. Lorem Ipsum has been the industry's standard dummy text",
         "ever since the 1500s, when an unknown printer took a galley of",
	 "type and scrambled it to make a type specimen book. It has",
	 "survived five centuries."});

   char option;
   
   do{
      static Memento *checkpoint = nullptr;

      doc.show();
      cout << endl;

      cout << "Enter option (i)nsert line, (e)rase line, (u)ndo last command, (c)heckpoint, roll(b)ack, (h)istory, (r)edo: ";
      cin >> option;

      int line; string str; 
      switch(option) {
      case 'i':
         cout << "line number to insert: ";
         cin >> line;
         cout << "line to insert: ";
	 cin.get();
         getline(cin, str);
         doc.insert(line, str);
         break;
      case 'e':
         cout << "line number to remove: ";
         cin >> line;
         doc.erase(line);
         break;
      case 'c':
	 checkpoint = doc.createMemento();
	 break;
      case 'b':
	 if (checkpoint != nullptr){
	    doc.rollBack(checkpoint);
	    delete checkpoint; checkpoint = nullptr;
	 }
         break;
        case 'u':
        doc.undo();
        break;
        case 'h':
        doc.history();
        break;
        case 'r':
        cout << "command to redo: ";
        cin >> line;
        doc.redo(line);
        break;
      }
   }while(option == 'i' || option == 'e' || option == 'c' || option == 'r' || option == 'u' || option == 'b' || option == 'h');
}