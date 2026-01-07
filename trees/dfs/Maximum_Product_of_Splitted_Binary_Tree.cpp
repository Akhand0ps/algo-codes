#include<bits/stdc++.h>

#include "../node.h"

using namespace std;


long long ans = 0;
long long total = 0;
long long MOD = 1e9+7;

int postorder(Node* root){

    if(!root) return 0;
    int leftsum = postorder(root->left);
    int rightsum = postorder(root->right);

    int subtreesum = root->val + leftsum + rightsum;
    ans = max(ans,1LL* subtreesum * (total-subtreesum));
    return subtreesum;
}
int maxProduct(Node* root) {
    
    total = postorder(root); //pehele total sum calculate krle
    
    postorder(root); //ab maxproduct compute kr

    return ans % MOD;
}



int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);


    cout<<maxProduct(root);




}