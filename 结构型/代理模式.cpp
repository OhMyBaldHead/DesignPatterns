//代理模式，就是给一个对象提供一个代理对象，并由代理对象控制对原对象的引用。
//说白了就是给一个对象提供一个替身，以控制对这个对象的访问。
//核心价值有：延迟加载，控制权限


#include <iostream>
#include <string>
using namespace std;

class Company {
public:
    virtual int makeMoney() = 0;
};

class CompanyA : public Company {
public:
    virtual int makeMoney() override {
        cout << "CompanyA makeMoney" << endl;
        return 10000;
    }
};                  

class CompanyB : public Company {
public:
    virtual int makeMoney() override {
        cout << "CompanyB makeMoney" << endl;
        return 20000;
    }
};                  

class ProxyA : public Company {
public:
    CompanyA* companya;
public:
    virtual int makeMoney() override {
        if (companya == nullptr) {
            companya = new CompanyA();
        }
        cout << "ProxyA makeMoney" << endl;
        return companya->makeMoney()+500;
    }
};

int main() {
    ProxyA* proxya = new ProxyA();
    cout << proxya->makeMoney() << endl;
    delete proxya;
    return 0;
}

