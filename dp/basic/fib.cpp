#include<bits/stdc++.h>

using namespace std;

int fib(int n,vector<int>&dp){

    if(n<=1)return n;
    if(dp[n] != -1)return dp[n];



    return dp[n]=fib(n-1,dp) + fib(n-2,dp);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin>>num;


    vector<int>dp(num+1,0);
    // cout<<"Fibo of "<<num<<" is =>"<<fib(num,dp);

    dp[0]=0,dp[1]=1;

    for(int i=2;i<=num;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[dp.size()-1]<<"\n";


    //we don't really entire array;
    cout<<"space optimise"<<"\n";


    int prev2=0;
    int prev1=1;

    for(int i=2;i<=num;i++){

        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }


    cout<<"Prev1:=>"<<prev1;






}