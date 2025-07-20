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
     cout<<"L -> ";
     Node* temp=head;
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }
 
 void printBackward( Node* tail){
     cout<<"R -> ";
     Node* temp=tail;
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->prev;
     }
     cout<<endl;
 }

int Size(Node* head){
    int cout=0;
    Node* temp=head;
    while(temp!=NULL){
        cout++;
        temp=temp->next;
    }
    return cout;
}

 void insertAtAnyPos(Node* &head,Node* &tail,int ind, int val){
    if(ind<0 || ind> Size(head)){
        cout<<"Invalid"<<endl;
        return;
    }
     Node* newnode=new Node(val);
     
     if(ind==0){
         if(head==NULL){
             head=newnode;
             tail=newnode;
         }
         else{
             newnode->next=head;
             head->prev=newnode;
             head=newnode;
         }
     }else if(ind==Size(head)){
         tail->next=newnode;
         newnode->prev=tail;
         tail=newnode;
     }else{
         Node* temp=head;
     for(int i=1;i<ind;i++){
         temp=temp->next;
     }
      newnode->next=temp->next;
      temp->next->prev=newnode;
      temp->next=newnode;
      newnode->prev=temp;  
         
     }
     printForward(head);
     printBackward(tail);
     
     
    
 }


int main()
{
    // Write your code here
 Node* head=NULL;
  Node* tail=NULL;
    int q;
    cin>>q;
    while(q--){
        int x,val;
        cin>>x>>val;
        insertAtAnyPos(head,tail,x,val);
    }
    
    return 0;
}
