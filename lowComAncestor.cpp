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
bool root2node(Node*root, int n, vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(n == root->data){
        return true;
    }
    int leftT = root2node(root->left,n,path);
    int rightT = root2node(root->right,n,path);
    if(leftT || rightT){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(Node* root,int n1, int n2){
    vector<int> path1;
    vector<int> path2;
    root2node(root,n1,path1);
    root2node(root,n2,path2);
    int lca=-1;
    for(int i=0,j=0;i < path1.size() && j < path2.size(); i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    levelOrder(root);
    int n1=4,n2=6;
    cout<<"for node "<<n1<<" and "<<n2<<", lowest common ancestor is: "<<lca(root,n1,n2);
}