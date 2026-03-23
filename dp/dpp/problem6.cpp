#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,int n,int m,int ans){
    if(j >= m || i >= n)return 0;
    if(i==n-1 && j == m-1){
        return 1;
    }
    int right = solve(i,j+1,n,m,ans);
    int down = solve(i+1,j,n,m,ans);
    return right+down;
}

int countways(int i,int j,int n,int m,vector<vector<int>>&dp){
    if(j >= m || i >= n)return 0;
    if(i==n-1 && j == m-1){
        return 1;
    }

    if(dp[i][j] != -1)return dp[i][j];
    int right = countways(i,j+1,n,m,dp);
    int down = countways(i+1,j,n,m,dp);

    return dp[i][j] = right+down;
}



int main(){
    int n;
    cout<<"total rows: ";
    cin>>n;
    int m;
    cout<<"total col: ";
    cin>>m;
    int ans = solve(0,0,n,m,0);
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int res = countways(0,0,n,m,dp);

    cout<<"Unique ways to reach [n-1][m-1] are: "<<res;
}