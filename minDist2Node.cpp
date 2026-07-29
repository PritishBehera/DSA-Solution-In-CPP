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
Node* lca(Node*root,int n1,int n2){//assuming that nodes are unique
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftN = lca(root->left,n1,n2);
    Node* rightN = lca(root->right,n1,n2);
    if(leftN!=NULL && rightN!=NULL){
        return root;
    }
    return leftN==NULL?rightN:leftN;
}
int distance(Node* lcaN,int n){
    if(lcaN==NULL){
        return -1;
    }
    if(lcaN->data==n){
        return 0;
    }
    int leftD = distance(lcaN->left,n);
    if(leftD!=-1){
        return leftD+1;
    }
    int rightD = distance(lcaN->right,n);
    if(rightD!=-1){
        return rightD+1;
    }
    return -1;
}
int minDistance(Node* root,int n1,int n2){
    if(root==NULL){
        return -1;
    }
    Node* lcaN = lca(root,n1,n2);
    int D1= distance(lcaN,n1);
    int D2= distance(lcaN,n2);
    return D1+D2;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    levelOrder(root);
    int n1=4,n2=6;
    cout<<"min distance: "<<minDistance(root,n1,n2);
    return 0;
}