#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

void absDiff4K(Node* root, int& k, int& absDiff,int& ans){
    if(root==NULL){
        return;
    }
    int diff = abs(k-root->val);
    if(diff < absDiff){
        ans = root->val;
        absDiff =  diff;
    }
    absDiff4K(root->left,k,absDiff,ans);
    absDiff4K(root->right,k,absDiff,ans);
}

void absoluteDiff(Node* root,int k){
    int absDiff = INT_MAX;
    int ans;
    absDiff4K(root,k,absDiff,ans);
    cout<<"Absolute Diffrence is :"<<absDiff<<" for node "<< ans;
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    absoluteDiff(root,19);
    return 0;
}