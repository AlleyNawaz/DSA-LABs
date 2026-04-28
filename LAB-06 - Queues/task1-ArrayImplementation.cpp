#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue Full\n";
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Deleted: " << q[front++] << endl;
}

void peek()
{
    if (front == -1 || front > rear)
        cout << "Queue Empty\n";
    else
        cout << "Front: " << q[front] << endl;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Empty\n";
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
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
    peek();
}