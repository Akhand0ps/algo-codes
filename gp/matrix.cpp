#include<bits/stdc++.h>

using namespace std;


//matrix method
int main(){


    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>>mat(n+1,vector<int>(n+1,0));

    //tc-> O(n)
    //sc=> O(n^2) 

    for(int i=0;i<m;i++){

        int u,v;
        cin>>u>>v;

        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    for(auto &it:mat){
        for(auto &iit:it){
            cout<<iit<<" ";
        }
        cout<<"\n";

    }
}


/*
    5 6
    1 2
    1 3
    2 4
    3 4
    3 5
    4 5
    0 0 0 0 0 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 1 1
    0 0 1 1 0 1
    0 0 0 1 1 0
 */