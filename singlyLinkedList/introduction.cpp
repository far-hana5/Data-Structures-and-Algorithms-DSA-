/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
#include<bits/stdc++.h>
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

int main(){
Node a(10),b(20),c(30);
//a.val=10;
//b.val=20;
//c.val=30;
a.next=&b;
b.next=&c;
//c.next=NULL;

cout<<a.val<<" "<<(*a.next).val<<" "<<c.val<<" "<<endl;
cout<<a.val<<" "<<a.next->val<<" "<<a.next->next->val<<" "<<endl;

cout<<a.val<<" "<<(*a.next).val<<" "<<(*(*a.next).next).val<<" "<<endl;

}
*/


//  Dynamic Node

/*


#include<bits/stdc++.h>
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

int main(){
Node* head= new Node(10);//new keyword can access heap memory
//node are in heap memory, head are in stack> memory(pointer) ;

Node* a=new Node(20);
Node* b=new Node(30);
Node* c=new Node(40);
//a.next=&b;
//(*head).next=a; //head a pointer what why we dereference it.previously
// b was a object that why accessing its address we did &b . but now a itself a address(pointer)
head->next=a;//same as (*head).next=a;
a->next=b;
b->next=c;
cout<<head->val<<"  "<<endl;// (*head).val same sa  head->val
cout<<head->next->val<<endl;
cout<<head->next->next->val<<endl;
cout<<head->next->next->next->val<<endl;
Node* tmp=head ;//pointer tmp
while(tmp!=NULL){
    cout<<tmp->val<<" ";
   tmp = tmp->next;
}
tmp=head;
cout<<endl;
while(tmp!=NULL){
    cout<<tmp->val<<" ";
   tmp = tmp->next;
}


}

*/