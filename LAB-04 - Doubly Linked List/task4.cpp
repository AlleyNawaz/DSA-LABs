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

bool search(int x){
 Node* t=head;
 while(t){
  if(t->data==x) return true;
  t=t->next;
 }
 return false;
}

int main(){
 insert(10); insert(20); insert(30);
 cout<<search(20);
}