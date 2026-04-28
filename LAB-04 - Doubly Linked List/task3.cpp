#include <iostream>
using namespace std;

struct Node{
 int data; Node* next; Node* prev;
 Node(int x){data=x; next=prev=NULL;}
};

Node* head=NULL;

void insertEnd(int x){
 Node* n=new Node(x);
 if(!head){head=n;return;}
 Node* t=head;
 while(t->next) t=t->next;
 t->next=n; n->prev=t;
}

void deleteFront(){
 Node* t=head;
 head=head->next;
 if(head) head->prev=NULL;
 delete t;
}

void deleteEnd(){
 Node* t=head;
 while(t->next) t=t->next;
 if(t->prev) t->prev->next=NULL;
 else head=NULL;
 delete t;
}

void display(){
 Node* t=head;
 while(t){ cout<<t->data<<" "; t=t->next;}
}

int main(){
 insertEnd(10); insertEnd(20); insertEnd(30);
 deleteFront();
 deleteEnd();
 display();
}