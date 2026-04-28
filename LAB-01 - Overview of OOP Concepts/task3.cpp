#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
};

class Rectangle : public Shape {
    int l, b;
public:
    Rectangle(int x, int y) { l = x; b = y; }
    void area() { 
        cout << "Rectangle Area: " << l * b << endl; 
    }
};

class Square : public Shape {
    int s;
public:
    Square(int x) { s = x; }
    void area() { 
        cout << "Square Area: " << s * s << endl; 
    }
};

class Triangle : public Shape {
    int b, h;
public:
    Triangle(int x, int y) { b = x; h = y; }
    void area() { 
        cout << "Triangle Area: " << (b * h) / 2 << endl; 
    }
};

int main() {
    Rectangle r(4, 5);
    Square s(4);
    Triangle t(6, 8);

    r.area();
    s.area();
    t.area();

    return 0;
}