#include<bits/stdc++.h>
using namespace std;


int main(){


    vector<int>nums = {2,3,1,2,4,3};
    int t;
    cout<<"Enter target: ";
    cin>>t;

    //brute

    int minlength = INT_MAX;

    for(int i=0;i<nums.size();i++){

        int sum =0;
        for(int j=i;j<nums.size();j++){

            sum +=nums[j];

            if(sum >=t){
                minlength = min(minlength,j-i+1);
            }
        }
    }

    cout<<"brute minLength: "<<minlength<<"\n";

    minlength = INT_MAX;

    int l=0;
    int r=0;
    int sum =0;
    while(r < nums.size()){

        sum += nums[r];

        while( sum >= t){

            minlength = min(minlength,r-l+1);
            sum -=nums[l];
            l++;
        }
        r++;
    }


    cout<<"optimal minlength: "<<minlength;



}