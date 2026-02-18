#include<bits/stdc++.h>
using namespace std;


int maxi(vector<int>&nums){
    int maxel = INT_MIN;
    int idx = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > maxel){
            maxel = nums[i];
            idx = i;
        }
    }

    return idx;
}
int main(){


    int q;
    cin>>q;


    while(q--){

        int no_of_boxes,max_rev_len;
        cin>>no_of_boxes>>max_rev_len;

        vector<int>nums(no_of_boxes);
        for(int i=0;i<no_of_boxes;i++)cin>>nums[i];

        3 2

        1 2 3
        
        

        
    
    }
}     