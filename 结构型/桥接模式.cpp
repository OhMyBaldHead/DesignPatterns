//桥接模式就是将不同的属性拼接在一起，避免属性的增长引起类的爆炸性增长
//假如我们希望创建红色的球，红色的盒子，红色的电视机，绿色的球，绿色的盒子，绿色的电视机，那么我们就可以使用桥接模式
//再不使用桥接模式的时候，我们就要创建多个类，RedBall，RedBox，RedTV，GreenBall，GreenBox，GreenTV，YellowBall，YellowBox，YellowTV
//这样随着属性的增加，类的数量也会增加，这样就会导致类的爆炸性增长，我们很难创造出过多的类
//这个时候我们可以使用桥接模式，将属性独立地内置到物体中，这样我们只需要改变物体的属性就可以

#include <iostream>
#include <string>
using namespace std;

class Color {
public:
    virtual string fill() = 0;
};

class Red : public Color {
public:
    virtual string fill() override {
        cout << "fill Red" << endl;
        return "Red";
    }
};

class Green : public Color {
public:
    virtual string fill() override {
        cout << "fill Green" << endl;
        return "Green";
    }
};  

class Yellow : public Color {
public:
    virtual string fill() override {
        cout << "fill Yellow" << endl;
        return "Yellow";
    }
};  

class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    virtual void draw() override {
        cout << "draw Rectangle" << endl;
    }
};  

class Circle : public Shape {
public:
    virtual void draw() override {
        cout << "draw Circle" << endl;
    }
};      

class Square : public Shape {
public:
    virtual void draw() override {
        cout << "draw Square" << endl;
    }
};  

class Object {
public:
    virtual void draw() = 0;
    virtual void action() = 0;
public:
    Color* color;
    Shape* shape;
};      

class Ball : public Object {
public:
    Ball(Color* color, Shape* shape){
        this->color = color;
        this->shape = shape;
    }
    virtual void draw() override {
        cout << "draw Ball" << endl;
        shape->draw();
        color->fill();
    }
    virtual void action() override {
        cout << "action Ball" << endl;
    }
};  

class Box : public Object {
public:
    Box(Color* color, Shape* shape){
        this->color = color;
        this->shape = shape;
    }
    virtual void draw() override {
        cout << "draw Box" << endl;
        shape->draw();
        color->fill();
    }
    virtual void action() override {
        cout << "action Box" << endl;
    }
};

int main() {
    Color* red = new Red();
    Shape* circle = new Circle();
    Object* ball = new Ball(red, circle);
    ball->draw();
    ball->action();
    delete ball;
    delete red;
    delete circle;
    return 0;
}