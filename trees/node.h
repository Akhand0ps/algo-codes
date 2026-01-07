#ifndef NODE_H
#define NODE_H

struct Node
{
    /* data */

    int val;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        this->val = val;
        left=right=nullptr;
    }
};


#endif