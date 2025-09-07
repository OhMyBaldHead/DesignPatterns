//策略模式就是给一个算法类接口，将实际算法实现从该接口中分离出来，使得算法可以独立于使用它的客户而变化。

//例如我使用抽象类实现一个排序法，而子类可以实现不同的排序算法，如冒泡排序，快速排序等。

#include <iostream>
#include <string>
using namespace std;    

class SortAlorithm {
public:
    virtual void sort() = 0;
};

class BubbleSort : public SortAlorithm {
public:
    virtual void sort() override {
        cout << "bubble sort" << endl;
    }
};  

class QuickSort : public SortAlorithm {
public:
    virtual void sort() override {
        cout << "quick sort" << endl;
    }
};          

int main() {
    SortAlorithm* sortAlorithm = new BubbleSort();
    sortAlorithm->sort();
    delete sortAlorithm;
    return 0;
}           