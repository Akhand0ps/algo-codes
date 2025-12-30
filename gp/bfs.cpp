#include<bits/stdc++.h>


using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,m;
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter number of edges: "<<endl;
    cin>>m;

    vector<vector<int>>adj(n);
    // vector<vector<pair<int,int>>>adjwt(n); ye wt graph ke liye hai;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<"->";
    //     for(int it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }




    cout<<"\n";

    vector<int>vis(n+1,0);

    // queue<int>q;
    // q.push(0);
    // vis[0]=1;

    // vector<int>ans;
    // ans.push_back(q.front());


    //ye for loop remove krde jb kKOI SRC GIVEN HOO.
    for(int i=0;i<n;i++){

        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                cout<<node<<" ";
                for(int neighbour:adj[node]){
                    if(!vis[neighbour]){
                        vis[neighbour] = 1;
                        q.push(neighbour);
                    }
                }
            }
        }
    }


}