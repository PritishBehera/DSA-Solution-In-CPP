#include<bits/stdc++.h>
using namespace std;
 int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<long long, int> find1;
    for(auto it:nums){
        find1[it]++;
        auto itr = find1.find(it);
        if(itr!=find1.end()){
            if(itr->second>(n/2)){
                return itr->first;
            }
        }
    }
    return -1;
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
    int res = majorityElement(nums);
    cout<<"majority element is "<<res;
    return 0;
}
// output:
// enter the size of array
// 6
// enter values into the array
// 3 4 5 3 3 3
// majority element is 3