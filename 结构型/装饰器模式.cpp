//装饰器模式就是可以灵活地给一个实例添加新的功能，同时又不改变其结构
//下面以奶茶+小料为例子解释装饰器

#include <iostream>
#include <string>
using namespace std;

//基础饮品，包括茶，牛奶，咖啡
class drink {
public:
    virtual string name() = 0;
    virtual float price() = 0;
};

class tea : public drink {
public:
    virtual string name() override {
        return "tea";
    }
    virtual float price() override {
        return 10;
    }
};

class milk : public drink {
public:
    virtual string name() override {
        return "milk";
    }
    virtual float price() override {
        return 5;
    }
};

class Coffee : public drink {
public:
    virtual string name() override {
        return "coffee";
    }
    virtual float price() override {
        return 20;
    }
};

//调料，包括糖，冰，柠檬，珍珠
class drinkDecorator : public drink {
protected:
    drink* pdrink;   
public:
    drinkDecorator(drink* drink) : pdrink(drink) {}
    virtual string name() = 0;
    virtual float price() = 0;
};

class AddSugar : public drinkDecorator {
public:
    AddSugar(drink* drink) : drinkDecorator(drink) {}
    virtual string name() override {
        return pdrink->name() + " + sugar";
    }
    virtual float price() override {
        return pdrink->price() + 2;
    }
};

class AddIce : public drinkDecorator {
public:
    AddIce(drink* drink) : drinkDecorator(drink) {}
    virtual string name() override {
        return pdrink->name() + " + ice";
    }
    virtual float price() override {
        return pdrink->price() + 3;
    }
};

//珍珠
class AddPearl : public drinkDecorator {
public:
    AddPearl(drink* drink) : drinkDecorator(drink) {}
    virtual string name() override {
        return pdrink->name() + " + pearl";
    }
    virtual float price() override {
        return pdrink->price() + 5;
    }
};  

int main(){
    drink* p = new tea();
    cout << p->name() << " " << p->price() << endl;
    drink* p1 = new AddSugar(p);
    cout << p1->name() << " " << p1->price() << endl;
    drink* p2 = new AddIce(p1);
    cout << p2->name() << " " << p2->price() << endl;
    drink* p3 = new AddPearl(p2);
    cout << p3->name() << " " << p3->price() << endl;
    delete p;
    delete p1;
    delete p2;
    delete p3;
    return 0;
}



