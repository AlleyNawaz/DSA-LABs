#include <iostream>
using namespace std;

class Rectangle {
    int l, b;

public:
    Rectangle() {
        l = 5; b = 6; 
    }
    Rectangle(int x, int y) {
        l = x; b = y; 
    }
    Rectangle(Rectangle &r) { 
        l = r.l; b = r.b; 
    }

    void area() {
        cout << "Area of rectangle is " << l * b << endl;
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(3, 6);
    Rectangle r3(r2);

    r1.area();
    r2.area();
    r3.area();

    return 0;
}