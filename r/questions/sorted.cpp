#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&nums,int i){

    if( i== nums.size()-1){
        return true;
    }

    // if(nums[i] < nums[i+1]) return check(nums,i+1);
    // return false;

    return nums[i] < nums[i+1] && check(nums,i+1);

}
int main(){

    vector<int>nums = {1,2,3,5,6};
    vector<int>nums1 = {1,2,3,77,6};
    
    if(check(nums,0)){
        cout<<"Yes";
    }
    else cout<<"NO";
    cout<<"\n";
     if(check(nums1,0)){
        cout<<"Yes";
    }
    else cout<<"NO";
}