#include<bits/stdc++.h>
using namespace std;

void spiral(int arr[][4],int n,int m){//provide explicitely 2nd dimennsion of array
    int srow=0,erow=n-1,scol=0,ecol=m-1;
    cout<<"Spiral Print will be \n";
    while(srow<=erow&&scol<=ecol){
        //top
        for(int j=scol;j<=ecol;j++){
            cout<<arr[srow][j]<<" ";
        }
        for(int i=srow+1;i<=erow;i++){
            cout<<arr[i][ecol]<<" ";
        }
        for(int j=ecol-1;j>=scol;j--){
            cout<<arr[erow][j]<<" ";
        }
        for(int i=erow-1;i>=srow+1;i--){
            cout<<arr[i][scol]<<" ";
        }
        scol++,srow++,erow--,ecol--;
    }
}

int main(){
    int n,m=4;
    cout<<"enter the size of row\n";
    cin>>n;
    cout<<"enter values into matrix\n";
    int arr[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    spiral(arr,n,m);
    return 0;
}
// Output:
// enter the size of row
// 4
// enter values into matrix
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// Spiral Print will be 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10