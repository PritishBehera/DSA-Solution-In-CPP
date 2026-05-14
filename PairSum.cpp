#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int> nums,int tar){
    int st=0,en=nums.size()-1;
    int n=en;
    while(st<=n&&en>=0){
        int curSum=nums[st]+nums[en];
        if(curSum==tar){
            cout<<"index pair is {"<<st<<","<<en<<"}.";
            return;
        }
        if(curSum>tar){
            en--;
        }else
        {
            st++;
        }
        
    }
    cout<<"No such pair which matches the target.";
}

int main(){
    vector<int> num;
    int s;
    cout<<"enter the no. of values you want to insert into vector\n";
    cin>>s;
    cout<<"enter the values, remember their should be a such pair which matches with target\n";
    for(int i=0;i<s;i++){
        int x;
        cin>>x;
        num.emplace_back(x);
    }
    int tar;
    cout<<"enter the target to be matched with any pairs sum of the given vector\n";
    cin>>tar;
    pairSum(num,tar);
    return 0;
}
// Output:
// enter the no. of values you want to insert into vector
// 4
// enter the values, remember their should be a such pair which matches with target
// 2 7 11 15
// enter the target to be matched with any pairs sum of the given vector
// 13
// index pair is {0,2}.