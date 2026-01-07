#include<bits/stdc++.h>

#include "../node.h"
using namespace std;


vector<int> levelOrder(Node* root){
    
    if(root == nullptr)return {-1};
    queue<Node*>q;
    vector<int>ans;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();
        ans.push_back(temp->val);
        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }

    return ans;
}


int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);


    vector<int>ans = levelOrder(root);

    for(auto it:ans)cout<<it<<" ";
}