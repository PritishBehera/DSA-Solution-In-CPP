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


void printInRange(Node*root,int &st,int &en){
    if(root==NULL){
        return;
    }
    if(root->data >= st && root->data <= en){
        cout<<root->data <<" ";
    }
    if(root->data >= st){
        printInRange(root->left,st,en);
    }
    if(root->data <= en){
        printInRange(root->right,st,en );
    }
}
int main(){
    int n=6;
    int arr[]={8,5,10,11,3,6,1,4,14};
    Node* root = buildBST(arr,n);
    levelOrder(root);
    int st=5, en=12;
    cout<<"the nodes within the RANGE are:";
    printInRange(root,st,en);
    return 0;
}