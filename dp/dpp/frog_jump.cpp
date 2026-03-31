#include<bits/stdc++.h>
using namespace std;


/* 

 A frog wants to climb a staircase with n steps.
 Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. 
 To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
 The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. 
 Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

*/
//top down -> time complecity -> O(n*k) SC-> O(n)dp array + Stack space
int solve(int ind,vector<int>&heights,vector<int>&dp,int k){

    if(ind == 0)return 0;

    if(dp[ind] != -1)return dp[ind];

    int miniSteps = INT_MAX;

    for(int j=1;j<=k;j++){

        int jump = solve(ind-j,heights,dp,k) + abs(heights[ind] - heights[ind-j]);

        miniSteps = min(miniSteps,jump);
    }

    return miniSteps;
}

int q1(int n, vector<int>& height, int k) {
    // DP array initialized to -1
    vector<int> dp(n, -1);
    // Start recursion from last index
    return solve(n - 1, height, dp, k);
}


//bottomup O(n*k) , SC-> O(n) + no auxilary space;
int bottomup(vector<int>&height,int k){
    int n = height.size();
    vector<int>dp(n,0);
    
    dp[0];
    dp[1] = abs(height[0]-height[1]);

    

    for(int i=2;i<n;i++){
        int miniSteps = INT_MAX;
        for(int j=1;j<=k;j++){

            if(i-j<0)continue;

            int jump = dp[i-j] + abs(height[i]-height[i-j]);

            miniSteps = min(miniSteps,jump);
        }
        dp[i] = miniSteps;
    }

    return dp[n-1];
    
}
int main(){

    //  vector<int> height{30, 10, 60, 10, 60, 50};
    vector<int> height{20, 30, 40, 20};

    int n = height.size();
    int k = 2;

    // Output the minimum cost
    cout << q1(n, height, k) << endl;
    cout<<bottomup(height,k)<<endl;
    
    
}