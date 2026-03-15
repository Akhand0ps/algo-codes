#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root,int val){

    if(root == nullptr){
        return new Node(val);
    }

    if(root->val > val){
        root->left = insert(root->left,val);
    }
    if(root->val < val){
        root->right = insert(root->right,val);
    }

    return root;
}


void display(Node* node){

    if(node == nullptr)return;
    cout<<node->val<<" ";
    display(node->left);
    display(node->right);
}

void bfs(Node* root){

    if(!root)return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){

        auto node = q.front();
        q.pop();
        cout<<node->val<<" ";

        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }

}

void arraybfs(Node* root){

    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){

        int size = q.size(); //iss level pe kitne elment hai
        vector<int>level;

        while(size--){
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }

    for(auto it:ans){
        for(auto level:it){
            cout<<level<<" ";
        }
    }
}


void levelOrderSuccessorOfNode(Node* root,int key){

    if(root == nullptr)return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){

        auto node = q.front();
        q.pop();
        if(node->left)  q.push(node->left);
        if(node->right) q.push(node->right);

        if(node->val == key){
            break;
        }
    }

    cout<<"Successor of Node "<<key<<" is: "<<q.front()->val;

}


void zigzag(Node* root){

    if(root==nullptr)return;
    vector<vector<int>>zigzug;

    deque<Node*>dq;
    dq.push_back(root);
    bool flag = false;


    while(!dq.empty()){

        int size = dq.size();
        vector<int>level;

        for(int i=0;i<size;i++){
            if(flag == false){

                auto node = dq.front();
                dq.pop_front();

                level.push_back(node->val);

                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
            else{

                auto node = dq.back();
                dq.pop_back();
                level.push_back(node->val);

                if(node->right)dq.push_front(node->right);
                 if(node->left)dq.push_front(node->left);
            }
        }
        flag = !flag;
        zigzug.push_back(level);
    }

    cout<<"zig zag:"<<"\n";
    for(auto it:zigzug){

        for(auto z:it){
            cout<<z<<" ";
        }
        // cout<<"\n";
    }
}



int 
int main(){


    vector<int>num= {1,2,3,4,5,6,7};
    vector<int> nums = {4,2,6,1,3,5,7};

    Node* root = nullptr;

    for(int i=0;i<nums.size();i++){
        root = insert(root,nums[i]);
    }
    // display(root);
    // cout<<"\n";
    // bfs(root);
    // cout<<"\n";
    // arraybfs(root);
    // cout<<"\n";
    // levelOrderSuccessorOfNode(root,2);
    // cout<<"\n";


    Node* newRoot = new Node(1);
    newRoot->left = new Node(2);
    newRoot->left->left = new Node(4);
    newRoot->left->left->left = new Node(8);
    newRoot->left->left->right = new Node(9);
    newRoot->left->right = new Node(5);

    newRoot->right = new Node(3);
    newRoot->right->left = new Node(6);
    newRoot->right->left->left = new Node(10);
    newRoot->right->left->right = new Node(11);
    newRoot->right->right = new Node(7);




    zigzag(newRoot);

}