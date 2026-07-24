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
bool identical(Node* root, Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }else if(root == NULL || subroot == NULL){
        return false;
    }
    if(root->data!=subroot->data){
        return false;
    }
    if(identical(root->left,subroot->left)){
        return identical(root->right,subroot->right);
    }
    return true;
}
bool subrootTrees(Node* root, Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }else if(root == NULL || subroot == NULL){
        return false;
    }
    if(root->data == subroot-> data){
        //identicals check
        if(identical(root,subroot)){
            return true;
        }
    }
    bool leftSubT = subrootTrees(root->left,subroot);
    if(!leftSubT){
        return subrootTrees(root->right,subroot);
    }
    return true;
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    Node* subroot= new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(5);
    cout<<subrootTrees(root,subroot);
}