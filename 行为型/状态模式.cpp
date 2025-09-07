#include <iostream>
#include <string>
using namespace std;

// 前向声明
//状态类之间的互相引用，且使用了类内的方法，可以份文件编写来避免循环引用时的编译错误
class Elevator;
class OpenState;
class CloseState;
class RunState;
class StopState; 

// 状态基类
class State {
public:
    virtual void open(Elevator* elevator) = 0;
    virtual void close(Elevator* elevator) = 0;
    virtual void run(Elevator* elevator) = 0;
    virtual void stop(Elevator* elevator) = 0;
    virtual string getStateName() = 0;
    virtual ~State() = default; // 虚析构函数
};

// 电梯类
class Elevator{
public:
    State* state;
    friend class OpenState;
    friend class CloseState;
    friend class RunState;
    friend class StopState; 
    
    // 构造函数初始化状态
    Elevator() : state(nullptr) {}
    
    void setState(State* state) {
        if(this->state != nullptr){
            delete this->state;
        }
        this->state = state;
    }
    
    void open() {
        if(state != nullptr) state->open(this);
    }
    
    void close() {
        if(state != nullptr) state->close(this);
    }
    
    void run() {
        if(state != nullptr) state->run(this);
    }
    
    void stop() {
        if(state != nullptr) state->stop(this);
    }   
    
    void getCurrentState() {
        if(state != nullptr)
            cout << "current state is " << state->getStateName() << endl;
        else
            cout << "no state" << endl;
    }
    
    ~Elevator() {
        delete state;
    }       
};

// 开门状态
class OpenState : public State {
public:
    friend class CloseState;
    void open(Elevator* elevator) override {
        cout << "already open" << endl;
    }
    
    void close(Elevator* elevator) override {
        cout << "closing door" << endl;
        elevator->setState(new CloseState());
    }
    
    void run(Elevator* elevator) override {
        cout << "can't run when door is open" << endl;
    }
    
    void stop(Elevator* elevator) override {
        cout << "already stopped" << endl;
    }
    
    string getStateName() override {
        return "open";
    }
};

// 关门状态
class CloseState : public State {
public:
    void open(Elevator* elevator) override {
        cout << "opening door" << endl;
        elevator->setState(new OpenState());
    }
    
    void close(Elevator* elevator) override {
        cout << "already closed" << endl;
    }
    
    void run(Elevator* elevator) override {
        cout << "starting to run" << endl;
        elevator->setState(new RunState());
    }
    
    void stop(Elevator* elevator) override {
        cout << "already stopped" << endl;
    }
    
    string getStateName() override {
        return "close";
    }
};      

// 运行状态
class RunState : public State {
public:    
    void open(Elevator* elevator) override {
        cout << "can't open door when running" << endl;
    }
    
    void close(Elevator* elevator) override {
        cout << "door already closed" << endl;
    }
    
    void run(Elevator* elevator) override {
        cout << "already running" << endl;
    }
    
    void stop(Elevator* elevator) override {
        cout << "stopping" << endl;
        elevator->setState(new StopState());
    }
    
    string getStateName() override {
        return "run";
    }
};  

// 停止状态
class StopState : public State {
public:  
    void open(Elevator* elevator) override {
        cout << "opening door" << endl;
        elevator->setState(new OpenState());
    }
    
    void close(Elevator* elevator) override {
        cout << "door already closed" << endl;
    }
    
    void run(Elevator* elevator) override {
        cout << "starting to run" << endl;
        elevator->setState(new RunState());
    }
    
    void stop(Elevator* elevator) override {
        cout << "already stopped" << endl;
    }
    
    string getStateName() override {
        return "stop";
    }
};      

int main() {
    Elevator* elevator = new Elevator();
    elevator->setState(new StopState());
    elevator->getCurrentState();
    
    elevator->open();
    elevator->getCurrentState();
    
    elevator->close();
    elevator->getCurrentState();
    
    elevator->run();
    elevator->getCurrentState();
    
    elevator->stop();
    elevator->getCurrentState();
    
    delete elevator;
    return 0;
}
