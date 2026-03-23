#include<bits/stdc++.h>
using namespace std;


/*
Problem:
Paid Staircase

You are climbing a paid staircase. It takes n steps to reach to the top and you have to
pay p[i] to step on the i-th stair. Each time you can climb 1 or 2 steps.
What's the cheapest amount you have to pay to get to the top of the staircase?

*/

// Time complexity: O(n)
// Space complexity: O(n)


int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();
    vector<int>dp(n+1,0);
    dp[0] = cost[0];
    dp[1]=cost[1];

    for(int i=2;i<=cost.size();i++){

        if(i == n){
            dp[i] = min(dp[i-1],dp[i-2]) + dp[n];
        }
        else{
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
    }
    return dp[n];
}


int paidStaricase(int n ,vector<int>&p){

    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=p[1];

    for(int i=2;i<=n;i++){
         dp[i] = min(dp[i-1],dp[i-2]) + p[i];
    }

    return dp[n];
}

int paidStaircase2(int n ,vector<int>&p){ 

    vector<int>dp(n+1,0);
    vector<int>parent(n+1,0);

    dp[0]=0;
    dp[1]=p[1];
    parent[1] = 0;

    for(int i=2;i<=n;i++){
        if(dp[i-1] < dp[i-2]){
            dp[i] = dp[i-1] + p[i];
            parent[i] = i-1;
        } else {
            dp[i] = dp[i-2] + p[i];
            parent[i] = i-2;
        }
    }

    // reconstruct path
    vector<int>path;
    int cur = n;
    while(cur > 0){
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    for(auto x : path) cout << x << " ";

    return dp[n];
}

int main(){

    vector<int>p = {0,3,2,4};
    int ans = paidStaircase2(2,p);
    // cout<<ans;
}
