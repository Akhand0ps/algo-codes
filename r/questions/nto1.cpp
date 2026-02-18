#include<bits/stdc++.h>
using namespace std;

//print n to 1

void solve(int n){

    if(n==0) return;
    cout<<n<<" ";
    solve(n-1);
}
//1 to n
void solve1(int num){
    if(num == 0)return;
    solve1(num-1);
    cout<<num<<" ";
}
int solve2(int n){

    if(n <=1)return 1;
    return  n * solve2(n-1);
}

int sumtillN(int n){

    if(n==0)return 0;

    return n + sumtillN(n-1);
}
int sumofdigits(int n){

    if(n == 0)return 0;

    return n%10 + sumofdigits(n/10);
}


int main(){
    int n;
    cout<<"Enter num: ";
    cin>>n;

    // solve(n);
    // cout<<"\n";
    // solve1(n);
    // cout<<"\n";
    // int ans = solve2(n);
    // cout<<"ans:"<<ans;
    // cout<<"\n";

    // cout<<sumtillN(n);

    cout<<sumofdigits(n);
}