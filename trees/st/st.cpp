#include<bits/stdc++.h>
using namespace std;



class Node{

    public:
    int data;
    int startInterval;
    int endInterval;
    
    Node* left;
    Node* right;

    Node(int startInterval,int endInterval){
        this->startInterval = startInterval;
        this->endInterval = endInterval; 
        left=right=nullptr;
    }
};


Node* construct(vector<int>&nums,int start,int end){
    if(start == end){
        Node* newNode = new Node(start,end);
        newNode->data = nums[end];
        return newNode;
    }

    Node* newNode = new Node(start,end);
    int mid = start + (end-start)/2;
    
    newNode->left = construct(nums,start,mid);
    newNode->right = construct(nums,mid+1,end);

    newNode->data = newNode->left->data + newNode->right->data;
    
    return newNode;
}

void display(Node* node){

    if(!node)return;

    cout<<"Node: "<<node->data<<" "<<"Interval: ["<<node->startInterval<<","<<node->endInterval<<"]"<<"\n";

    display(node->left);
    display(node->right);
}

int query(int qsi,int qei,Node* root){

    if(root->startInterval >= qsi && root->endInterval <= qei){
        return root->data;
    }

    else if(root->startInterval > qei || root->endInterval < qsi){
        return 0;
    }
    
    else return query(qsi,qei,root->left) + query(qsi,qei,root->right);
}


int update(int  index,int value,Node* node){

    if(index >= node->startInterval && index <= node->endInterval){
        if(index == node->startInterval && index == node->endInterval){
            node->data = value;
            return node->data;
        }
        else{

            int leftans= update(index,value,node->left);
            int rightans = update(index,value,node->right);

            return node->data =  leftans + rightans;
        }
    }

    return node->data;
}

int main(){

    vector<int>nums = {3,8,7,6,-2,-8,4,9};
    Node* root = nullptr;

    root = construct(nums,0,nums.size()-1);

    display(root);
    cout<<"\n";
    cout<<"sum: "<<query(2,6,root);
    cout<<"\n";

    cout<<"updated root: "<<update(3,14,root);
    cout<<"\n";
    cout<<"======================================="<<"\n";

    display(root);

    cout<<"=======================================";

}