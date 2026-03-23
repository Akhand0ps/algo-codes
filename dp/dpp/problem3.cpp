#include<bits/stdc++.h>
using namespace std;


/* 

Problem:
    Climbing stairs with k steps

    you are climbing a stair case. It takes n steps to reach to the top
    Each time you can either climb 1 or 2 steps
    In how many distinct ways can you climb to the top?



Framework for solving DP problem:
    1: Define the objective function
        f(i) is the distinct ways to reach the i-th stairs
    2: Identity bases cases
        f(0) = 1; -> doing nothing also counts
        f(1) = 1;
    3: Write down a recurrence relation for the optimized objective function
        f(n) = f(n-1) + f(n-2) + .... + f(n-k);
    4: What's the order of executuon
        bottom-up 
    5: where to look for the answere?
        f(n)


*/

//Time complexicity: O(n*k)
//SC: O(n)

int climbstais(int n,int k){
    vector<int>dp(n+1);
    dp[0] = 1;
    dp[1] = 1;     
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j<0){
                continue;
            }
            dp[i] = dp[i] + dp[i-j];
            cout<<dp[i]<<" ";
        }
    }
    cout<<"\n";
    return dp[n];
}

int solve(int n,vector<int>&dp){

    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1)return dp[n];
    
    return dp[n] = solve(n-1,dp) + solve(n-2,dp);
}


int solve1(int n){

    int prev1 = 1;
    int prev2 = 1;

    for(int i=2;i<=n;i++){

        int curr = prev1+prev2;
        prev2 = prev1;
        prev1  = curr;
    }

    return prev1;
}

int main(){

    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"\n";
    int k;
    cout<<"enter k: ";
    cin>>k;

    vector<int>dp(n+1,-1);
    int ans = climbstais(n,k);
    // cout<<"bottom-up: "<<ans<<"\n";
    // cout<<"top-down: "<<solve(n,dp)<<"\n";
    // cout<<"top-down: "<<solve1(n)<<"\n";

}