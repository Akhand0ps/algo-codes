#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){

    vis[node] = 1;
    pathvis[node]=1;

    //neghbour
    for(int &neg:adj[node]){

        //if it is not visited
        if(!vis[neg]){

            if(dfs(neg,adj,vis,pathvis)) return true;
        }

        //if it is visited and has the same path then it is 100% cycle

        else if(pathvis[neg]){
            return true;
        }
    }

    pathvis[node] = 0;
    return false;
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

   vector<int>vis(n+1,0);
   vector<int>pathvis(n+1,0);

    for(int i=0;i<n;i++){

        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis)){
                cout<<"cycle exist";
                break;
            }
            else cout<<"cycle does not exist";
        }
    }
}