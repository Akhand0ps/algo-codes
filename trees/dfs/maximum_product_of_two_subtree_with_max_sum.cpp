#include<bits/stdc++.h>
#include "../node.h"
using namespace std;


int postorder(Node* root,int &firstMax,int &secondMax){

    if(!root) return 0;
    int leftsum = postorder(root->left,firstMax,secondMax);
    int rightsum = postorder(root->right,firstMax,secondMax);

    int subtreesum = root->val + leftsum + rightsum;
    if(subtreesum > firstMax){    
        secondMax = firstMax;
        firstMax = subtreesum;
    }

    else if(subtreesum > secondMax){
        secondMax = subtreesum;
    }

    return subtreesum;
}
int maxProduct(Node* root) { 
    const  int MOD = 1e9+7;
    int firstMax = INT_MIN;
    int secMax = INT_MIN;

    int a =  postorder(root,firstMax,secMax);
    cout<<firstMax<<" "<<secMax<<"\n";
    int product = firstMax * secMax;
    cout<<product<<" ";
    return product % MOD;
}


int main(){



}