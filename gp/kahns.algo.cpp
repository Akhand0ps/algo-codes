#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>indegree(n,0);

    for(int u=0;u<n;u++){

        for(auto v:adj[u]){
            indegree[v]++;
        }
    }

    queue<int>q;
    vector<int>topo;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){

        int front = q.front();
        q.pop();

        topo.push_back(front);

        for(int &neg:adj[front]){
            indegree[neg]--;
            if(indegree[neg] == 0){
                q.push(neg);
            }
        }
    }

    if(topo.size()!= n)cout<<"cycle exist";

    else {
        for(int &node:topo){
            cout<<node<<" ";
        }
    }

    
}