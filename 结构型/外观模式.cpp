//外观模式，就是把一堆子类做个封装，然后对外提供统一的接口，这样子类就不用对外暴露了
//就是子模块封装

//以智能家居为例子

#include <iostream>
#include <vector>
#include <string>
using namespace std;    


class AIfurniture{
public:
    virtual void open() = 0;
    virtual void close() = 0;
};

//智能电视
class AITV : public AIfurniture{
public:
    virtual void open() override{
        cout << "打开电视" << endl;
    }
    virtual void close() override{
        cout << "关闭电视" << endl;
    }

    void loveTVshow(){
        cout << "AI根据大数据智能切换到喜欢的电视节目" << endl;
    }
    void changeTVshow(int a){
        cout << "手动切换到第" << a << "个电视节目" << endl;
    }
};

//智能空调
class AICooler : public AIfurniture{
public:
    virtual void open() override{
        cout << "打开空调" << endl;
    }
    virtual void close() override{
        cout << "关闭空调" << endl;
    }
    void loveTemperature(){
        cout << "AI根据大数据智能调节到喜欢的温度" << endl;
    }
    void changeTemperature(int a){
        cout << "手动调节到第" << a << "个温度" << endl;
    }
};   

//智能灯
class AILight : public AIfurniture{
public:
    virtual void open() override{
        cout << "打开灯" << endl;
    }
    virtual void close() override{
        cout << "关闭灯" << endl;
    }
    void loveLight(){
        cout << "AI根据大数据智能调节到喜欢的亮度" << endl;
    }
    void changeLight(int a){
        cout << "手动调节到第" << a << "个亮度" << endl;
    }
};

//智能浴室
class AIShower : public AIfurniture{
public:
    virtual void open() override{
        cout << "打开浴室" << endl;
    }
    virtual void close() override{
        cout << "关闭浴室" << endl;
    }
    void loveShower(){
        cout << "AI根据大数据智能调节到喜欢的温度" << endl;
    }
    void changeShower(int a){
        cout << "手动调节到温度" << a << "°C" << endl;
    }
};  

class AIwaiter{
public:
    AITV* tv;
    AICooler* cooler;
    AILight* light;
    AIShower* shower;    
public:
    AIwaiter(){
        this->tv = new AITV();
        this->cooler = new AICooler();
        this->light = new AILight();
        this->shower = new AIShower();
    }   
    //准备到家时
    void readyGetHome(){
        tv->open();
        tv->loveTVshow();
        cooler->open();
        cooler->loveTemperature();
        light->open();
        light->loveLight();
        shower->open();
        shower->loveShower();
    }
    //离开家时
    void leaveHome(){
        tv->close();
        cooler->close();
        light->close();
        shower->close();
    }   
    //睡觉时
    void sleep(){
        tv->close();
        shower->close();
    }       
    ~AIwaiter(){
        delete tv;
        delete cooler;
        delete light;
        delete shower;
    }
};

int main(){
    AIwaiter* waiter = new AIwaiter();
    waiter->readyGetHome();
    waiter->leaveHome();
    waiter->sleep();
    delete waiter;
    return 0;
}           