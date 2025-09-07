//观察者，就是把信息的发布者中添加观察者，然后信息发布者发布之后，可以直接通知观察者更替消息

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observer {
public:
    virtual void update(string n) = 0;
};

class Computer : public Observer {
public:
    string news;
    virtual void update(string n) override {
        news = n;
        cout << "computer get news: " << news << endl;
    }
};

class Phone : public Observer {
public:
    string news;
    virtual void update(string n) override {
        news = n;
        cout << "phone get news: " << news << endl;
    }
};

class CCTV {
public:
    vector<Observer*> observers;
    void attach(Observer* o) {
        observers.push_back(o);
    }
    void detach(Observer* o) {
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i] == o) {
                observers.erase(observers.begin() + i);
            }
        }
    }
    void notify(string n) {
        for (int i = 0; i < observers.size(); i++) {
            observers[i]->update(n);
        }
    }
};
  
int main() {
    Computer c;
    Phone p;
    CCTV cctv;
    cctv.attach(&c);
    cctv.attach(&p);
    cctv.notify("new news1");
    cctv.detach(&p);
    cctv.notify("new news2");
    return 0;
}
