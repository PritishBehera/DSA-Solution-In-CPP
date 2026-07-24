#include<bits/stdc++.h>
using namespace std;
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

void topViewTree(Node* root,map<int,int>&mp){
    if(root==NULL){
        return;
    }
    int tr=0;
    queue<pair<Node*,int>> qu;
    qu.push({root,tr});
    while(!qu.empty()){
        Node* curr =qu.front().first;
        int trc =qu.front().second;
        qu.pop();
        //logic
        if(mp.count(trc)==0){
            mp[trc]=curr->data;
        }
        if(curr->left!=NULL){
            qu.push({curr->left,trc-1});
        }
        if(curr->right!=NULL){
            qu.push({curr->right,trc+1});
        }
    }
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = binaryTrees(nodes);
    map<int,int> mp;
    topViewTree(root,mp);
    for(auto it: mp){
        cout<< it.second<<" ";
    }
    return 0;
}