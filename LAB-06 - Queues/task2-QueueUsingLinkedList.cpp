#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueue(int x)
{
    Node *n = new Node();
    n->data = x;
    n->next = NULL;

    if (rear == NULL)
        front = rear = n;
    else
    {
        rear->next = n;
        rear = n;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue Empty\n";
        return;
    }

    Node *temp = front;
    cout << "Deleted: " << temp->data << endl;
    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;
}

void display()
{
    Node *t = front;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}