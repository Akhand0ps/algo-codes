#include<bits/stdc++.h>
using namespace std;

int maxi = INT_MIN;
int solve(int ind,vector<int>&nums){
    if(ind < 0)return 0;

    if(ind == 0)return nums[0];    
   
    int pick = nums[ind] + solve(ind-2,nums);

    int notpick = 0 + solve(ind-1,nums);

    return max(pick,notpick);
}

int memoization(int ind,vector<int>&nums,vector<int>&dp){

    if(ind < 0)return 0;

    if(ind == 0)return nums[0]; 

    if(dp[ind] != -1)return dp[ind];
   
    int pick = nums[ind] + memoization(ind-2,nums,dp);

    int notpick = 0 + memoization(ind-1,nums,dp);

    return dp[ind] = max(pick,notpick);
}

int bottomup(int ind,vector<int>&nums){

    

}
int main(){

    vector<int>nums = {2,1,4,9};
    int n = nums.size();

    cout<<"ans: "<<solve(n-1,nums)<<"\n";

    vector<int>dp(n,-1);
    cout<<"ans: "<<memoization(n-1,nums,dp);

    
}