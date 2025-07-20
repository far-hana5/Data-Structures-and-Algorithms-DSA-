#include <bits/stdc++.h>

using namespace std;

class Node
 {
     public:
      string val;
      Node* next;
      Node* prev;
      
      Node(string val){
          this->val=val;
          this->next=NULL;
          this->prev=NULL;
      }
 };
 


void insertAtTail(Node* &head,Node* &tail, string val){
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


Node* findAddress(Node* head,string address){
  Node* temp=head;
    while(temp!=NULL){
        if(temp->val == address)return temp;
        temp=temp->next;
    }
    return NULL;
}
int main()
{
    // Write your code here
   Node* head=NULL;
    Node* tail=NULL;
    
    string add;
    
    while(cin>>add){
      if(add=="end"){
          break;
      }  
        insertAtTail(head,tail,add);
    }
    
    int q;
    cin>>q;
    cin.ignore();
    Node* temp=head;
    
    while(q--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        
        string perline,com;
        ss>>com;
        
        if(com=="visit"){
           ss>>perline;
            Node* node=findAddress(head,perline);
            
            if(node!=NULL){
                temp=node;
                cout<<temp->val<<endl;
            }else{
                cout<<"Not Available"<<endl;
            }
        }else if(com=="next"){
            if(temp->next!=NULL){
                temp=temp->next;
                cout<<temp->val<<endl;
            }else{
                 cout<<"Not Available"<<endl;             
            }
        }else if(com=="prev"){
            if(temp->prev!=NULL){
                temp=temp->prev;
                cout<<temp->val<<endl;
            }else{
                 cout<<"Not Available"<<endl;             
            }
        }
    }
    
    
    
    return 0;
}
