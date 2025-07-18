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
void insertAtHead(Node* &head ,Node* &tail,int val){
     Node* newnode=new Node(val);
     newnode->next=head;
     head=newnode;
    if(tail==NULL)tail=newnode;
 }
 void deleteAtAnyPos(Node* &head,Node* &tail,int ind){
    if(head==NULL)return;
    if(ind==0){
        Node* deletenode=head;
        head=head->next;
        if(head==NULL)tail=NULL;
        delete deletenode;
        return;
    }
     Node* temp=head;
     for(int i=1;i<ind;i++){
          if(temp==NULL || temp->next==NULL)return;
        temp=temp->next;
       
     }
     Node* deletenode=temp->next;
     if(deletenode==NULL)return;
     if(deletenode->next ==NULL)tail=temp;
     temp->next=deletenode->next;
     delete deletenode;
 }
void printLinkedList(Node* head)
{
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    





Node* head=NULL;
Node* tail=NULL;
/*int val;
while(1){
   
   cin>>val;
   if(val==-1)break;
   
   insertAtTail(head,tail,val);
}*/

int q;
cin>>q;
while(q--){
    int x,val;
    cin>>x>>val;

    if(x==0){
        
        insertAtHead(head,tail,val);
         
    }else if(x==1){
      
        insertAtTail(head,tail,val);
         
    }else{
       
        deleteAtAnyPos(head,tail,val);
         
    }
    printLinkedList(head);
}

    return 0;
}