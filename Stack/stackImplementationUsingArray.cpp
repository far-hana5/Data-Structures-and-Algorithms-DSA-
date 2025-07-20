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

int main()
{

    /*
    myStack st;

int n;
cin>>n;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    st.push(x);
}

  while(!st.empty()){
      cout<<st.top()<<endl;
      st.pop();
  }
}
   
    
    */
   myStack st;
   
st.push(10);
st.push(20);
st.push(30);
cout<<st.top()<<endl;
st.pop();
if(st.empty()==false){
    cout<<st.top()<<endl; 
}
   







    return 0;
}