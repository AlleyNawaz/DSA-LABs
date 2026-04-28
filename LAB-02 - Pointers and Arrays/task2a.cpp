#include <iostream>
using namespace std;

int main()
{
    int a(1);
    int b(2);
    int *p1, *p2;

    p1 = &a;
    p2 = &b;

    *p1 = *p2;
    *p2 = 10;

    cout << *p1 << " " << b << " " << a << endl;
    return 0;
}