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

        int n;
        cin>>n;

        vector<int>nums(n);
        for(int i=0;i<n;i++)cin>>nums[i];

        // 1 2 1

        // 2 1 4 5 3
        // max(2)+max(2,1)+max(2,1,4)+max(2,1,4,5)+max(2,1,4,5,3)
        // 2 +2 +4 + 5 + 5 = 18
        // 5 1 4 2 3
        // max(5)+max(5,1)+max(5,1,4)+max(5,1,4,2)+max(5,1,4,2,3)
        // 25

        int maxelidx = maxi(nums);

        swap(nums[0],nums[maxelidx]);

        cout<<nums[0]*nums.size()<<"\n";
        
        
    
    }
}