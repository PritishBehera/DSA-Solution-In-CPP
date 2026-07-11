#include<bits/stdc++.h>
using namespace std;
void reverseByKindex(queue<int>&qu,int k){
    stack<int> st;
    int n=qu.size();
    for(int i=0;i<k&&!qu.empty();i++){
        st.push(qu.front());
        qu.pop();
    }
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
    for(int i=0;i<(n-k)&&!qu.empty();i++){
        int val=qu.front();
        qu.pop();
        qu.push(val);
    }
    return;
}
int main(){
    int k=3;
    queue<int> qu;
    for(int i=1;i<6;i++){
        qu.push(i);
    }
    reverseByKindex(qu,k);
    //printing queue
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}