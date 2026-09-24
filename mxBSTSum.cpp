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

class info{
public:
    bool isBST;
    int max;
    int min;
    int sum;
    info(bool isBST,int max,int min,int sum){
        this->isBST=isBST;
        this->max=max;
        this->min=min;
        this->sum=sum;
    }
};

int mxSum=0;
info helpFunc(TreeNode* root){
    if(root==NULL){
        return info(true,INT_MIN,INT_MAX,0);
    }
    info left= helpFunc(root->left);
    info right= helpFunc(root->right);

    int curMx=max({left.max,root->val,right.max});
    int curMn=min({right.min,root->val,left.min});
    int s=left.sum+right.sum+root->val;
    
    if( left.isBST && right.isBST &&  root->val > left.max && root->val < right.min){
        mxSum=max(mxSum,s);
        return info(true,curMx,curMn,s);
    }else{
        return info(false,curMx,curMn,s);
    }
}
int maxSumBST(TreeNode* root) {
    helpFunc(root);
    return mxSum;
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

    int ans = maxSumBST(root);
    cout<<ans;
    return 0;
}