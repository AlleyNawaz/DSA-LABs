#include <iostream>
using namespace std;

void foo()
{
    int* array = new int[100];

    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    delete[] array;
}

int main()
{
    foo();
    cout << "Function executed without memory leak." << endl;
    return 0;
}