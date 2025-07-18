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

int findX(Node* head,int x){
 Node* temp=head;
 int count=0;
    while(temp!=NULL){
     //   cout<<temp->val<<endl;
        if(temp->val==x){
           return count;
        }
        temp=temp->next;count++;
    }
    return -1;
}


int main()
{
    


int t;
cin>>t;
while(t--){
Node* head=NULL;
Node* tail=NULL;
int val;int x;
while(1){
   
   cin>>val;
   if(val==-1)break;
   insertAtTail(head,tail,val);
}

cin>>x;
cout<<findX(head,x)<<endl;

}


    return 0;
}