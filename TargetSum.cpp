#include<bits/stdc++.h>
using namespace std;
vector<int> targetSum(vector<int> nums,int target){
    int n=nums.size();
    vector<int> vec(2);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                vec[0]=i;
                vec[1]=j;
            }
        }
    }
    return vec;
}

int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    vector<int> nums(s);
    cout<<"enter values into the array and their must be such values which adds up results the target\n";
    for(int i=0;i<s;i++){
        cin>>nums[i];
    }
    cout<<"enter the targeted sum\n";
    int tar;
    cin>>tar;
    vector<int> ans = targetSum(nums,tar);
    cout<<"0 based indexes are \n";
    for(auto it:ans){
        cout<<it<<",";
    }
    return 0;
}
// output:
// enter the size of array
// 5
// enter values into the array and their must be such values which adds up results the target
// 2 8 4 5 2
// enter the taageted sum
// 12
// 0 based indexes are 
// 1,2,