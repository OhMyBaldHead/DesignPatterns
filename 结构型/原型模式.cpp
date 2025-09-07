//原型模式就是对象的复制，利用已有的一个原型对象，快速地生成和原型对象一样的实例。
//原型模式是一种对象创建型模式。
//原型模式主意浅拷贝和深拷贝

#include <iostream>
#include <string>
using namespace std;    

class Prototype
{
public:
    virtual ~Prototype() {}
    virtual void show() = 0;    
    virtual Prototype* clone() = 0;
};

class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype(string name,int id) : name(new string(name)),id(id) {}
    ConcretePrototype(const ConcretePrototype& cp) {
        name = new string(*cp.name);
        id = cp.id;
    }
    ~ConcretePrototype() {}
    Prototype* clone()
    {
        return new ConcretePrototype(*this);
    }
    void show() override
    {
        cout << "name: " << *name << endl;
        cout << "id: " << id << endl;   
    }
private:
    string* name;
    int id;
};

int main()
{
    Prototype* p1 = new ConcretePrototype("zhangsan",1);
    Prototype* p2 = p1->clone();
    p1->show();
    p2->show();
    delete p1;
    delete p2;
    return 0;
}