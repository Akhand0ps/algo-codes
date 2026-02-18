#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){     
    vis[node] =1;
    pathvis[node] = 1;
    for(auto &neg:adj[node]){
        
        //not visited hai
        if(!vis[neg]){
            
            if(dfs(neg,adj,vis,pathvis))return true;
        }
        else if(pathvis[neg]){
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}


bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
    // Code here
    vector<vector<int>>adj(N);
    vector<int>vis(N,0);
    vector<int>pathvis(N,0);
    for(int i=0;i<P;i++){
        int u = prerequisites[i].first;
        int v = prerequisites[i].second;
        adj[u].push_back(v);
    }
    for(int i=0;i<N;i++){
        
        if(!vis[i]){
            
            if(dfs(i,adj,vis,pathvis))return false;;
        }
    }
    return true;
}