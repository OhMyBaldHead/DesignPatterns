#include<iostream>
#include<string>
using namespace std;

//产品部分
class Product {
public:
    virtual void myname() = 0;
};

class ProductA : public Product {
public:
    virtual void myname() override {
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "ProductA";
};

class ProductB : public Product {
public:
    virtual void myname() override{
        cout << "myname: " << name << endl;
    }
    void func1() {
    }
private:
    string name = "ProductB";
};

//工厂部分
class Factory {
public:
    virtual Product* createProduct() = 0;
};

class FactoryA : public Factory {
public:
    virtual Product* createProduct() override {
        return new ProductA();
    }
};  

class FactoryB : public Factory {
public:
    virtual Product* createProduct() override {
        return new ProductB();
    }
};  

int main() {
    Factory* factoryA = new FactoryA();
    Product* productA = factoryA->createProduct();
    productA->myname();
    delete productA;
    delete factoryA;
    return 0;
}       