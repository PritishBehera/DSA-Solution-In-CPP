#include<bits/stdc++.h>
using namespace std;


void ratWays(int i,int j,int n,vector<vector<int>>&mat,vector<string>&ans,string moves,vector<vector<int>>& vis){
    if(i==n-1&&j==n-1){
        ans.push_back(moves);
        return ;
    }
    //down
    if(i+1<n&& !vis[i+1][j] && mat[i+1][j]==1){
        vis[i][j]=1;
        ratWays(i+1,j,n,mat,ans,moves+'D',vis);
        vis[i][j]=0;
    }
    //left
    if(j-1>=0&& !vis[i][j-1] && mat[i][j-1]==1){
        vis[i][j]=1;
        ratWays(i,j-1,n,mat,ans,moves+'L',vis);
        vis[i][j]=0;
    }
    //right
    if(j+1<n&& !vis[i][j+1] && mat[i][j+1]==1){
        vis[i][j]=1;
        ratWays(i,j+1,n,mat,ans,moves+'R',vis);
        vis[i][j]=0;
    }
    //up
    if(i-1>=0&& !vis[i-1][j] &&mat[i-1][j]==1){
        vis[i][j]=1;
        ratWays(i-1,j,n,mat,ans,moves+'U',vis);
        vis[i][j]=0;
    }
}

int main(){
    vector<vector<int>> mat={{1,0,0,0},
                            {1,1,0,1},
                            {1,1,0,0},
                            {0,1,1,1}};//nxn
    int n=4;
    vector<string> ans;
    vector<vector<int>> vis(4,vector<int>(4,0));
    ratWays(0,0,n,mat,ans,"",vis);
    for(auto it:ans){ cout<<it<<"\n";}
    return 0;
}
// o/p:
// DDRDRR
// DRDDRR