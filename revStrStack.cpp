#include<bits/stdc++.h>
using namespace std;
string revString(string&str){
    stack<char> s;
    for(char it :str){
        s.push(it);
    }
    string ans;
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str="abcd";
    string ans=revString(str);
    cout<<ans;
    return 0;
}