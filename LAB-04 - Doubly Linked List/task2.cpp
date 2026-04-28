#include <iostream>
using namespace std;

struct Node{
 int data;
 Node* next;
 Node* prev;

 Node(int x){
  data=x;
  next=prev=NULL;
 }
};

Node* head=NULL;

void insertFront(int x){
 Node* n=new Node(x);
 if(!head) head=n;
 else{
  n->next=head;
  head->prev=n;
  head=n;
 }
}

void insertEnd(int x){
 Node* n=new Node(x);
 if(!head){ head=n; return; }
 Node* t=head;
 while(t->next) t=t->next;
 t->next=n;
 n->prev=t;
}

void display(){
 Node* t=head;
 while(t){
  cout<<t->data<<" ";
  t=t->next;
 }
}

int main(){
 insertFront(10);
 insertFront(20);
 insertFront(30);

 insertEnd(40);
 insertEnd(50);
 insertEnd(60);

 display();
}