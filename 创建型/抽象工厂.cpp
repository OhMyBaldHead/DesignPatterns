#include<iostream>
#include<string>
using namespace std;

//苹果香蕉
class Apple {
public:
    virtual void myname() = 0;
};
class Banana {
public:
    virtual void myname() = 0;
};
//工厂
class Factory {
public:
    virtual Apple* createApple() = 0;
    virtual Banana* createBanana() = 0;
};



//中国，美国，日本地区的苹果香蕉
class ChinaApple : public Apple {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "ChinaApple";         
};
class ChinaBanana : public Banana {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "ChinaBanana";         
};

class AmericaApple : public Apple {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "AmericaApple";         
};
class AmericaBanana : public Banana {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "AmericaBanana";         
};

class JapanApple : public Apple {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "JapanApple";         
};
class JapanBanana : public Banana {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:    
    string name = "JapanBanana";         
};  

//各地的工厂
class ChinaFactory : public Factory {
public:
    virtual Apple* createApple() override {
        return new ChinaApple();
    }
    virtual Banana* createBanana() override {
        return new ChinaBanana();
    }
};
class AmericaFactory : public Factory {
public:
    virtual Apple* createApple() override {
        return new AmericaApple();
    }
    virtual Banana* createBanana() override {
        return new AmericaBanana();
    }
};
class JapanFactory : public Factory {
public:
    virtual Apple* createApple() override {
        return new JapanApple();
    }
    virtual Banana* createBanana() override {
        return new JapanBanana();
    }
};              


int main() {
    Factory* chinaFactory = new ChinaFactory();
    Apple* ChinaApple = chinaFactory->createApple();
    ChinaApple->myname();
    delete ChinaApple;
    delete chinaFactory;
    return 0;
}       