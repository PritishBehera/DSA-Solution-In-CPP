#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums, int k) {
        int s= nums.size();
        k=s-k;
        while(k>0){
            int f=nums[0];
            for(int i=1;i<s;i++){
                nums[i-1]=nums[i];
            }
            nums[s-1]=f;
            k--;
        }
        cout<<"final values are:";
        for(auto it:nums){
            cout<<it<<" ";
        }
    }
int main(){
    vector<int> nums;
    int n;
    cout<<"enter the no. of values of array:";
    cin>>n;
    cout<<"enter values:";
    while(n>0){
        int x=0;
        cin>>x;
        nums.emplace_back(x);
    n--;
    }
    int k;
    cout<<"enter the rotate times:";
    cin>>k;
    rotate(nums,k);
    return 0;
}
// Output:
// enter the no. of values of array:5
// enter values:1 2 3 4 5
// enter the rotate times:3
// final values are:3 4 5 1 2