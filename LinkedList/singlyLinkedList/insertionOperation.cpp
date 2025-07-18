/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
 void insertAtHead(Node* &head ,int val){
     Node* newnode=new Node(val);
     newnode->next=head;
     head=newnode;
 }
  void insertAtTail(Node* &head ,int val){
     Node* newnode=new Node(val);
     if(head==NULL){
         head=newnode;
         return;
     }
       Node* tmp=head ;
while(tmp->next!=NULL){
    
   tmp = tmp->next;
}
//right now tmp is at last node;
tmp->next=newnode;
     
 }
 
 void insertAtAnyPos(Node* &head ,int ind,int val){
     Node* newnode=new Node(val);
    
       Node* tmp=head ;
    for(int i=0;i<ind-1;i++){
         tmp = tmp->next;
    }
//right now tmp is at ind-1  node;
   newnode->next=tmp->next;
   tmp->next=newnode;
     
 }
 
 void printLinkedList(Node* head){
     Node* tmp=head ;//pointer tmp
while(tmp!=NULL){
    cout<<tmp->val<<" ";
   tmp = tmp->next;
}
 }
 
int main()
{
    Node* head=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    
    head->next=a;
    a->next=b;
    insertAtHead(head,100);
    insertAtTail(head,40);
     insertAtTail(head,40);
      insertAtTail(head,40);
      insertAtAnyPos(head,2,500);
      
    printLinkedList(head);
}
