#include<bits/stdc++.h>
#include "../node.h"
using namespace std;


int depth(Node* root,int x,int d=0){


    if(root ==nullptr)return -1;
    if(root->val ==x)return d;

    int left = depth(root->left,x,d+1);
    if(left != -1) return left;


    return depth(root->right , x,d+1);
}

int main(){

    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);


    root->right = new Node(1);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    cout<<depth(root,4);
}