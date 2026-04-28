#include <iostream>
using namespace std;

class Time {
public:
    int h, m, s;

    void read() {
        cout << "Enter hours, minutes and seconds: ";
        cin >> h >> m >> s;
    }

    void add(Time t1, Time t2) {
        s = t1.s + t2.s;
        m = t1.m + t2.m + s / 60;
        h = t1.h + t2.h + m / 60;
        s %= 60;
        m %= 60;
    }

    void display() {
        cout << "HH:MM:SS " << h << ":" << m << ":" << s << endl;
    }
};

int main() {
    Time t1, t2, t3;

    t1.read();
    t2.read();

    t3.add(t1, t2);
    t3.display();

    return 0;
}