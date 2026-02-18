#include<bits/stdc++.h>
using namespace std;

bool isCycle(int src,vector<vector<int>>&adj,vector<int>&vis){

    queue<pair<int,int>>q;
    q.push({src,-1});

    while(!q.empty()){
        pair<int,int> front = q.front();
        int node = front.first;
        int parent = front.second;
        q.pop();

        for(auto &neg:adj[node]){

            if(!vis[neg]){
                vis[neg] = 1;
                q.push({neg,node});
            }

            else if(parent != neg)return true;
        }
    }

    return false;

}

int main(){


    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);

    for(int i=0;i<n;i++){

        if(!vis[i]){

            if(isCycle(i,adj,vis)){
                cout<<"true";
                break;
            }
        }
    }   

    cout<<"False";
}