#include<bits/stdc++.h>
using namespace std;
void interleave(queue<int>&qu){
    int n=qu.size();
    queue<int> secQ;
    for(int i=0;i<n/2;i++){
        secQ.push(qu.front());
        qu.pop();
    }
    while(!secQ.empty()){
        qu.push(secQ.front());
        secQ.pop();
        qu.push(qu.front());
        qu.pop();
    }
}
int main(){
    queue<int> qu;
    for(int i=1;i<=10;i++){
        qu.push(i);
    }
    interleave(qu);
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}