#include<bits/stdc++.h>
using namespace std;
void reverseQ(queue<int>&qu){
    stack<int> st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int> qu;
    for(int i=0;i<10;i++){
        qu.push(i);
    }
    reverseQ(qu);
    while(!qu.empty()){//printing reversed queue
        cout<<qu.front()<<" ";
        qu.pop();
    }
}