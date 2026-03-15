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



void display(TreeNode* node){

    if(!node)return;
    
    cout<<node->val<<" ";
    display(node->left);
    display(node->right);
}

int diameter = 0;

int height(TreeNode* node){

    if(node == nullptr){
        return 0;
    }

    int leftheight = height(node->left);
    int rightheight = height(node->right);

    int dia = leftheight + rightheight;
    diameter = max(diameter,dia);

    return max(leftheight,rightheight)+1;
}


bool check(TreeNode* root,int mini,int maxi){

    if(root==nullptr)return true;

    if(root->val <= mini || root->val >= maxi){
        return false;
    }

    return check(root->left,mini,root->val) && check(root->right,root->val , maxi);
}
bool validateBSt(TreeNode* root){

    return check(root,INT_MIN,INT_MAX);
}


TreeNode* lca(TreeNode* root,int n1,int n2){

    if(!root)return NULL;

    if(root->val == n1 || root->val == n2)return root;

    TreeNode* left = lca(root->left,n1,n2);
    TreeNode* right = lca(root->right,n1,n2);

    if(left == nullptr && right != nullptr)return right;
    if(left != nullptr && right == nullptr)return left;

    if(left && right)return root;
}

int main(){

    TreeNode* root = new TreeNode(12);

    root->left = new TreeNode(8);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(11);

    root->right = new TreeNode(18);

    display(root);
    cout<<"\n";
    cout<<"Height of BT in nodes: "<<height(root)<<"\n";
    
    cout<<"Diameter of BT: "<<height(root)<<"\n";




    //validateBST

    TreeNode* newRoot = new TreeNode(10);
    newRoot->left = new TreeNode(5);

    newRoot->right = new TreeNode(20);
    newRoot->right->left = new TreeNode(9);
    newRoot->right->right = new TreeNode(25);

    TreeNode* Nroot = new TreeNode(2);
    Nroot->left = new TreeNode(1);
    Nroot->right = new TreeNode(3);
    Nroot->right->right = new TreeNode(5);

    if(validateBSt(Nroot))cout<<"Valid"<<"\n";
    else cout<<"Not valid";
    
   



}