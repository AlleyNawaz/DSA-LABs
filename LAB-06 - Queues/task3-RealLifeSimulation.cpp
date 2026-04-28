#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    int ch;
    string name;

    do
    {
        cout << "\n1.Add Customer\n2.Serve Customer\n3.Display\n4.Exit\n";
        cin >> ch;
        cin.ignore();

        if (ch == 1)
        {
            getline(cin, name);
            q.push(name);
        }
        else if (ch == 2)
        {
            if (q.empty())
                cout << "No customers\n";
            else
            {
                cout << "Served: " << q.front() << endl;
                q.pop();
            }
        }
        else if (ch == 3)
        {
            queue<string> t = q;
            while (!t.empty())
            {
                cout << t.front() << endl;
                t.pop();
            }
        }

    } while (ch != 4);
}