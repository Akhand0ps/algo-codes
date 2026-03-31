#include<bits/stdc++.h>
using namespace std;


//recursion tC-> O(2^n) SC-> stack space
bool targetsum(int index,int target,vector<int>&nums){

    if(target == 0)return true;
    if(index == 0)return target == nums[0];

    bool pick = targetsum(index-1,target-nums[index],nums);
    bool notpick = targetsum(index-1,target,nums);


    return pick || notpick;
}


//how to apply memoization?
// - figure out the changing states
// - make dp of that
// here dp[index][target] - it means do i have the sum of target from 0 till i
bool memoization(int index,int target,vector<int>&nums,vector<vector<int>>&dp){

    if(target == 0)return true;
    if(index == 0)return target == nums[0];

    if(dp[index][target] != -1)return dp[index][target];
    
    bool pick = false;

   if(nums[index] <= target){
         pick = memoization(index-1,target-nums[index],nums,dp);
   }

    bool notpick = memoization(index-1,target,nums,dp);

    return dp[index][target] == pick || notpick;

}

bool bottumUp(vector<int>&nums,int k){

    int n = nums.size();
    // int m = target;
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));

    //n+1 ki jagah n bhi le skkta hai becaause in recursion your startign from n-1;
    

    //what if the target is 0?
    //target 0 kab ho skta hai aur kitni indexces ke liye ho skta hai?
    //target 0 kisi bhi index from 0 to n-1 ke liye ho skta hai.
    //isliye

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    //and dp[0][nums[0]] = true ,always true
    /* 
    
        mtlb {2,3,1,1} index=0,nums[0] =2
        ab index 0 se leke 0 tk kya koi sum hai jo 2 ke equal hai? => yes hai
        dp[index][target] , hamara target nums[0] hai woh toh hamesa true hi hoga kyu ham sirf usi index ko consider kr rhe hai.


    */

    dp[0][nums[0]] = true; 


    for(int ind=1;ind<n;ind++){

        for(int target=1;target<=k;target++){
            // dp[i][0]=true;

            // dp[index][target]
            bool pick = false;

            if(nums[ind] <= target){
                pick = dp[ind-1][target - nums[ind]];
            }

            bool notpick = dp[ind-1][target];

            dp[ind][target] = pick || notpick;

        }
    }
    return dp[n-1][k];

    //TC- O(Nxtarget) SC: O(Nxtarget);

}


int main(){

    vector<int>nums = {2,3,1,1};

    // if(targetsum(nums.size()-1,2,nums)){
    //     cout<<"yes it does";
    // }
    // else{
    //     cout<<"nope";
    // }
    int n = 1e3;
    int m = 1e3;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    
    int target;
    cout<<"target: ";
    cin>>target;
    if(memoization(nums.size()-1,target,nums,dp)){
        cout<<"yes it does";
    }
    else{
        cout<<"nope";
    }

    

}