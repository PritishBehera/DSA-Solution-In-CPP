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
int sumTree(Node*root){
    if(root==NULL){
        return 0;
    }
    int leftS = sumTree(root->left);
    int rightS = sumTree(root->right);
    if(leftS==0 && rightS==0){
        int nValue = root->data;
        root->data=leftS+rightS;
        return nValue;
    }
    int nValue = root->data;
    root->data=leftS+rightS;
    return root->data+nValue;
    
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    levelOrder(root);
    sumTree(root);
    cout<<"transforming into sum tree:\n";
    levelOrder(root);
    return 0;
}