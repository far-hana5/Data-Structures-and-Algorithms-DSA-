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

bool isSame(Node* head1,Node* head2){
 Node* temp1=head1;
 Node* temp2=head2;
 int count=0;
    while(temp1!=NULL && temp2!=NULL){
     //   cout<<temp->val<<endl;
        if(temp1->val!=temp2->val){
           return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}


int main()
{
    





Node* head1=NULL;
Node* tail1=NULL;
int val1,c1=0;
while(1){
   
   cin>>val1;
   if(val1==-1)break;
   c1++;
   insertAtTail(head1,tail1,val1);
}

Node* head2=NULL;
Node* tail2=NULL;
int val2,c2=0;
while(1){
   
   cin>>val2;
   if(val2==-1)break;
   c2++;
   insertAtTail(head2,tail2,val2);
}
if(c1!=c2){cout<<"NO"<<endl; return 0 ;}
bool f=isSame(head1,head2);

if(f==false)cout<<"NO"<<endl;
else cout<<"YES"<<endl;


    return 0;
}