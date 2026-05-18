#include<bits/stdc++.h>
using namespace std;
int single(vector<int> &nums,int n){
    unordered_map<long long,int> find1;
    for(int i=0;i<n;i++){
        find1[nums[i]]++;
    }
    for(auto &it:find1){
        if(it.second==1){
            return it.first;
        }
    }
    return 0;
}
int method2(vector<int> &nums,int n){
    int a = 0;
    for(int i=0;i<n;i++){
        a=a^nums[i];
    }
    return a;
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
    int res = single(nums,s);
    cout<<"number with only 1 frequency is "<<res;
    return 0;
}
// Output:
// enter the size of array
// 5
// enter values into the array
// 2 2 5 6 6
// number with only 1 frequency is 5