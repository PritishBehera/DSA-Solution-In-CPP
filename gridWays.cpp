#include<bits/stdc++.h>
using namespace std;

int gridWays(int r,int c,int n,int m){
    //base
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    //kaam
    int val1 = gridWays(r,c+1,n,m);
    int val2 = gridWays(r+1,c,n,m);
    return val1 + val2;
}
int main(){
    int n=5,m=5;//nxm,n=no. of rows,m=no. of cols
    int ans=gridWays(0,0,n,m);
    cout<<ans;
    return 0;
}