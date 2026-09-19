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

class info{
public:
    bool isBST;
    int max;
    int min;
    int size;
    info(bool isBST, int max, int min, int size){
        this->isBST=isBST;
        this->max=max;
        this->min=min;
        this->size=size;
    }
};

static int mxSize;

info* largestBST(Node* root){
    //base
    if(root==NULL){
        return new info(true,INT_MIN,INT_MAX,0);
    }
    info* leftInfo = largestBST(root->left);
    info* rightInfo = largestBST(root->right);

    int mx = max(root->data,max(leftInfo->max,rightInfo->max));
    int mn = min(root->data,min(leftInfo->min,rightInfo->min));
    int sz = leftInfo->size + rightInfo->size + 1;

    if(root->data > leftInfo->max && root->data < rightInfo->min 
        && leftInfo->isBST && rightInfo->isBST ){
            mxSize = max(mxSize,sz);
            return new info(true,mx,mn,sz);
        }
        else{
            return new info(false,mx,mn,sz);
        }
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    largestBST(root);
    cout<<"largest BST is:"<< mxSize;

    return 0;
}