#include<bits/stdc++.h>
using namespace std;
//this search algorithm only works for row and col wise sorted matrix
void search(int mat[][4],int n,int m,int key){//top right corner element taken as comparing element
    int srow=0,ecol=m-1;
    while(srow<n&&ecol>=0){
        if(mat[srow][ecol]==key){
            cout<<key<<" found at ("<<srow<<","<<ecol<<") index.\n";
            return;
        }
        if(key>mat[srow][ecol]){
            srow++;
        }else if(key<mat[srow][ecol]){
            ecol--;
        }
    }
    cout<<key<<" doesn't exist in the matrix.";
}

void search2(int mat[][4],int n,int m, int key){//bottom left corner element taken as comparing element
    int erow=n-1,scol=0;
    while(erow>=0&&scol<m){
        if(mat[erow][scol]==key){
            cout<<key<<" found at ("<<erow<<","<<scol<<") index\n";
            return;
        }
        if(key<mat[erow][scol]){
            erow--;
        }else if(key>mat[erow][scol]){
            scol++;
        }
    }
    cout<<key<<" doesn't exist in the matrix";
}

int main(){
    int mat[4][4]={{12,14,17,21},
                    {13,18,20,23},
                    {15,19,22,25},
                    {19,23,25,27}};
    
    int key;
    cout<<"enter item to be searched\n";
    cin>>key;
    search2(mat,4,4,key);
    return 0;
}
// Output:
// enter item to be searched
// 25
// item found at (2,3) index.