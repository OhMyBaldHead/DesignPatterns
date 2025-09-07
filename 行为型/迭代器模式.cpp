//迭代器模式，迭代器不用关心迭代的对象的具体结构。使用模板去迭代就可以了
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

template<typename T>
class Iterator;

template<typename T>
class Mylist {
public:
    vector<T> data;
    Mylist() : data(data) {}
    void add(T data) {
        this->data.push_back(data);
    }
    void remove(T data) {
        this->data.erase(remove(this->data.begin(), this->data.end(), data), this->data.end());
    }
    Iterator<T>* getIterator() {
        return new ForwardIterator<T>(this);
    }
};  

template <typename T>
class Iterator {
public:
    int index;
    Mylist<T>* List;
    virtual bool hasnext() = 0;
    virtual void next() = 0;
    virtual T current() = 0;
};

template <typename T>
class ForwardIterator : public Iterator<T> {
public:
    ForwardIterator(Mylist<T>* list){
        this->List = list;
        this->index = 0;
    }
    virtual bool hasnext(){
        if(index < List->data.size()){
            return true;
        }
        return false;
    }
    virtual void next(){
        if(hasnext()){
            index++;
        }   
    }
    virtual T current(){
        return List->data[index];
    }
};  

//还可以定义反向迭代器等

int main() {
    Mylist<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    Iterator<int>* it = list.getIterator();
    while(it->hasnext()){
        cout << it->current() << endl;
        it->next();
    }
    return 0;
}