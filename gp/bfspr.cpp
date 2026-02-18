#include<bits/stdc++.h>
using namespace std;



void bfs(vector<vector<int>>&adj){

    int n = adj.size()-1;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){

        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){

                int node = q.front();
                q.pop();

                cout<<node<<" ";

                for(int neg:adj[node]){
                    if(!vis[neg]){
                        vis[neg] = 1;
                        q.push(neg);
                    }
                }
            }
        }
    }

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    //tc-> O(N+E) -> undirected
    //tc->O(E)->directed

    //sp-> O(n+E)
    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //delete this if the graph is directed
    }
    // for(auto &it:adj){

    //     for(auto &neg:it){
    //         cout<<neg<<" ";
    //     }
    //     cout<<"\n";
    // }

    bfs(adj);






}


/* 
n=5,m= 6
1 2
1 3
2 4
3 4
3 5
4 5


1->  {2,3} 
2->  {1,4} 
3->  {1,4,5}
4->  {2,3,5}
5->  {3,4}  

*/