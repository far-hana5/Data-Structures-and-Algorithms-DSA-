/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
 class Node
 {
     public:
      int val;
      Node* next;
      Node* prev;
      
      Node(int val){
          this->val=val;
          this->next=NULL;
          this->prev=NULL;
      }
 };
 
 void printForward( Node* head){
     Node* temp=head;
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
 
 void printBackward( Node* tail){
     Node* temp=tail;
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->prev;
     }
     cout<<endl;
 }
 void insertAtHead(Node* &head,Node* &tail, int val){
    
     Node* newnode=new Node(val);
      if(head==NULL){
         head=newnode;
         tail=newnode;
         return;
     }
     newnode->next=head;
     head->prev=newnode;
     head=newnode;
 }

 void insertAtTail(Node* &head,Node* &tail, int val){
     
     
     Node* newnode=new Node(val);
     if(head==NULL){
         head=newnode;
         tail=newnode;
         return;
     }
     tail->next=newnode;
     newnode->prev=tail;
     tail=newnode;
     
 }
  void insertAtAnyPos(Node* &head,int ind, int val){
    
     Node* newnode=new Node(val);
     Node* temp=head;
     for(int i=1;i<ind;i++){
         temp=temp->next;
     }
     
     
     newnode->next=temp->next;
     temp->next->prev=newnode;
     temp->next=newnode;
     newnode->prev=temp;
    
 }

int main()
{
    Node* head=new Node(10);
    Node* a=new Node(20);
    Node* tail =new Node(30);
    head->next=a;a->prev=head;
    a->next=tail;tail->prev=a;
    printForward(head);
    printBackward(tail);
     insertAtHead(head,tail,100);
     insertAtTail(head,tail,200);
     printForward(head);
     printForward(head);
     
     insertAtAnyPos(head,2,500);
     printForward(head);
    return 0;
}