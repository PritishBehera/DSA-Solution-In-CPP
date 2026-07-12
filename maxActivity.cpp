#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}
void sortingEnd(vector<pair<int,int>>&pairs){
    sort(pairs.begin(),pairs.end(),compare);
}
int maxActivity(vector<int>&start,vector<int>&end){
    //end must be sorted
    vector<pair<int,int>> pairs;
    for(int i=0;i<start.size();i++){
        pairs.push_back({start[i],end[i]});
    }
    sortingEnd(pairs);
    //select start[0]
    int count=1;
    cout<<"A0"<<"\n";
    int currEndTime=pairs[0].second;
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first>=currEndTime){
            cout<<"A"<<i<<"\n";
            count++;
            currEndTime=pairs[i].second;
        }
    }
    return count;
}
int main(){
    vector<int>start={1,8,5,0,3,5};
    vector<int>end={2,9,7,6,4,9};
    cout<<maxActivity(start,end);
    return 0;
}