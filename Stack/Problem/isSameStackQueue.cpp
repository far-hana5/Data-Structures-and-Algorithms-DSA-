/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool areEqual(stack<int>st,queue<int>q){
    if(st.size()!=q.size())return false;
    
    while(!st.empty()&& !q.empty()){
        if(st.top()!= q.front()){
            return false;
        }
        st.pop();
        q.pop();
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n;
   stack<int>st;
   
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    
    
    cin>>m;
    queue<int>q;
    
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        q.push(val);
    }
    
    if(n!=m){
        cout<<"No\n";
        return 0;
    }
    
    if(areEqual(st,q)){
        cout<<"Yes\n";
    }else{
        cout<<"NO\n";
    }
    

    return 0;
}