//适配器模式，就是将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类能一起工作。
//就是功能的转换

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

//实现一个简单的RGB转YUV的适配器接口

//定义点坐标
class Point {
public:
    double x;
    double y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
//定义矩形
class Rectangle {
private:
    Point p1, p2, p3, p4; // 四个顶点
public:
    // 构造函数：通过四个点初始化
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
        : p1(p1), p2(p2), p3(p3), p4(p4) {
        // 可以添加验证是否为矩形的逻辑
    }
    // 获取四个顶点
    std::vector<Point> getVertices() const {
        return {p1, p2, p3, p4};
    }
};

//定义RGB颜色
class RGB {
public:
    int r;
    int g;
    int b;
    
    RGB(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
};

//定义YUV颜色
class YUV {
public:
    int y;
    int u;
    int v;
    
    YUV(int y = 0, int u = 0, int v = 0) : y(y), u(u), v(v) {}
};

class Object {
public:
    Object(const Rectangle& rect, const RGB& rgb) : rect(rect), rgb(rgb) {}
public:
    Rectangle rect;
    RGB rgb;
};

class ObjectAdapter {
public:
    ObjectAdapter(const Object& obj) : obj(obj) {}
    YUV getYUV() const {
        // RGB to YUV conversion formula
        int r = obj.rgb.r;
        int g = obj.rgb.g;
        int b = obj.rgb.b;
        
        int y = static_cast<int>(0.299 * r + 0.587 * g + 0.114 * b);
        int u = static_cast<int>(-0.14713 * r - 0.28886 * g + 0.436 * b + 128);
        int v = static_cast<int>(0.615 * r - 0.51498 * g - 0.10001 * b + 128);
        
        return YUV(y, u, v);
    }
    Rectangle getRect() const {
        return obj.rect;
    }   
private:
    Object obj;
};

int main() {
    // 创建矩形
    Point p1(0, 0), p2(10, 0), p3(10, 5), p4(0, 5);
    Rectangle rect(p1, p2, p3, p4);
    
    // 创建RGB颜色 (红色)
    RGB rgb(255, 0, 0);
    
    // 创建对象
    Object obj(rect, rgb);
    
    // 使用适配器转换
    ObjectAdapter adapter(obj);
    YUV yuv = adapter.getYUV();
    
    // 打印结果
    cout << "RGB(255, 0, 0) -> YUV(" 
         << yuv.y << ", " 
         << yuv.u << ", " 
         << yuv.v << ")" << endl;
    
    return 0;
}