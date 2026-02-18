#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    //tc-> O(2E) -> undirected
    //tc->O(E)->directed

    //sp-> O(n+E)
    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); //delete this if the graph is directed
    }
    for(auto &it:adj){

        for(auto &neg:it){
            cout<<neg<<" ";
        }
        cout<<"\n";
    }



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