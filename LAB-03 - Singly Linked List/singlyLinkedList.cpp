#include <iostream>
using namespace std;

class Node {
public:
    int d1;
    double d2;
    Node* next;

    Node(int a, double b) {
        d1 = a;
        d2 = b;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Task 2: Add at end
    void addEnd(Node* n) {
        if(head == NULL){
            head = n;
            return;
        }

        Node* t = head;
        while(t->next != NULL)
            t = t->next;

        t->next = n;
    }

    // Task 3: Delete last
    Node* deleteLast() {
        if(head == NULL) return NULL;

        if(head->next == NULL){
            Node* x = head;
            head = NULL;
            return x;
        }

        Node* t = head;
        while(t->next->next != NULL)
            t = t->next;

        Node* del = t->next;
        t->next = NULL;
        return del;
    }

    // Task 4: Size
    int size() {
        int c = 0;
        Node* t = head;
        while(t != NULL){
            c++;
            t = t->next;
        }
        return c;
    }

    // Task 5: Search
    bool search(int a,double b){
        Node* t = head;
        while(t != NULL){
            if(t->d1 == a && t->d2 == b)
                return true;
            t = t->next;
        }
        return false;
    }

    // Task 6: Add after node
    void addAfter(int a,double b,Node* n){
        Node* x = new Node(a,b);
        x->next = n->next;
        n->next = x;
    }

    // Task 7: Delete after node
    Node* deleteAfter(Node* n){
        if(n==NULL || n->next==NULL) return NULL;

        Node* x = n->next;
        n->next = x->next;
        return x;
    }

    void show(){
        Node* t = head;
        while(t!=NULL){
            cout<<"("<<t->d1<<","<<t->d2<<")->";
            t=t->next;
        }
        cout<<"NULL\n";
    }
};

int main(){

    LinkedList list;

    // Task 1: Create three nodes
    Node* node1 = new Node(1,1.1);
    Node* node2 = new Node(2,2.2);
    Node* node3 = new Node(3,3.3);

    list.addEnd(node1);
    list.addEnd(node2);
    list.addEnd(node3);

    list.show();

    cout<<"Size: "<<list.size()<<endl;

    cout<<"Search 2,2.2: "<<list.search(2,2.2)<<endl;

    list.addAfter(9,9.9,node1);
    list.show();

    list.deleteAfter(node1);
    list.show();

    list.deleteLast();
    list.show();
}