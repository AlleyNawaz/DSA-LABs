#include <iostream>
using namespace std;

const int MAX = 100;

void insert(int heap[], int &size, int value){
    int i = size;
    heap[i] = value;
    size++;

    // heapify up (bubble up)
    while(i > 0 && heap[(i-1)/2] < heap[i]){
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify(int heap[], int size, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] > heap[largest])
        largest = left;

    if(right < size && heap[right] > heap[largest])
        largest = right;

    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, size, largest);
    }
}

void deleteMax(int heap[], int &size){
    if(size <= 0){
        cout << "Heap is empty\n";
        return;
    }

    cout << "Dispatched (Highest Priority): " << heap[0] << endl;

    heap[0] = heap[size-1];
    size--;

    heapify(heap, size, 0);
}

void display(int heap[], int size){
    cout << "Current Queue: ";
    for(int i=0; i<size; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main(){
    int heap[MAX];
    int size = 0;

    int choice, value;

    do{
        cout << "\n1. Insert Emergency";
        cout << "\n2. Dispatch (Delete Max)";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter priority value: ";
            cin >> value;
            insert(heap, size, value);
            break;

        case 2:
            deleteMax(heap, size);
            break;

        case 3:
            display(heap, size);
            break;
        }

    }while(choice != 4);

    return 0;
}