#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    }
};
static int idx = -1;
Node* binaryTrees(vector<int>& nodesArr){
    idx++;
    if(nodesArr[idx]== -1){
        return NULL;
    }
    Node* node = new Node(nodesArr[idx]);
    node->left = binaryTrees(nodesArr);
    node->right = binaryTrees(nodesArr);
    return node;
}
void preorder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    //same can be written for inorder and postorder
    //these all are implementation of depth first search(dfs)
}
void levelOrder(Node* root){//traversal(BFS)
    if(root==NULL){
        return;
    }
    queue<Node*> qu;
    qu.push(root);
    qu.push(NULL);
    while(!qu.empty()){
        Node* curr=qu.front();
        qu.pop();
        if(curr==NULL){
            cout<<"\n";
            if(qu.empty()){
                break;
            }
            qu.push(NULL);
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
                qu.push(curr->left);
            }
            if(curr->right!=NULL){
                qu.push(curr->right);
            }
        }
    }
}
int kthLevelANC(Node*root, int k, int n,int&ans){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 1;
    }
    int leftC = kthLevelANC(root->left,k,n,ans);
    if(leftC!=-1){
        if(leftC==k){
            ans = root->data;
        }
        return leftC+1;
    }
    int rightC = kthLevelANC(root->right,k,n,ans);
    if(rightC!=-1){
        if(rightC==k){
            ans = root->data;
        }
        return rightC+1;
    }
    return leftC==-1?rightC:leftC;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    levelOrder(root);
    int k=1,n1=6;
    int ans= -1;
    kthLevelANC(root,k,n1,ans);
    cout<<k<<"th level ancestor for "<<n1<<" is: "<<ans;
    return 0;
}