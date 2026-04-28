#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;

    try {
        if (b == 0)
            throw "division by zero not possible";
        cout << a / b;
    }
    catch (const char* msg) {
        cout << msg;
    }

    return 0;
}