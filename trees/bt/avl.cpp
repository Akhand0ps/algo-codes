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
        left=right=nullptr;
        height = 0;
    }    
};


int height(Node* node){
    if(node==nullptr){
        return -1;
    }
    return node->height;
}

Node* rightRotate(Node* p){

    Node* c = p->left;
    Node* t2 = c->right;

    c->right = p;
    p->left = t2;

    p->height = max(height(p->left),height(p->right)) +1;
    c->height = max(height(c->left),height(c->right)) +1;
    //ye sb krne ke baad ke new node C hogi.
    return c;
}

Node* leftRotate(Node* c){
    Node* g = c->right;
    Node* t2 = g->left;
    
    g->left = c;
    c->right = t2;

    c->height = max(height(c->left),height(c->right)) +1;
    g->height = max(height(g->left),height(g->right)) +1;

    return g; 
}

Node* rotate(Node* node){

     //left heavy
    if(height(node->left) - height(node->right) >1){
        
        if(height(node->left->left) - height(node->left->right) > 1){

            //left-left case
            return rightRotate(node);
        }
        
        if(height(node->left->left) - height(node->left->right) < 0){
            //left-right case;

            //first left rotate on child
            node->left = leftRotate(node->left);
            //now current node pe right rotate;
            return rightRotate(node);
        }
    }
    //right heavy
    if(height(node->left) - height(node->right) < -1){
        
        if(height(node->right->left) - height(node->right->right) < 0){

            //left-left case
            return leftRotate(node);
        }
        
        if(height(node->right->left) - height(node->right->right) > 0    ){
            //left-right case;

            //first left rotate on child
            node->right = rightRotate(node->right);
            //now current node pe right rotate;
            return leftRotate(node);
        }
    }
    return node;
}


Node* insert(int value,Node* node){

    if(node == nullptr){
        return new Node(value);
    }
    if(node->val > value){
        node->left = insert(value,node->left);
    }

    if(node->val < value){
        node->right = insert(value,node->right);
    }

    node->height = max(height(node->left),height(node->right))+1;
    return rotate(node);
}

bool balanced(Node* node){
    if(node==nullptr){
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

int main(){
    
    // int rootVal;
    // cout<<"Enter root: ";

    Node* root = nullptr;
   vector<int>nums = {5,2,7,1,4,6,9,8,3,10};
   for(int i=0;i<nums.size();i++){
        root = insert(nums[i],root);
   }
   display(root,"this is root: ");


   cout<<"\n";

   cout<<"========================"<<"\n";
   cout<<"========================"<<"\n";
   cout<<"height verification - logn hi hota hai uska prove"<<"\n";

   Node* newRoot = nullptr;
   for(int i=0;i<1000;i++){
        newRoot = insert(i,newRoot);
   }

   cout<<"Height of tree: "<<height(newRoot)<<"\n";
    cout<<"========================";
   cout<<"========================";
}
