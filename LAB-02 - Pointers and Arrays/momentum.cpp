#include <iostream>
using namespace std;

double* momentum(const double velocity[3], double mass)
{
    double* result = new double[3];
    for (int i = 0; i < 3; i++) {
        result[i] = mass * velocity[i];
    }
    return result;
}

int main()
{
    double velocity[3];
    double mass;

    cout << "Enter velocity (x y z): ";
    cin >> velocity[0] >> velocity[1] >> velocity[2];

    cout << "Enter mass: ";
    cin >> mass;

    double* m = momentum(velocity, mass);

    cout << "Momentum vector: ";
    for (int i = 0; i < 3; i++) {
        cout << m[i] << " ";
    }
    cout << endl;

    delete[] m;
    return 0;
}