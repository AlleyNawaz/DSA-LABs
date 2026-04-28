#include <iostream>
using namespace std;

struct Node{
 int data; Node* next; Node* prev;
 Node(int x){data=x; next=prev=NULL;}
};

Node* head=NULL;

void insert(int x){
 Node* n=new Node(x);
 if(!head){head=n;return;}
 Node* t=head;
 while(t->next)t=t->next;
 t->next=n; n->prev=t;
}

void reverse(){
 Node* c=head;
 Node* t=NULL;
 while(c){
  t=c->prev;
  c->prev=c->next;
  c->next=t;
  c=c->prev;
 }
 if(t) head=t->prev;
}

void display(){
 Node* t=head;
 while(t){cout<<t->data<<" "; t=t->next;}
}

int main(){
 insert(10); insert(20); insert(30);
 reverse();
 display();
}