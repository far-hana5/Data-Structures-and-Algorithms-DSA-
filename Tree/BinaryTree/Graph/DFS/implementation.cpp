/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];

void dfs(int src)
{
    
    cout<<src<<" ";
    vis[src]=true;
    for(int child:adj_list[src]){
        if(vis[child]==false){
            dfs(child);
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
memset(vis,false.sizeof(vis));
dfs(0);



    return 0;
}