#include<bits/stdc++.h>
using namespace std;


struct Node{

    int val;
    struct Node* left;
    struct Node* right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

void display(Node* root){
    if(root == nullptr)return;

    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

void insert(Node* node){

    cout<<"Do you want to insert left of node "<<node->val<<": ";
    bool left;
    cin>>left;
    if(left){
        int leftval;
        cout<<"Enter the left value of Node "<<node->val<<": ";
        cin>>leftval;
        Node* leftNode = new Node(leftval);
        node->left = leftNode;
        insert(leftNode);
    }
   cout<<"Do you want to insert right of node "<<node->val<<": ";
    bool right;
    cin>>right;
    if(right){
        int rightval;
        cout<<"Enter the right value of Node "<<node->val<<": ";
        cin>>rightval;
        Node* rightNode = new Node(rightval);
        node->right = rightNode;
        insert(rightNode);
    }
}


int main(){

    int rootVal;
    cout<<"Enter root value: ";
    cin>>rootVal;
    struct Node* root = new Node(rootVal);
    insert(root);

    display(root);
     
}


/* 

Enter root value: 15
Do you want to enter left of 15: 1  
Enter the left value of 15: 6
Do you want to enter left of 6: 1
Enter the left value of 6: 8    
Do you want to enter left of 8: 0
Do you want to enter the right of 8: 1
Enter the right value of 8: 10
Do you want to enter left of 10: 0
Do you want to enter the right of 10: 0
Do you want to enter the right of 6: 1
Enter the right value of 6: 14
Do you want to enter left of 14: 0
Do you want to enter the right of 14: 0
Do you want to enter the right of 15: 1
Enter the right value of 15: 9
Do you want to enter left of 9: 0
Do you want to enter the right of 9: 0

*/