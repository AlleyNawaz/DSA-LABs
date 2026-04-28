#include <iostream>
using namespace std;

struct Node{
 int data; Node* next; Node* prev;
 Node(int x){data=x; next=prev=NULL;}
};

Node* head=NULL;

void insert(int x){
 Node* n=new Node(x);
 if(!head){
  head=n;
  head->next=head;
  head->prev=head;
  return;
 }
 Node* last=head->prev;
 last->next=n;
 n->prev=last;
 n->next=head;
 head->prev=n;
}

void display(){
 Node* t=head;
 for(int i=0;i<6;i++){
  cout<<t->data<<" ";
  t=t->next;
 }
}

int main(){
 insert(10); insert(20); insert(30);
 display();
}