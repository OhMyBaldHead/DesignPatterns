//享元模式遇到的问题是，我需要很多个类，而这些类仅仅在某些细微属性上有区别。
//享元模式就是通过外部输入参数的形式，可以临时定义修改某些细微属性。
//然后创建一张享元模式的查找表，来快速地查找到享元

//以字母为例子举例享元模式。字母不变的是字母，变的是大小，位置
#include <cctype> //字符处理
#include <map> //map
#include <string> //string
#include <iostream>
using namespace std;    

class SharedElement
{
private:
    char ch;
    int x;
    bool Upper;
public:
    static string str;
public:
    SharedElement(char ch, int x, bool Upper){
        this->ch = ch;
        this->x = x;
        this->Upper = Upper;
        if(Upper){
            ch = toupper(ch);            //大写转小写
        }
        else{
            ch = tolower(ch);            //小写转大写
        }   
    }
    
    char getCh(){
        return ch;
    }
    
    int getX(){
        return x;
    }
    
    bool getUpper(){
        return Upper;
    }

    void Change(int x,bool Upper){
        this->x = x;
        this->Upper = Upper;
        if(Upper){
            ch = toupper(ch);            //大写转小写
        }
        else{
            ch = tolower(ch);            //小写转大写
        }   
    }
};
string SharedElement::str = string(100,'0');

class SharedElementFactory
{
private:
    map<char, SharedElement*> sharedElements;
public:
    SharedElementFactory(){}
    SharedElement* getSharedElement(char ch){ 
        ch = tolower(ch);                                            //转小写
        if(sharedElements.find(ch) == sharedElements.end()){            //如果map中不存在该元素 
            sharedElements[ch] = new SharedElement(ch,0,false);        //创建一个元素
        }
        return sharedElements[ch];                                    //返回该元素
    }
    ~SharedElementFactory(){
        for(auto it = sharedElements.begin(); it != sharedElements.end(); it++){
            delete it->second;
        }
    }
};

int main(){
    SharedElementFactory* factory = new SharedElementFactory();
    SharedElement* sharedElementa = factory->getSharedElement('a');
    SharedElement* sharedElementb = factory->getSharedElement('b');
    SharedElement* sharedElementc = factory->getSharedElement('c');
    SharedElement* sharedElementd = factory->getSharedElement('d');
    SharedElement* sharedElemente = factory->getSharedElement('e');
    SharedElement* sharedElementf = factory->getSharedElement('f');
    SharedElement* sharedElementg = factory->getSharedElement('g');

    sharedElementa->Change(3,true);
    SharedElement::str[3] = sharedElementa->getCh();
    sharedElementb->Change(10,false);
    SharedElement::str[10] = sharedElementb->getCh();
    sharedElementc->Change(7,true);
    SharedElement::str[7] = sharedElementc->getCh();
    sharedElementd->Change(15,false);
    SharedElement::str[15] = sharedElementd->getCh();
    sharedElemente->Change(16,true);
    SharedElement::str[16] = sharedElemente->getCh();
    sharedElementf->Change(18,false);
    SharedElement::str[18] = sharedElementf->getCh();
    sharedElementg->Change(20,true);
    SharedElement::str[20] = sharedElementg->getCh();

    cout<<SharedElement::str<<endl;


}


