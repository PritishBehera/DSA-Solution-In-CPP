#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

Node* sorted2BST(vector<int>&vec,int st, int en){
    //base
    if(st>en){
        return NULL;
    }
    int mid=(st+en)/2;
    Node* root = new Node(vec[mid]);
    root->left = sorted2BST(vec,st,mid-1);
    root->right = sorted2BST(vec,mid+1,en);

    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void getInorder(Node* root,vector<int>&vec){
    if(root==NULL){
        return;
    }
    getInorder(root->left,vec);
    vec.push_back(root->val);
    getInorder(root->right,vec);
}

void merge2BST(Node* root1,Node* root2){
    vector<int> vec;
    vector<int> vec2;
    getInorder(root1,vec);
    getInorder(root2,vec2);
    vector<int> vec3;
    int i=0,j=0;
    while(i<vec.size()&&j<vec2.size()){
        if(vec[i]<=vec2[j]){
            vec3.push_back(vec[i]);
            i++;
        }else{
            vec3.push_back(vec2[j]);
            j++;
        }
    }
    while(i<vec.size()){
        vec3.push_back(vec[i]);
        i++;
    }
    while(j<vec2.size()){
        vec3.push_back(vec2[j]);
        j++;
    }
    Node* newRoot = sorted2BST(vec3,0,(vec3.size()-1));
    preorder(newRoot);
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    merge2BST(root1,root2);
    return 0;
}