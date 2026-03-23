#include<bits/stdc++.h>
using namespace std;



/* 

Problem:
Maximum Profit in a Grid

A robot is located at the top-left corner of a m x n grid (marked 'S' in the diagram below).
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'E' in the diagram below).
Each cell contains a coin the robot can collect.

What is the maximum profit the robot can accumulate?

*/


int maxProfit(vector<vector<int>>&grid){

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dp(n,vector<int>(m));

    dp[0][0] =grid[0][0];


    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(i>0 && j>0){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
            else if(i>0){
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else if(j>0){
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
        }
    }

    return dp[n-1][m-1];
}

void printPath(int i,int j,vector<vector<int>>&grid,string path){
   
    if(i>=grid.size() || j>=grid[0].size()){
        return;
    }

    if(i==grid.size()-1 && j==grid[0].size()-1){
        cout<<"path: "<<path<<"\n";
        return;
    }

   
    path.push_back('R');
    printPath(i,j+1,grid,path);
    path.pop_back();

    path.push_back('D');
    printPath(i+1,j,grid,path);
    path.pop_back();

}


int main(){

     vector<vector<int>>grid ={
        {4,7,1},
        {5,10,2},
        {6,8,3},
    };
    int res = maxProfit(grid);
    // cout<<"res: "<<res<<"\n";

    printPath(0,0,grid,"");
    
}