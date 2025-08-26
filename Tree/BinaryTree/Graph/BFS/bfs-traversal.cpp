/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];

void bfs(int src){
   queue<int>q ; 
   q.push(src);
   vis[src]=true;
   
   while(!q.empty()){
       int par=q.front();
       q.pop();
       
       for(int child :adj_list[par]){
           if(!vis[child]){
               q.push(child);
               vis[child]=true;
           }
       }
   }
}
int main()
{
    
int n,e;
cin>>n>>e;
while(e--){
    int a,b;
    cin>>a>>b;
    
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
}

memset(vis,false,sizeof(vis));
int src,dst;
cin>>src>>dst;
bfs(src);

if(vis[dst]){
    cout<<"yes"<<endl;
}else{
    cout<<"No"<<endl;
}
    return 0;
}