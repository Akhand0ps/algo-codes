#include<bits/stdc++.h>
using namespace std;


//this not dynamic programming, but a regular recursion

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n<=2)return 1;
    return fib(n-1) + fib(n-2);
}


//this is top-down DP (a.k.a recursion + memeoization)

int fiboTopDownHelper(int n,vector<int>&memo){

    if(n==0)return 0;
    if(n <=2)return 1;

    // if(n<=1)return n; better one
    if(memo[n] != -1)return memo[n];

    return memo[n] = fiboTopDownHelper(n-1,memo) + fiboTopDownHelper(n-2,memo);
}

int fiboTopDown(int n){

    vector<int>memo(n+1,-1);
    return fiboTopDownHelper(n,memo);
}

// this is bottm-up DP (forward DP)
//solves base cases first.

/* 

    f(i-1)
        \
         >----------> f(i)
        / 
    f(i-2)
*/


int bottomUp(int n){

    if(n==0)return 0;
    if(n<=2)return 1;

    vector<int>dp(n+1);

    dp[0]=0;
    dp[1]=1;
    // dp[2]=1;

    for(int i=2;i<=n;i++){

        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}   


/* 
    this is bottom-up DP (backward DP)

    --------> f(i+2)
    |
    f(i)
    |
    --------> f(i+1)
*/


int bottomUpBackword(int n){

    if(n<=1)return n;

    vector<int>dp(n+2);

    dp[0]=0;
    dp[1]=1;
    // dp[2]=1;

    for(int i=1;i<n;i++){

        dp[i+1] = dp[i+1] + dp[i];
        dp[i+2] = dp[i+2] + dp[i];
        
    }

    return dp[n];
}   


void frogjump(){
    
    int n = 4;
    vector<int>h = {20,30,40,20};

    vector<int>dp(n,0);
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);

    for(int i=2;i<n;i++){
        
        int onestep = dp[i-1] + abs(h[i-1]-h[i]);
        int secondstep = dp[i-2] + abs(h[i-2] - h[i]);

        dp[i] = min(onestep,secondstep);
    }

    cout<<dp[n-1];
}

int main(){

    frogjump();
}