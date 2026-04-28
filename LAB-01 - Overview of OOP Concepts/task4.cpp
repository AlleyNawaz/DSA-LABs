#include <iostream>
using namespace std;

int calc(int a, int b) { 
    return a + b; 
}
int calc(int a, int b, int c) { 
    return a - b - c; 
}
double calc(double a, double b) { 
    return a * b; 
}

int main() {
    cout << calc(5, 3) << endl;
    cout << calc(10, 3, 2) << endl;
    cout << calc(2.5, 4.0) << endl;

    return 0;
}