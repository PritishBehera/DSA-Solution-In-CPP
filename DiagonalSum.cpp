#include<bits/stdc++.h>
using namespace std;
//diagonal sum only works for nXm matrix where n=m
void diagonalSum(int mat[][4],int n){//change 2nd dimension according to matrix size
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=mat[i][i];
        sum+=mat[i][n-i-1];
    }
    if(n%2!=0){
        sum-=mat[(n-1)/2][(n-1)/2];
    }
    cout<<"Diagonal Sum is "<<sum;
}
void diagonalSum2(int mat[][4],int n,int m){//another method wiht O(n2) time complexity
    int sum =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=mat[i][j];
            }else if(j==n-i-1){
                sum+=mat[i][j];
            }
        }
    }
    cout<<" Diagonal sum is "<<sum;
}
int main(){
    int mat[4][4]={{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
    int mat2[3][3]={{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    diagonalSum(mat,4);
    // diagonalSum(mat2,3);
    return 0;
}