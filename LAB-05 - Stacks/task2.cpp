#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

class Stack
{
    StackNode *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int item)
    {
        StackNode *newNode = new StackNode();
        newNode->data = item;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << item << endl;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!\n";
            return;
        }
        StackNode *temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }

        StackNode *temp = top;
        cout << "Stack elements:\n";
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s;
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