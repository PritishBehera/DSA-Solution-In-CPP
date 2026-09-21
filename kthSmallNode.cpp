#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void kthSmall(TreeNode* root, int &k,int &ans){
    if(root==NULL){
        return ;
    }
    if(ans !=-1){
        return;
    }
    kthSmall(root->left,k,ans);
    k=k-1;
    if(k==0 && ans ==-1){
        ans = root->val;
        return ;
    }
    kthSmall(root->right,k,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    kthSmall(root,k,ans);
    if(ans < 0){
        return -1;
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);

    root->right = new TreeNode(60);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);

    int ans = kthSmallest(root,3);
    cout<<"kth smallest in the given BST is:"<< ans;
    return 0;
}