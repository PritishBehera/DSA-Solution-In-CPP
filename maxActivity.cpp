#include<bits/stdc++.h>
using namespace std;
int maxActivity(vector<int>start,vector<int>end){
    //end must be sorted
    //select start[0]
    int count=1;
    cout<<"A0"<<"\n";
    int currEndTime=end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEndTime){
            cout<<"A"<<i<<"\n";
            count++;
            currEndTime=end[i];
        }
    }
    return count;
}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};
    cout<<maxActivity(start,end);
    return 0;
}