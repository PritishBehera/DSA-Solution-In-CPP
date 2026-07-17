#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second > p2.second;
}
void maxProfit(vector<int>&deadLine,vector<int>&profit){
    vector<pair<int,int>> pairs;
    for(int i=0;i<profit.size();i++){
        pairs.push_back({deadLine[i],profit[i]});
    }
    sort(pairs.begin(),pairs.end(),compare);
    int maxProfit=pairs[0].second;
    int lastDate=2;
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first >= lastDate){
            maxProfit += pairs[i].second;
            lastDate++;
        }
    }
    cout<<maxProfit;
}
int main(){
    vector<int> deadLine={4,1,1,1};
    vector<int> profit={20,10,40,30};
    maxProfit(deadLine,profit);
    return 0;
}