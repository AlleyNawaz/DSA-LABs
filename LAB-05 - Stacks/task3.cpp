#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> actions;
    int choice;
    string action;

    do
    {
        cout << "\n1.Perform Action\n2.Undo\n3.Exit\n";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter action: ";
            getline(cin, action);
            actions.push(action);
            cout << "Action added\n";
        }

        else if (choice == 2)
        {
            if (actions.empty())
            {
                cout << "Nothing to undo\n";
            }
            else
            {
                cout << "Undo: " << actions.top() << endl;
                actions.pop();

                if (!actions.empty())
                    cout << "Current action: " << actions.top() << endl;
                else
                    cout << "No actions left\n";
            }
        }

    } while (choice != 3);

    return 0;
}