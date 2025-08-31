/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
 int grid[1005][1005];
 bool vis[1005][1005];

vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}} ;
int n,m;
bool valid(int i,int j){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
    if(grid[i][j]==0)return false;
    return true;
}

int dfs(int si,int sj)
{
 
 
 vis[si][sj]=true;
int store=1;
 
 for(int i=0;i<4;i++){
     int ci=si+d[i].first;
     int cj=sj+d[i].second;
     if(valid(ci,cj)==true &&!vis[ci][cj]){
        store+= dfs(ci,cj);
     }
 }
    return store;
 
}
int main()
{
    
cin>>n>>m;

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
       
    }
}


memset(vis,false,sizeof(vis));
    vector<int>result;
    for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        
       if(vis[i][j]==false && grid[i][j]=='1'){
          int res= dfs(i,j);
           result.push_back(res);
       }
    }
    }
    if(result.empty()){
        cout<<0<<"\n";
        return 0;
    }
    sort(result.begin(),result.end(),greater<int>());
    
        cout<<result[0]<<" ";
    
cout<<"\n";
//cout<<dfs<<endl;

    return 0;
}
/*
class Solution {
public:

vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}} ;
int n,m; bool vis[1005][1005];
bool valid(int i,int j,vector<vector<int>>& grid){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
    if(grid[i][j]==0)return false;
    return true;
}
int dfs(int si,int sj,vector<vector<int>>& grid)
{
 
 
 vis[si][sj]=true;
int store=1;
 
 for(int i=0;i<4;i++){
     int ci=si+d[i].first;
     int cj=sj+d[i].second;
     if(valid(ci,cj,grid)==true &&!vis[ci][cj]){
        store+= dfs(ci,cj,grid);
     }
 }
    return store;
 
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
memset(vis,false,sizeof(vis));
    vector<int>result;
    for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        
       if(vis[i][j]==false && grid[i][j]=='1'){
          int res= dfs(i,j,grid);
           result.push_back(res);
       }
    }
    }
    if(result.empty()){
       return 0;
    }
    sort(result.begin(),result.end(),greater<int>());
     return result[0];
    }
};
*/