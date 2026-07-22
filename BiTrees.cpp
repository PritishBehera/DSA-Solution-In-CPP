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
void levelOrder(Node* root){
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
int heightT(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftH= heightT(root->left);
    int rightH= heightT(root->right);
    return max(leftH,rightH)+1;
}
int countN(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftC= countN(root->left);
    int rightC= countN(root->right);
    return leftC + rightC + 1;
}
int sumOfN(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftS = sumOfN(root->left);
    int rightS = sumOfN(root->right);
    int val = leftS + rightS + root->data;
    return val;
}
int diameterT(Node*root,int&maxDia){
    if(root==NULL){
        return 0;
    }
    int leftD = diameterT(root->left,maxDia);
    int rightD = diameterT(root->right,maxDia);
    
    maxDia = max(leftD + rightD + 1,maxDia);
    return max(leftD ,rightD) + 1;
}
int main(){
    vector<int> nodes={1,2,4,9,10,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root = binaryTrees(nodes);
    // preorder(root);
    // levelOrder(root);
    // cout<<heightT(root)<<"\n";
    // cout<<countN(root);
    // cout<<sumOfN(root);
    int maxDia = INT_MIN;
    diameterT(root,maxDia);
    cout<<maxDia;
    return 0;
}