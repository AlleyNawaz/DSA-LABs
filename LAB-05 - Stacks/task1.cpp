#include <iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;
    int size;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
    }

    void push(int item)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = item;
        cout << "Pushed: " << item << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s(5);
    int choice, value;

    do
    {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        }
    } while (choice != 4);

    return 0;
}