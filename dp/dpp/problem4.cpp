#include<bits/stdc++.h>
using namespace std;



int climbingStairs(int n,int k,vector<bool>&red){


    vector<int>dp(k,0);
    dp[0] = 1;
    

    for(int i=1;i<=n;i++){

        dp[i % k] = 0;

        for(int j=1;j<k;j++){

            if(i-j<0)continue;

            if(red[i]){
                dp[i%k] = 0;
            }
            else{
                dp[i%k] = dp[i%k] + dp[(i-j)%k];
            }
        }
    }
    return dp[n%k];
}

int main(){

     int n;
    cout<<"Enter stairs: ";
    cin>>n;

    int k;
    cout<<"Enter maximum stairs: ";
    cin>>k;

    // vector<int>red = {1,3,4};

    vector<bool> blocked(n+1, false);

    blocked[1] = true;
    blocked[3] = true;
    blocked[4] = true;

    int ans = climbingStairs(n,k,blocked);
    cout<<ans;
}