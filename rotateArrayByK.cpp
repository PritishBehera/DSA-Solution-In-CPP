#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums, int k) {
        while(k>0){
            int j=0;
            for(int i=0;i<nums.size();i++){
                int f ;
                if(j==(nums.size()-1)){
                    j--;
                }
                if(j==0){
                    f = nums[i];
                }
                if(j+1==(nums.size()-1)){
                    nums[j+1]=f;
                }
                nums[j]=nums[j+1];
                j++;
            }
            k--;
        }
        for(auto it:nums){
            cout<<it<<" ";
        }
    }
int main(){
    vector<int> nums;
    int n;
    cout<<"enter the no. of values of array";
    cin>>n;
    cout<<"enter values;"
    while(n>0){
        int x=0;
        cin>>x;
        nums.emplace_back(x);
    n--;
    }
    int k;
    cout<<"enter the rotate times";
    cin>>k;
    rotate(nums,k);
    return 0;
}