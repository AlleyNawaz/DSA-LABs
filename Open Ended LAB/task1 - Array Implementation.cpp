#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

struct Order
{
    int orderID;
    string customerName;
    string food;
    bool drink;
    string status;
};

class RestaurantQueue
{
private:
    Order queue[SIZE];
    int front;
    int rear;

public:
    RestaurantQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (rear == SIZE - 1);
    }

    void enqueue(Order o)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty())
            front = 0;

        rear++;
        queue[rear] = o;
        cout << "Order added for " << o.customerName << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No orders to process\n";
            return;
        }

        cout << "Processing Order ID: " << queue[front].orderID << endl;
        queue[front].status = "Completed";

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "No pending orders\n";
            return;
        }

        cout << "\nCurrent Orders:\n";

        for (int i = front; i <= rear; i++)
        {
            cout << "Order ID: " << queue[i].orderID << endl;
            cout << "Customer: " << queue[i].customerName << endl;
            cout << "Food: " << queue[i].food << endl;
            cout << "Drink: " << (queue[i].drink ? "Yes" : "No") << endl;
            cout << "Status: " << queue[i].status << endl;
        }
    }
};

int main()
{
    RestaurantQueue rq;

    Order o1 = {1, "Ali", "Burger", true, "Pending"};
    Order o2 = {2, "M Hamza", "Pizza", false, "Pending"};
    Order o3 = {3, "M Muaaz", "Pasta", true, "Pending"};

    rq.enqueue(o1);
    rq.enqueue(o2);
    rq.enqueue(o3);

    rq.displayQueue();

    cout << "\nProcessing orders...\n";

    rq.dequeue();
    rq.dequeue();

    rq.displayQueue();

    return 0;
}