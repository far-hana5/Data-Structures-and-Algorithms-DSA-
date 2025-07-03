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
 void insertAtTail(Node* &head, Node* &tail ,int val){
     Node* newnode=new Node(val);
     if(head==NULL){
         head=newnode;
         return;
     }
      

tail->next=newnode;
tail=tail->next;
     
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
    Node* tail=new Node(30);
    
    head->next=a;
    a->next=tail;
    insertAtTail(head,tail,900);
    printLinkedList(head);
}