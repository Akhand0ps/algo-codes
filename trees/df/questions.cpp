#include<bits/stdc++.h>
using namespace std;

class TreeNode{

    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left=right = nullptr;
    }
};




bool helper(TreeNode* node,vector<int>&nums,int i){

    if(!node){
        return false;
    }

    if(i > nums.size() && node->val == nums[i]){
        return false;
    }

    if(!node->left && !node->right && i == nums.size()-1)return true;

    return helper(node->left,nums,i+1) || helper(node,nums,i+1);
}

bool pathexists(TreeNode* node,vector<int>&nums){

    if(!node){
        return nums.size() == 0;
    }

    return helper(node,nums,0);
}


int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(9);

    root->right->right = new TreeNode(12);
    root->right->left = new TreeNode(10);
    root->right->left->left = new TreeNode(16);

    root->right->right->left = new TreeNode(8);

    vector<int>nums = {3,9,12,8};

    if(pathexists(root,nums))cout<<"Yes it does";
    else cout<<"Nope";

}