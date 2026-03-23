#include<bits/stdc++.h>
using namespace std;

/* 


Problem:
Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'S' in the diagram below).
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'E' in the diagram below).

How many possible unique paths are there?




Above is a 3 x 4 grid. How many possible unique paths are there?


*/

//Time complexity: 
//Space complexity: 
//F(i,j) = F(i-1,j) + F(i,j-1)
int uniquePaths(int n,int m){

    // if(i < 0 || j<0) return 0;

    vector<vector<int>>dp(n,vector<int>(m));
    dp[0][0] =1;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(i >0 && j>0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            else if(i>0){
                dp[i][j] = dp[i-1][j];
            }
            else if(j>0){
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];

}
int uniquePathWithObstacles(vector<vector<int>>&grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dp(n,vector<int>(m));

    dp[0][0] =1;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(grid[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }

            if(i>0 && j>0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            else if(i>0){
                dp[i][j] = dp[i-1][j];
            }
            else if(j>0){
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];
}









int main(){

     int n;
    cout<<"total rows: ";
    cin>>n;
    int m;
    cout<<"total col: ";
    cin>>m;

    int ans = uniquePaths(n,m);
    cout<<ans<<"\n";


    vector<vector<int>>grid ={
        {0,0,0},
        {0,1,0},
        {0,0,0},
    };
    int res = uniquePathWithObstacles(grid);
    cout<<"res: "<<res;
}