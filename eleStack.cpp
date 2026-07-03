#include<bits/stdc++.h>
using namespace std;
void placeBottom(int val,stack<int>&s){
    if(s.empty()){
        s.push(val);
        return;
    }
    int tp=s.top();
    s.pop();
    placeBottom(val,s);
    s.push(tp);
    return;
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    int val=1;
    placeBottom(val,s);
    while(!s.empty()){
        int tp=s.top();
        cout<<tp<<" ";
        s.pop();
    }
    return 0;
}