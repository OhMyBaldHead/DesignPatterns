//备忘录模式就是整一个备忘录来记录类的状态
//循环引用依然要注意分文件编写

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Memento;

class Package {
public:
    string picturePath;
    string text;
    int x;
    int y;
    //保存
    void save(Memento* mem) {
        mem->getSaveInfo(this);
    }
    void recover(Memento* mem){
        this->text = mem->saveInfo.text;
        this->x = mem->saveInfo.x;
        this->y = mem->saveInfo.y;
    }
};

class SaveInfo{
public:
    string text;
    int x;
    int y;
    SaveInfo(Package* p){
        this->text = p->text;
        this->x = p->x;
        this->y = p->y;
    }
};  

class Memento
{
public:
    SaveInfo saveInfo;
    void getSaveInfo(Package* p){
        saveInfo = SaveInfo(p);
    }
};

class Operator
{
public:
    stack<Memento*> memStack;
    void addMemento(Memento* mem){
        memStack.push(mem);
    }

    Memento* getMemento(){
        Memento* mem = memStack.top();
        memStack.pop();
        return mem;
    }

    ~Operator(){
        while(!memStack.empty()){
            Memento* mem = memStack.top();
            delete mem;
            memStack.pop();
        }
    }
};

int main()
{
    Package p;
    p.picturePath = "C:\\Users\\Administrator\\Desktop\\1.jpg";
    p.text = "hello world";
    p.x = 100;
    p.y = 100;
    Operator op;
    Memento* mem = new Memento();
    p.save(mem);
    op.addMemento(mem);
    p.text = "hello world 2";
    p.x = 200;
    p.y = 200;
    mem = new Memento();
    p.save(mem);
    op.addMemento(mem);
    p.text = "hello world 3";
    p.x = 300;
    p.y = 300;
    cout << p.text << endl;
    cout << p.x << endl;
    cout << p.y << endl;
    p.recover(op.getMemento());
    delete mem;
    return 0;
}   




