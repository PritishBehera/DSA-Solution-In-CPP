#include<bits/stdc++.h>
using namespace std;
using ll= long long;
bool compare(pair<double,long long> p1, pair<double,long long> p2){
    return p1.first > p2.first;
}
double fractionalKnapsack(vector<ll>& val,vector<ll>& wt,int capacity){
    vector<pair<double,long long>> pairs;
    double ans=0;
    for(int i=0;i<wt.size();i++){
        pairs.push_back({(double)val[i]/wt[i],wt[i]});
    }
    sort(pairs.begin(),pairs.end(),compare);
    for(int i=0;i<pairs.size();i++){
        if(pairs[i].second <= capacity){
            capacity-= pairs[i].second;
            ans+= pairs[i].first*pairs[i].second;
        }else{
            ans+= pairs[i].first*capacity;
            break;
        }
    }
    return ans;
}
int main(){
    vector<long long> val = {60,100,120};
    vector<long long> wt = {10,20,30};
    int capacity = 50;
    double ans=fractionalKnapsack(val,wt,capacity);
    cout<<ans;
    return 0;
}