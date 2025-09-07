#include <iostream>
#include <string>   
using namespace std;


//1，构造函数私有化，避免被实例化。2，静态成员变量，静态成员函数，静态成员变量只能被初始化一次，且只能被类名调用。
class Singleton {
public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    int add(int a, int b) {
        return a + b;
    }   
    int sub(int a, int b) {
        return a - b;
    }   
    int mul(int a, int b) {
        return a * b;
    }   
    int div(int a, int b) {
        return a / b;
    }   

private:
    Singleton() {}  //构造函数是私有的
    static Singleton* instance;  //静态成员变量
};
Singleton* Singleton::instance = nullptr;

//懒汉式，饿汉式
//懒汉式是在第一次调用getInstance()方法时实例化对象，由于多线程可能并发调用getInstance()方法，所以线程不安全
//解决线程不安全的方式是给getInstance()方法加锁,但是加锁会影响性能
//为了解决加锁影响性能的问题，可以使用局部静态变量的方法，这种方法不仅写起来很简单，而且避免了锁带来的性能影响
//局部静态变量是在第一次调用getInstance()方法时实例化对象，由于局部静态变量在程序结束时才销毁，所以是线程安全的
//而饿汉式是在类加载时就实例化对象。因为程序刚加载是就完成了单例的创建，所以是线程安全的

//局部静态变量的单例
class SingletonNew {
public:
    static SingletonNew* getInstance() {
        static SingletonNew instance;  //局部静态变量
        return &instance;
    }

    int add(int a, int b) {
        return a + b;
    }   
    int sub(int a, int b) {
        return a - b;
    }   
    int mul(int a, int b) {
        return a * b;
    }   
    int div(int a, int b) {
        return a / b;
    }   

private:
    SingletonNew() {}  //构造函数是私有的
};

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s1->add(1, 2) << endl;
    cout << s1->sub(1, 2) << endl;
    cout << s1->mul(1, 2) << endl;
    cout << s1->div(1, 2) << endl;
    return 0;
}   