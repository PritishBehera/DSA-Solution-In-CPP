#include<bits/stdc++.h>
using namespace std;
void solve(int i,string curr,vector<string>&ans,unordered_map<char,string>mp,string dig,int n){
    //base case
    if(i==n){
        ans.push_back(curr);
        return;
    }
    //kaam
    string str=mp[dig[i]];
    //recursive call
    for(char ch:str){
        solve(i+1,curr+ch,ans,mp,dig,n);
    }
}
int main(){
    string dig;
    cout<<"enter number of digit can be size of any but must from 2 to 9:";
    cin>>dig;
    unordered_map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans;
    solve(0,"",ans,mp,dig,dig.size());
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
// o/p:
// enter number of digit can be size of any but must from 2 to 9:23
// ad ae af bd be bf cd ce cf 