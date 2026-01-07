#include<bits/stdc++.h>

#include "../node.h"
using namespace std;


//POSTORDER TRAVERSAL (LEFT | RIGHT | ROOT)

void postorder(Node* node){

    if(node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->val<<" ";  //root

}


int main(){

    struct Node* root = new Node(1);

    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(8);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);



    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);


    postorder(root);
    
}