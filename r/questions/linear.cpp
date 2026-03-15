#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&nums,int target,int i){

   if(i == nums.size())return false;
   
   return nums[i] == target || check(nums,target,i+1);

}   

vector<int>find(vector<int>&nums,int target,vector<int>&ans,int index){
    
    if(index == nums.size()) return ans;
    if(nums[index]==target){
        ans.push_back(index);
    }
    return find(nums,target,ans,index+1);
}


int main(){

    vector<int>nums = {1,2,3,5,6,6,7};
    vector<int>nums1 = {1,2,3,77,6};
    
    if(check(nums,6,0)){
        cout<<"Yes";
    }
    else cout<<"NO";

    cout<<"\n";

    vector<int>ans;
    find(nums,6,ans,0);
    for(auto it:ans)cout<<it<<" ";
    
}