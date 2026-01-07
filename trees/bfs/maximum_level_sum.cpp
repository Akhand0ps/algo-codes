#include<bits/stdc++.h>

#include "../node.h"
using namespace std;


int levelOrder(Node* root){
    
    if(root == nullptr)return {-1};
    queue<Node*>q;
    vector<int>ans;
    q.push(root);

    int maxlevel=0;
    int max_sum = INT_MIN;

    int level = 1;


    while(!q.empty()){

        int levelSize = q.size();
        int sum =0;


        while(levelSize--){
            Node* curr = q.front();
            q.pop();

            sum += curr->val;
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }


        if(sum > max_sum){
            max_sum = sum;
            maxlevel = level;
        }

        level++;
    }

    return maxlevel;
}


int main(){

    struct Node* root = new Node(1);

    root->left = new Node(7);
    root->right = new Node(0);
    root->left->left = new Node(7);
    root->left->right = new Node(-8);


    int ans = levelOrder(root);
    cout<<ans;
}