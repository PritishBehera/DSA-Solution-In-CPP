#include<bits/stdc++.h>
using namespace std;
int maxSubArray(int arr[],int n){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int currSum=0;
            for(int k=i;k<=j;k++){
                currSum+=arr[k];
            }
            maxSum=max(currSum,maxSum);
        }
    }
    return maxSum;
}
int main(){
    int arr[]={2,3,-5,-2,4,5};
    int res = maxSubArray(arr,sizeof(arr)/sizeof(int));
    cout<<"max sub array is:"<<res;
    return 0;
}