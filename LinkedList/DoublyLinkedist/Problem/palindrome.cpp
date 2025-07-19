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
 


void insertAtTail(Node* &head,Node* &tail, int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    
}

 void printForward(Node* head){
     Node* temp=head;
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->next;
     }
     cout<<endl;
 }

bool isPalindrome(Node* head,Node* tail){
    while(head!=NULL && tail!=NULL && head!=tail && tail->next!=head){
        if(head->val!=tail->val){
            return false;
        }
        head=head->next;
        tail=tail->prev;
    }
    return true;
}

int main()
{
    // Write your code here
    Node* head=NULL;
    Node* tail=NULL;
    
    int val;
    
    while(true){
        cin>>val;
        
        if(val==-1){
            break;
        }
        insertAtTail(head,tail,val);
    }
    
    if(isPalindrome(head,tail)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    //printForward(head);

    return 0;
}
