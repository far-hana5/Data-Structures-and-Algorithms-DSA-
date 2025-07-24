/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
       vector<int>v;
       
       void push(int val){
           v.push_back(val);
       }
       
       void pop(){
           v.pop_back();
       }
       
       int top(){
           return v.back();
       }
       
       int size(){
           return v.size();
       }
       bool empty(){
           return v.empty();
       }
};

bool areEqual(myStack st1,myStack st2){
    if(st1.size()!=st2.size()){
        return false;
    }
    
    while(!st1.empty()){
        if(st1.top()!=st2.top()){
            return false;
        }
        
        st1.pop();
        st2.pop();
    }
    
    return true;
}

int main()
{
    int n,m;
    cin>>n;
    myStack st;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    
    cin>>m;
    myStack st1;
    
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        st1.push(val);
    }
    
    if(areEqual(st,st1)){
        cout<<"Yes\n";
    }else{
        cout<<"NO\n";
    }
    

    return 0;
}

/*
Question: Take two stacks of size N and M as input and check if both of 
them are the same or not. Don’t use STL stack to solve this problem.

*/