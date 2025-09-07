//模板模式是对于算法的，抽象类中定义算法的骨架，但是具体的细节设置成虚函数，留到子类中去实现

//以维修电器为例子

#include <iostream>
#include <string>
using namespace std;

class RepairElectronics {
public:
    virtual void repair(){
        getPackage();
        open();
        doRepair();
        close();
        sendPackage();
    }
    void getPackage(){
        cout << "获取电器" << endl;
    }
    void open(){
        cout << "打开电器" << endl;
    }
    void close(){
        cout << "关闭电器" << endl;
    }
    void sendPackage(){
        cout << "寄回电器" << endl;
    }
    virtual void doRepair() = 0;
};

class RepairTV : public RepairElectronics {
public:
    void doRepair(){
        cout << "维修电视" << endl;
    }
};     

class RepairAirConditioner : public RepairElectronics {
public:
    void doRepair(){
        cout << "维修空调" << endl;
    }
};   

int main() {
    RepairElectronics* repairElectronics = new RepairTV();
    repairElectronics->repair();
    delete repairElectronics;
    return 0;
}       