//责任链模式就是在处理者中存储下一个处理者，然后形成一个处理者链条，并在每个处理者中设置一个职责范围。
//接收到任务后，查看是否在自己的职责范围内，如果在，则处理，不在则不处理。
//然后将任务移交给下一个处理者。

//以一道工序需要 work1 work2 work3 三个工人完成为例

#include <iostream>
#include <string>
using namespace std;

class Package{
public:
    int size;
};

class Worker {
public:
    virtual void doWork(Package* pg) = 0;
};

class Worker1 : public Worker {
public:
    Worker* nextWorker;
    Worker1(Worker* nextWorker) : nextWorker(nextWorker) {}
    virtual void doWork(Package* pg) override {
        if(pg->size < 10)
        cout << "work1 work" << endl;
        if(nextWorker != nullptr){
            nextWorker->doWork(pg);
        }
    }
};

class Worker2 : public Worker {
public:
    Worker* nextWorker;
    Worker2(Worker* nextWorker) : nextWorker(nextWorker) {}
    virtual void doWork(Package* pg) override {
        if(pg->size >= 10 && pg->size < 20)
        cout << "work2 work" << endl;
        if(nextWorker != nullptr){
            nextWorker->doWork(pg);
        }
    }
};

class Worker3 : public Worker {
public:
    Worker* nextWorker;
    Worker3(Worker* nextWorker) : nextWorker(nextWorker) {}
    virtual void doWork(Package* pg) override {
        if(pg->size >= 20)
        cout << "work3 work" << endl;
        if(nextWorker != nullptr){
            nextWorker->doWork(pg);
        }
    }
};

int main() {
    Package* pg = new Package();
    pg->size = 15;
    Worker* worker3 = new Worker3(nullptr);
    Worker* worker2 = new Worker2(worker3);
    Worker* worker1 = new Worker1(worker2);

    worker1->doWork(pg);
    delete worker1;
    delete worker2;
    delete worker3;
    delete pg;
    return 0;
}