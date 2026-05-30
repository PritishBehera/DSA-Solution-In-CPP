#include<bits/stdc++.h>
using namespace std;

string removeCopy(string str,string ans, int i,auto &mp,int n){
    if(i==n){
        return ans;
    }
    if(!(mp.find(str.at(i))!=mp.end())){
        mp.insert({str.at(i),i});
        ans+=str.at(i);
    }
    return removeCopy(str,ans,i+1,mp,n);
}
int main(){
    string str = "appaarao";
    unordered_map<char,int> mp;
    string res = removeCopy(str,"",0,mp,str.length());
    cout<<res;
    return 0;
}
// o/p:apro