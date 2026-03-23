#include<bits/stdc++.h>
using namespace std;



int climbingStairs(int n,int k){

    vector<int>dp(k,0);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        // dp[i%k] = 0; 
        for(int j=1;j<k;j++){
            if(i-j<0)continue;
            dp[i%k] = dp[i%k] + dp[(i-j)%k];
            //  cout<<dp[i%k]<<" ";
        }
    }
    // cout<<"\n";
    // cout<<"n%k: "<<n%k<<" "<<dp[n%k];
    // cout<<"\n";
    // for(auto it:dp)cout<<it<<" ";
    return dp[n%k];
}
int main(){
    int n;
    cout<<"Enter stairs: ";
    cin>>n;

    int k;
    cout<<"Enter maximum stairs: ";
    cin>>k;
   
    int ans = climbingStairs(n,k);
    cout<<"ans: "<<ans;
}