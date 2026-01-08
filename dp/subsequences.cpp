#include<bits/stdc++.h>
using namespace std;






void generateAllsubsequences(int index,vector<int>&nums,vector<int>&ans){
    // cout<<index<<" ";
    // cout<<"\n";
    if(index == nums.size()){

        if(ans.size() ==0){
            cout<<"[]"<<"\n";
        }
       else{
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
       }
        return;
    }
    ans.push_back(nums[index]);
    generateAllsubsequences(index+1,nums,ans);

    ans.pop_back();
    generateAllsubsequences(index+1,nums,ans);
}


int  main(){

    vector<int>nums1 = {2,1,-2,5};
    vector<int>nums2 = {3,0,-6};
    vector<int>nums = {3,1,2};

    vector<int>ans;

    cout<<"1: "<<"\n";
    generateAllsubsequences(0,nums1,ans);
    cout<<"\n";
    cout<<"2: "<<"\n";
    generateAllsubsequences(0,nums2,ans);
    cout<<"\n";
    cout<<"3: "<<"\n";
    generateAllsubsequences(0,nums,ans);



}