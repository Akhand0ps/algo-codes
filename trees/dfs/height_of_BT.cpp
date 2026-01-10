#include<bits/stdc++.h>
#include "../node.h"
using namespace std;



int height(Node* root){
    if(root == NULL) return 0;

    return 1 + max(height(root->left),height(root->right));
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

    cout<<height(root->right->right);
}