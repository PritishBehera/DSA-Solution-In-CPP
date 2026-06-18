#include<bits/stdc++.h>
using namespace std;
void solve(int i,int arr[],vector<int> curr,int n,vector<vector<int>>&ans){
    if(i==n){
        ans.push_back(curr);
        return ;
    }
    solve(i+1,arr,curr,n,ans);
    curr.push_back(arr[i]);
    solve(i+1,arr,curr,n,ans);
    curr.pop_back();
    

}
int main(){
    int arr[]={3,2,1};
    vector<vector<int>>ans;
    vector<int> curr;
    solve(0,arr,curr,3,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"\n";
    }
}