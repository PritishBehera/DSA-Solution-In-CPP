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
void getInorder(Node*root,vector<int>&vec){
    if(root==NULL){
        return;
    }
    getInorder(root->left,vec);
    vec.push_back(root->data);
    getInorder(root->right,vec);
}
Node* sortedArr2BST(vector<int>&vec,int st,int en){
    if(st>en){
        return NULL;
    }
    int mid=(st+en)/2;
    Node* root = new Node(vec[mid]);
    root->left = sortedArr2BST(vec,st,mid-1);
    root->right = sortedArr2BST(vec,mid+1,en);
    return root;
}
Node* formBalancedBST(Node* root){
    vector<int> vec;
    getInorder(root,vec);
    root = sortedArr2BST(vec,0,vec.size()-1);
    return root;
}
int main(){
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    cout<<"binary search tree:\n";
    levelOrder(root);
    
    root = formBalancedBST(root);
    cout<<"balanced binary search tree:\n";
    levelOrder(root);
    return 0;
}