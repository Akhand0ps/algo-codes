
#include<bits/stdc++.h>
using namespace std;

void f(int n){

    if(n == 6)return;

    cout<<n<<" ";
    f(n+1);
}

int main(){

    f(1);
}