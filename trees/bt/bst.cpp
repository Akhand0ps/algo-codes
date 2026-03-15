#include<bits/stdc++.h>
using namespace std;
class Node{

    public:
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        this->val = val;
        left=right = nullptr;
        height = 0;
    }
};

int height(Node* node){
    if(node == nullptr){
        return -1;
    }
    return node->height;
}

Node* insert(int value,Node* node){

    if(!node){
        return new Node(value);
    }

    if(node->val > value){
        node->left = insert(value,node->left);
    }

    if(node->val < value){
        node->right =  insert(value,node->right);
    }

    node->height = max(height(node->left),height(node->right)) +1; 
    return node; // return current node. because after inserting you dont want to change what is already there. smjha!!
    
}

bool balanced(Node* node){

    if(node == nullptr){
        return true;
    }

    return abs(height(node->left)-height(node->right)) <=1 && balanced(node->left) && balanced(node->right);
}


void display(Node* node,string details){
    if(node == nullptr)return;
    cout<<details<<node->val<<"\n";
    display(node->left,"left child of node: ");
    display(node->right,"right child of node: ");
}

void populate(vector<int>&nums,Node* root){
    for(int i=1;i<nums.size();i++){
        insert(nums[i],root);
    }
}

Node* popusorted(vector<int>&sorted,int start,int end,Node* root){

    if(start >= end){
        return root;
    }
    int mid = start + (end-start)/2;
    root =insert(sorted[mid],root);
    root = popusorted(sorted,start,mid,root);
    root = popusorted(sorted,mid+1,end,root);
    return root;
}
Node* populateSorted(vector<int>sorted,Node* node){

    return popusorted(sorted,0,sorted.size(),node);
}

void preorder(Node* node){
    if(node == nullptr)return;
    cout<<node->val<<" ";
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node* node){
    if(node == nullptr)return;
   
    inorder(node->left);
    cout<<node->val<<" ";
    inorder(node->right);
}
void postorder(Node* node){
    if(node == nullptr)return;
   
    postorder(node->left);
    postorder(node->right);
    cout<<node->val<<" ";
}

int main(){

    // int rootVal;
    // cout<<"Enter root val: ";
    // cin>>rootVal;
    // Node* root = new Node(rootVal);

    // vector<int>nums = {5,2,7,1,4,6,9,8,3,10};
    
    // populate(nums,root);
    
    // // insert(5,root);
    // display(root,"Root Node: ");
    // cout<<"\n";
    // cout<<"Height of tree:"<<height(root)<<"\n";
    // if(balanced(root))cout<<"Balanced"<<"\n";
    // else cout<<"Not balanced"<<"\n";

    cout<<"==========================="<<"\n";

    ///sorted 

    vector<int>sorted = {1,2,3,4,5,6,7,8,9,10};
    Node* newRoot = nullptr;
    newRoot = populateSorted(sorted,newRoot);
    display(newRoot,"Sorted array wale tree ka node: ");
    cout<<"\n";
    cout<<"Height of tree(sorted):"<<height(newRoot)<<"\n";
    if(balanced(newRoot))cout<<"Balanced"<<"\n";
    else cout<<"Not balanced"<<"\n";

    cout<<"preorder: ";
    preorder(newRoot);
    cout<<"\n";
    cout<<"inorder: ";
    inorder(newRoot);

    cout<<"\n";
    cout<<"postorder: ";
    postorder(newRoot);

}