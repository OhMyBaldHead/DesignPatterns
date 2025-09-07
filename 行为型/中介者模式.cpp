//中介者模式，就是专门管理消息发送的
//例如ABCDEFGHIJKLMN，如果A想要发给BCD，那么不用直接写A.send(B),A.send(C),A.send(D);
//而是写一个中介者，中介者管理A，B，C，D，当A想要发给BCD的时候，直接写A.send(Mediator)，中介者收到消息后，再分别发送给B，C，D
//所有的消息传递都可以定义在中介中，十分方便。

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mediator{
public:
    virtual void send(string message) = 0;
};

class Person{
public:
    string name;
    string message;
    Person(string name, string message):name(name), message(message){}
    virtual void send(string message) = 0;
    virtual void receive(string message) = 0;
};

class PersonA : public Person{
public:
    vector<Mediator*> mediators;
    PersonA(string name) : Person(name, ""){}
    void send(string message){
        this->message = message;
        cout << name << "发送消息：" << endl;
        for(Mediator* mediator : mediators){            
            mediator->send(message);
        }   
    }
    void receive(string message){
        cout << name << "收到消息：" << message << endl;
    }
    void addMediator(Mediator* mediator){
        mediators.push_back(mediator);
    }   
    void removeMediator(Mediator* mediator){
        for(int i = 0; i < mediators.size(); i++){
            if(mediators[i] == mediator){
                mediators.erase(mediators.begin() + i);
            }
        }
    }
};

class MediatorA : public Mediator{
public:
    vector<Person*> person;
    void send(string message){
        for(Person* p : person){
            p->receive(message);
        }
    }
    void addPerson(Person* p){
        person.push_back(p);
    }
    void removePerson(Person* p){
        for(int i = 0; i < person.size(); i++){
            if(person[i] == p){
                person.erase(person.begin() + i);
            }
        }
    }
};

int main(){ 
    PersonA* p1 = new PersonA("A");
    PersonA* p2 = new PersonA("B");
    PersonA* p3 = new PersonA("C");
    PersonA* p4 = new PersonA("D");
    PersonA* p5 = new PersonA("E");
    PersonA* p6 = new PersonA("F");
    MediatorA* m1 = new MediatorA();
    m1->addPerson(p4);
    m1->addPerson(p5);
    m1->addPerson(p6);
    p1->addMediator(m1);
    p2->addMediator(m1);
    p1->send("hello");
    delete m1;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;      
    return 0;

}





