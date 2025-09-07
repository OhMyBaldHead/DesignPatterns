#include<iostream>
#include<string>
using namespace std;

//汽车
class Car {
public:
    virtual void detialShow() = 0;
    virtual void setRoof(string roof) = 0;
    virtual void setBody(string body) = 0;
    virtual void setWheel(string wheel) = 0;
};

//奔驰
class Benz : public Car {
public:
    virtual void detialShow() override {
        cout << "name: " << name << endl;
        cout << "roof: " << roof << endl;
        cout << "body: " << body << endl;
        cout << "wheel: " << wheel << endl;
    }
    virtual void setRoof(string roof) override{
        this->roof = roof;
    }
    virtual void setBody(string body) override{
        this->body = body;
    }
    virtual void setWheel(string wheel) override{
        this->wheel = wheel;
    }   
private:
    string name = "Benz";
    string roof;
    string body;
    string wheel;
};  

//宝马
class BMW : public Car {
public:
    virtual void detialShow() override {
        cout << "name: " << name << endl;
        cout << "roof: " << roof << endl;
        cout << "body: " << body << endl;
        cout << "wheel: " << wheel << endl;
    }
    virtual void setRoof(string roof) override{
        this->roof = roof;
    }
    virtual void setBody(string body) override{
        this->body = body;
    }
    virtual void setWheel(string wheel) override{
        this->wheel = wheel;
    }   
private:
    string name = "BMW";
    string roof;
    string body;
    string wheel;
};      

//法拉利
class Ferrari : public Car {                       
public:
    virtual void detialShow() override {
        cout << "name: " << name << endl;
        cout << "roof: " << roof << endl;
        cout << "body: " << body << endl;
        cout << "wheel: " << wheel << endl;
    }
    virtual void setRoof(string roof) override{
        this->roof = roof;
    }
    virtual void setBody(string body) override{
        this->body = body;
    }
    virtual void setWheel(string wheel) override{
        this->wheel = wheel;
    }   
private:
    string name = "Ferrari";
    string roof;
    string body;
    string wheel;
};      

//建造者基类
class CarBuilder
{
public:
    virtual void BuildRoof(string roof) = 0;
    virtual void BuildBody(string body) = 0;
    virtual void BuildWheel(string wheel) = 0;
    virtual Car* getCar() = 0;
};

//奔驰建造者
class BenzBuilder : public CarBuilder
{
public:
    virtual void BuildRoof(string roof) override {
        car->setRoof("BenzRoof:" + roof);
    }
    virtual void BuildBody(string body) override {
        car->setBody("BenzBody:" + body);
    }
    virtual void BuildWheel(string wheel) override {
        car->setWheel("BenzWheel:" + wheel);
    }
    virtual Car* getCar() override {
        return car;
    }
    ~BenzBuilder() {
        if(car)
            delete car;
    }
private:
    Car* car = new Benz();
};

//宝马建造者
class BMWBuilder : public CarBuilder
{
public:
    virtual void BuildRoof(string roof) override {
        car->setRoof("BMWRoof:" + roof);
    }
    virtual void BuildBody(string body) override {
        car->setBody("BMWBody:" + body);
    }
    virtual void BuildWheel(string wheel) override {
        car->setWheel("BMWWheel:" + wheel);
    }
    virtual Car* getCar() override {
        return car;
    }
    ~BMWBuilder() {
        if(car)
            delete car;
    }   
private:
    Car* car = new BMW();
};              

//法拉利建造者
class FerrariBuilder : public CarBuilder
{
public:
    virtual void BuildRoof(string roof) override {
        car->setRoof("FerrariRoof:" + roof);
    }
    virtual void BuildBody(string body) override {
        car->setBody("FerrariBody:" + body);
    }
    virtual void BuildWheel(string wheel) override {
        car->setWheel("FerrariWheel:" + wheel);
    }
    virtual Car* getCar() override {
        return car;
    }
    ~FerrariBuilder() {
        if(car)
            delete car;
    }   
private:
    Car* car = new Ferrari();
};      

//指挥者
class Director {
public:
    void setBuilder(CarBuilder* builder) {
        this->builder = builder;
    }
    Car* Construct() {
        builder->BuildRoof("奔驰的星空顶");
        builder->BuildBody("奔驰制造的F1赛车的地盘");
        builder->BuildWheel("奔驰的超宽抓地轮胎");
        return builder->getCar();
    }
    ~Director() {
        if(builder)
            delete builder;
    }
private:
    CarBuilder* builder;
};  

int main(){

    //建造一辆奔驰
    Director* director = new Director();
    director->setBuilder(new BenzBuilder());
    Car* car = director->Construct();
    car->detialShow();
    delete car;
    delete director;
}


