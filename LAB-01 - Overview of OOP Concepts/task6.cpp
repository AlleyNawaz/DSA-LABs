#include <iostream>
using namespace std;

class Complex {
public:
    int r, i;

    void read() { 
        cin >> r >> i; 
    }

    Complex operator+(Complex c) {
        Complex temp;
        temp.r = r + c.r;
        temp.i = i + c.i;
        return temp;
    }

    void display() {
        cout << r << "+" << i << "i";
    }
};

int main() {
    Complex c1, c2, c3;
    c1.read();
    c2.read();
    c3 = c1 + c2;
    c3.display();
    return 0;
}