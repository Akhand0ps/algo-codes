#include<bits/stdc++.h>
using namespace std;

void p1(int r,int c){

    if(r == 0)return;

    if(c < r){
        cout<<"*"<<" ";
        p1(r,c+1);
    }
    else{
        cout<<"\n";
        p1(r-1,0);
    }
}

void b(int r,int c,vector<int>&nums){

    if(r==0)return;
    
    if(c < r){
        if(nums[c] > nums[c+1]){
            swap(nums[c],nums[c+1]);
        }
        b(r,c+1,nums);
    }
    else{
        b(r-1,0,nums);
    }
}

void selection(int r,int c,vector<int>&nums,int maxi){

    if(r==0)return;
    if(c < r){
        if(nums[c] > nums[maxi]){
            selection(r,c+1,nums,c);
        }
        else{
            selection(r,c+1,nums,maxi);
        }
    }
    else{
        swap(nums[r-1],nums[maxi]);
        selection(r-1,0,nums,0);
    }
}



int main(){

    p1(4,0);
    vector<int>nums = {4,3,2,1};
    b(nums.size()-1,0,nums);
    cout<<"Bubble: ";
    for(auto &it:nums)cout<<it<<" ";
    cout<<"\n";
    cout<<"selection: ";
    selection(nums.size()-1,0,nums,0);
    for(auto &it:nums)cout<<it<<" ";
}