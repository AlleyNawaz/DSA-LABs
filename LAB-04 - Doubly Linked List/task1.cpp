#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int v){
        data=v;
        next=prev=NULL;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){ head=NULL; }
};

int main(){
    DoublyLinkedList d;
    cout<<"DLL Initialized";
}