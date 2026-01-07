
#include<bits/stdc++.h>
using namespace std;


int main(){

    int k;
    cout<<"Enter K: ";
    cin>>k;

    vector<int>nums = {100,200,300,400};
    int maxisum = 0;

    int sum =0;

    int l=0;
    int r=0;
    int n = nums.size();



    while(r < n){

        sum += nums[r];

        if(r-l+1 > k){
            sum -= nums[l];
            l++;
        }

        maxisum = max(maxisum,sum);
        r++;
    }

    cout<<"maximum sum of subarray: "<<maxisum;
    return 0;
}