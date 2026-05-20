#include<bits/stdc++.h>
using namespace std;
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
void sort(vector<int> nums,int n){//bubble sort
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
    for(auto it: nums){
        cout<<it<<" ";
    }
}
void meth2(vector<int> nums,int n){
    vector<int> freq(3,0);
    for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;
    }
    int i=0;
    while(freq[0]!=0){
        nums[i]=0;
        i++;
        freq[0]--;
    }
    while(freq[1]!=0){
        nums[i]=1;
        i++;
        freq[1]--;
    }
    while(freq[2]!=0){
        nums[i]=2;
        i++;
        freq[2]--;
    }
    for(auto it: nums){
        cout<<it<<" ";
    }
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
    sort(nums,s);
    return 0;
}
// output:
// enter the size of array
// 5
// enter values into the array
// 2 1 0 2 1
// 0 1 1 2 2 