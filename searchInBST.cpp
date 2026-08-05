#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insert(int val,Node* root){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(val,root->left);
    }else if(val > root->data){
        root->right = insert(val,root->right);
    }
    return root;
}
Node* buildBST(int arr[],int n){
    Node* root = NULL;
    for(int i=0;i<=n-1;i++){
        root = insert(arr[i],root);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
bool searchInBST(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(key==root->data){
        return true;
    }
    if(key < root->data){
        return searchInBST(root->left,key);
    }else{
        return searchInBST(root->right,key);
    }
    return false;
}
int main(){
    int n=6;
    int arr[]={3,5,2,1,7,4};
    Node* root = buildBST(arr,n);
    // levelOrder(root);
    // inorder(root);
    cout<<searchInBST(root,9);
    return 0;
}