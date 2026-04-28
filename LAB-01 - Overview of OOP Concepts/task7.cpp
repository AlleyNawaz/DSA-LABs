#include <iostream>
using namespace std;

template <class T>
T Large(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << Large(5, 10) << endl;
    cout << Large(12.4, 10.2) << endl;
    cout << Large('z', 'Z') << endl;
    return 0;
}