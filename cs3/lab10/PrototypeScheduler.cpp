#include <iostream>
#include <queue>


using std::cout; using std::endl; using std::queue;

enum class State {Ready, Running, Blocked, Exited};

//Base class
class ProcessBase
{
public:
    ProcessBase(State s) : state_(s) { totalProcesses++; };
    
    //Methods required for prototype pattern
    virtual ProcessBase* clone() = 0;
    virtual State getState() = 0;
    virtual void setState(State s) = 0;
    virtual int getID() = 0;
    virtual void dispatch() = 0;
    virtual void exit() = 0;
    virtual void block() = 0;
    virtual void unblock() = 0;
    virtual void suspend() = 0;
    virtual ~ProcessBase(){};
protected:
    State state_;
    inline static int totalProcesses = -1; //Makes sense being -1 since prototype will thus be 0
};

class Process: public ProcessBase
{
public:
    Process(State s) : ProcessBase(s) {id_ = totalProcesses; };
    Process* clone() override {return new Process(state_);};
    State getState() override {return state_; };
    int getID() override { return id_; };
    void setState(State s) override { state_ = s; };
    void dispatch() override
    {
        if (state_ == State::Ready) state_ = State::Running;
    }
    void exit() override
    {
        if (state_ == State::Running) state_ = State::Exited;
    }
    void suspend() override
    {
        if (state_ == State::Running) state_ = State::Ready;
    }
    void block() override
    {
        if (state_ == State::Running) state_ = State::Blocked;
    }
    void unblock() override
    {
        if (state_ == State::Blocked) state_ = State::Ready;
    }
private:
    int id_;
};

void printState(ProcessBase* p)
{
    State s = p->getState();
    int id = p->getID();
    cout << "PID " << id << " state: ";
    if (s == State::Blocked) cout << "BLOCKED";
    if (s == State::Running) cout << "RUNNING";
    if (s == State::Ready) cout << "READY";
    if (s == State::Exited) cout << "exited";
    cout << endl;
}

int main()
{
    queue<ProcessBase*> ready;
    queue<ProcessBase*> blocked;
    Process prototypeProcess(State::Ready);
    for (int i = 0; i < 4; i++)
    {
        ready.push(prototypeProcess.clone());
        cout << "PID " << ready.back()->getID() << ": created" << endl;
        printState(ready.back());
    }
    cout << "---------- scheduler running -------------\n";
    while (!ready.empty() || !blocked.empty())
    {
        if(!ready.empty())
        {
            cout << "Dispatching...\n";
            ready.front()->dispatch();
            printState(ready.front());
            int r = rand()%3;
            if (r == 0)
            {
                cout << "Exiting...\n";
                ready.front()->exit();
                printState(ready.front());
                ready.pop();
            }
            else if (r == 1)
            {
                cout << "Suspending...\n";
                ready.front()->suspend();
                printState(ready.front());
                ready.push(ready.front());
                ready.pop();
            }
            else if (r == 2)
            {
                cout << "Blocking...\n";
                ready.front()->block();
                printState(ready.front());
                blocked.push(ready.front());
                ready.pop();
            }
            if (ready.empty()) cout << "\nReady queue is empty\n\n";
        }
        if (!blocked.empty())
        {
            int r = rand()%3; //33 percent chance of getting unblocked
            if (r == 0)
            {
                cout << "Unblocking...\n";
                blocked.front()->unblock();
                printState(blocked.front());
                ready.push(blocked.front());
                blocked.pop();
            }
        }
        if (ready.empty() && blocked.empty()) cout << "all processes exited.\n";
    }
    
}