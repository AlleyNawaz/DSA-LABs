#include <iostream>
using namespace std;

class Count {
    int value;
public:
    Count() { value = 5; }

    void operator++() {
        ++value; 
    }
    void operator++(int) { 
        value++; 
    }

    void display() { cout << "Count: " << value << endl; }
};

int main() {
    Count c;
    ++c;
    c.display();
    c++;
    c.display();

    return 0;
}