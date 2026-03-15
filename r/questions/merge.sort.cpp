#include<bits/stdc++.h>
using namespace std;

vector<int>m(vector<int>&first,vector<int>&second){

    int i =0;
    int j =0;
    int k =0;
    int n = first.size();
    int m = second.size();
    vector<int>mix(n+m);

    while(i<first.size() && j < second.size()){

        if(first[i] < second[j]){

            mix[k] = first[i];
            i++;
        }
        else{

            mix[k] = second[j];
            j++;
        }
        k++;
    }

    while(i < first.size()){
        mix[k] = first[i];
        i++;
        k++;
    }
    while(j < second.size()){
        mix[k]= second[j];
        j++;
        k++;
    }

    return mix;
}

vector<int>mergeSort(vector<int> nums){

    if(nums.size() == 1)return nums;

    int mid = nums.size()/2;
    
    vector<int> left = mergeSort(vector<int>(nums.begin(),nums.begin()+mid));
    vector<int> right = mergeSort(vector<int>(nums.begin()+mid,nums.end()));
    
    return m(left,right);
}



int main(){

    vector<int>nums = {8,3,4,12,5,6};
    vector<int>res = mergeSort(nums);

    for(auto &it:res)cout<<it<<" ";
}