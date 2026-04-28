#include <iostream>
using namespace std;

int main()
{
    double* d_var;
    double* d_array;

    d_var = new double;
    d_array = new double[10];

    cout << "Enter a double value: ";
    cin >> *d_var;
    cout << "Value entered: " << *d_var << endl;

    for (int i = 0; i < 10; i++) {
        d_array[i] = 1.0;
    }

    cout << "Array values: ";
    for (int i = 0; i < 10; i++) {
        cout << d_array[i] << " ";
    }
    cout << endl;

    delete d_var;
    delete[] d_array;

    return 0;
}