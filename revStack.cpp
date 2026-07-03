#include<bits/stdc++.h>
using namespace std;
void botPlace(int val,stack<int>&s){
    if(s.empty()){
        s.push(val);
        return;
    }
    int tp=s.top();
    s.pop();
    botPlace(val,s);
    s.push(tp);
}
void revStack(stack<int>&s){
    //base
    if(s.empty()){
        return;
    }
    //recursive call
    int val= s.top();
    s.pop();
    revStack(s);
    botPlace(val,s);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    revStack(s);
    while(!s.empty()){
        int tp=s.top();
        cout<<tp<<" ";
        s.pop();
    }
    return 0;
}