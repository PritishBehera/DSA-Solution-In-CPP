#include<bits/stdc++.h>
using namespace std;

int rotatedBinarySearch(int nums[],int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[left]<=nums[mid]){
            if(target>=nums[left]&&target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }else{
            if(target>nums[mid]&&target<=nums[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    int arr[s];
    cout<<"enter values into the sorted rotated array\n";
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"enter the target to be searched\n";
    cin>>target;
    int res = rotatedBinarySearch(arr,s,target);
    cout<<"index of target is "<<res;
    return 0;
}
// Output:
// enter the size of array
// 7
// enter values into the sorted rotated array
// 4 5 6 7 0 1 2
// enter the target to be searched
// 0
// index of target is 4