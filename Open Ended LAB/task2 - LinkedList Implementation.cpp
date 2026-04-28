#include <iostream>
using namespace std;

struct Node
{
    int jobID;
    Node *next;
};

class PrinterQueue
{
private:
    Node *front;
    Node *rear;

public:
    PrinterQueue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int id)
    {
        Node *newNode = new Node;
        newNode->jobID = id;
        newNode->next = NULL;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Print Job " << id << " added\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No print jobs\n";
            return;
        }

        Node *temp = front;
        cout << "Printing Job ID: " << temp->jobID << endl;

        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Printer queue empty\n";
            return;
        }

        Node *temp = front;

        cout << "\nCurrent Print Jobs:\n";

        while (temp != NULL)
        {
            cout << "Job ID: " << temp->jobID << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    PrinterQueue pq;

    pq.enqueue(101);
    pq.enqueue(102);
    pq.enqueue(103);

    pq.display();

    cout << "\nProcessing jobs...\n";

    pq.dequeue();
    pq.dequeue();

    pq.display();

    return 0;
}