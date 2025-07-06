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
void insertAtTail(Node* &head,Node* &tail,int val){
    Node *newnode= new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}
void printLinkedList(Node* head)
{
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<endl;
        temp=temp->next;
    }
}
int maxi(Node* head)
{
    Node* temp=head;
    int maxi=INT_MIN;
    
    while(temp!=NULL){
        maxi=max(maxi,temp->val);
        //cout<<temp->val<<endl;
        temp=temp->next;
    }
    return maxi;
}

int mini(Node* head)
{
    Node* temp=head;
    int mini=INT_MAX;
    while(temp!=NULL){
        mini=min(mini,temp->val);
        //cout<<temp->val<<endl;
        temp=temp->next;
    }
    return mini;
}


int main()
{
    
Node* head=NULL;
Node* tail=NULL;
int val;
while(1){
   cin>>val;
   if(val==-1)break;
   insertAtTail(head,tail,val);
}
//printLinkedList(head);
cout<<maxi(head) - mini(head);
    return 0;
}