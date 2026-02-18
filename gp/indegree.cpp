#include<bits/stdc++.h>
using namespace std;

void indegree(vector<vector<int>>&adj,vector<int>&deg){
    //adj list to indegrre
    for(int u=0;u<adj.size();u++){

        for(auto v:adj[u]){
            deg[v]++;
        }
    }
}
void indegree2(vector<vector<int>>&adj,vector<int>&deg){
    //edge list to indegrre
    // for(auto edge : edges) {
    //     int u = edge[0];
    //     int v = edge[1];

    //     indegree[v]++;   // v ke andar ek incoming edge aa gayi
    // }
}
int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>deg(n,0);
    indegree(adj,deg);


    
    
}