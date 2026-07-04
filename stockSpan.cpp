#include<bits/stdc++.h>
using namespace std;
void maxStockSpan(vector<int>&stock,vector<int>&span){
    stack<int> s;
    for(int i=0;i<stock.size();i++){
        while(!s.empty() && stock[i]>=stock[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span.push_back(i+1);
        }else{
            span.push_back(i-s.top());
        }
        s.push(i);
    }
}
int main(){
    vector<int> stock={100,80,60,70,60,85,100};
    vector<int> span;
    maxStockSpan(stock,span);
    for(auto it: span){
        cout<<it<<" ";
    }
    return 0;
}