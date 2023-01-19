//Matthew Moore
//11-10-2022
#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

//Forward declaration
class State;

class Process
{
public:
    Process(); //increment id and set starting state

    //helper function
    static int getProcessId() { return id_; };

    //behaviors
    string report();
    void dispatch();
    void block();
    void suspend();
    void unblock();
    void exit();

    //state pattern implementation
    void changeState(State* state) { state_ = state; };
private:
    State* state_;
    inline static int id_ = 0;
};


//Abstract state
class State
{
public:
    virtual void dispatch(Process*){};
    virtual void block(Process*){};
    virtual void suspend(Process*){};
    virtual void unblock(Process*){};
    virtual void exit(Process*){};
    virtual string report() = 0;
    void changeState(Process* p, State* s)
    {
        p->changeState(s);
    }
};

class Ready: public State
{
public:
    static State* instance()
    {
        static State* onlyInstance = new Ready;
        return onlyInstance;
    }
    string report() override
    {
        return "Process " + std::to_string(Process::getProcessId()) + " is ready";
    }
    void dispatch(Process*) override;
};

class Running: public State
{
public:
    static State* instance()
    {
        static State* onlyInstance = new Running;
        return onlyInstance;
    }
    string report() override
    {
        return "Process " + std::to_string(Process::getProcessId()) + " is running";
    }
    void block(Process*) override;
    void suspend(Process*) override;
    void exit(Process*) override;
};

class Blocked: public State
{
public:
    static State* instance()
    {
        static State* onlyInstance = new Blocked;
        return onlyInstance;
    }
    string report() override
    {
        return "Process " + std::to_string(Process::getProcessId()) + " is blocked";
    }
    void unblock(Process*) override;
};

void Ready::dispatch(Process* p)
{
    changeState(p, Running::instance());
}
void Running::block(Process* p)
{
    changeState(p, Blocked::instance());
}
void Running::suspend(Process* p)
{
    changeState(p, Ready::instance());
}
void Running::exit(Process* p)
{
    delete p;
}
void Blocked::unblock(Process* p)
{
    changeState(p, Ready::instance());
}

//constructor
Process::Process()
{
    ++id_;
    state_ = Ready::instance();
}

//handlers
void Process::dispatch()
{
    state_->dispatch(this);
}
void Process::block()
{
    state_->block(this);
}
void Process::suspend()
{
    state_->suspend(this);
}
void Process::exit()
{
    state_->exit(this);
}
void Process::unblock()
{
    state_->unblock(this);
}
string Process::report()
{
    return state_->report();
}

//Testing
// int main()
// {
//     Process p;
//     cout << p.report() << endl;
//     p.dispatch();
//     cout << p.report() << endl;
//     Process c;
//     cout << c.report() << endl;
//     c.dispatch();
//     cout << c.report() << endl;
//     c.suspend();
//     cout << c.report() << endl;
//     c.unblock();
//     cout << c.report() << endl;
//     c.dispatch();
//     cout << c.report() << endl;
//     c.block();
//     cout << c.report() << endl;
//     c.unblock();
//     cout << c.report() << endl;
// }