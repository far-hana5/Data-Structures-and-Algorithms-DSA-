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
          Node* left;
          Node* right;
          
        Node(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
    };
    
Node* inputTree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1)root=NULL;
    else root=new Node(val);
    
    queue<Node*>q;
    
    if(root) q.push(val);
    
    
    while(!q.empty())
    {
        Node* p=q.front();
        q.pop();
        
        
        int l,r;
        cin>>l>>r;
        Node* myLeft; Node* myRight;
        
        if(l==-1)myLeft=NULL;
        else myLeft=new Node(l);
        
        if(r==-1)myRight=NULL;
        else myRight=new Node(r);
        
        p->left=myLeft;
        p->right=myRight;
        
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
        
        
    }
    
  return   root;
    
}

bool search(Node* root,int val){
    if(root==NULL)return false;
    if(root->val==val)return true;
    
    if(val<root->val){
      return  search(root->left,val);
    }
    else{
       return search(root->right,val);
    }
}

int main()
{
   
  Node* root=inputTree();
  int val;cin>>val;
   if(search(root,val)){
       cout<<"found"<<endl;
   }else{
cout<<"Not found"<<endl;
   }

    return 0;
}