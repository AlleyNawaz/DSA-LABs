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

void insert(int x){
 Node* n=new Node(x);
 if(!head){ head=n; return; }

 Node* t=head;
 while(t->next) t=t->next;
 t->next=n;
 n->prev=t;
}

void insertAfter(int k,int v){
 Node* t=head;

 while(t && t->data!=k) t=t->next;

 if(t==NULL){
  cout<<"Key not found\n";
  return;
 }

 Node* n=new Node(v);

 n->next=t->next;

 if(t->next)
  t->next->prev=n;

 t->next=n;
 n->prev=t;
}

void insertBefore(int k,int v){

 if(head==NULL) return;

 // if inserting before first node
 if(head->data==k){
  Node* n=new Node(v);
  n->next=head;
  head->prev=n;
  head=n;
  return;
 }

 Node* t=head;
 while(t && t->data!=k) t=t->next;

 if(t==NULL){
  cout<<"Key not found\n";
  return;
 }

 Node* n=new Node(v);

 n->prev=t->prev;
 n->next=t;
 t->prev->next=n;
 t->prev=n;
}

void display(){
 Node* t=head;
 while(t){
  cout<<t->data<<" ";
  t=t->next;
 }
}

int main(){

 insert(10);
 insert(20);
 insert(30);

 insertAfter(20,99);
 insertBefore(10,77);

 display();
}