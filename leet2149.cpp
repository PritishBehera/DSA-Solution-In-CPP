//link for Question:https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &nums,int n){
    int k=0,l=1;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            vec[k]=nums[i];
            k+=2;
        }else{
            vec[l]=nums[i];
            l+=2;
        }
    }
    return vec;
}

int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    vector<int> nums(s);
    cout<<"enter values into the array\n";
    for(int i=0;i<s;i++){
        cin>>nums[i];
    }
    vector<int> res = rearrange(nums,s);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
// Output:
// enter the size of array
// 6
// enter values into the array
// 5 9 -3 6 -1 -4
// 5 -3 9 -1 6 -4 