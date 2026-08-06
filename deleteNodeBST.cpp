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
int inorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    int va = root->data;
    delete root;
    return va;
}
Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }else if(val > root->data){
        root->right = deleteNode(root->right,val);
    }else{
        //root==val
        //case=0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //case=1 child
        if(root->left==NULL){
            Node* temp= root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            Node* temp= root->left;
            delete root;
            return temp;
        }
        //case=2 child
        Node *successor = root->right;
        while(successor->left!=NULL){
            successor=successor->left;
        }
        root->data=successor->data;
        root->right=deleteNode(root->right,successor->data);
    }
}
int main(){
    int n=6;
    int arr[]={3,5,2,1,7,4};
    Node* root = buildBST(arr,n);
    levelOrder(root);
    deleteNode(root,3);
    cout<<"after deleting the node";
    levelOrder(root);
    return 0;
}