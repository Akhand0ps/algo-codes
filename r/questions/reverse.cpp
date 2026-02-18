#include<bits/stdc++.h>
using namespace std;

int sum = 0;

void rev(int n){

    if(n == 0)return;
    
    int rem = n%10;
    sum = sum * 10 + rem;
    rev(n/10);
}

// void op(int n,int p){
//     if()
// }
int main(){

    int n;
    cout<<"Enter number: ";
    cin>>n;
    rev(n);

    cout<<"Reversed number: "<<sum;

}