#include<bits/stdc++.h>
using namespace std;
int maxSumSubArray2(int arr[],int n){//time complexity:O(n2)
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=arr[j];
            maxSum=max(currSum,maxSum);
        }
    }
    return maxSum;
}
int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    int arr[s];
    cout<<"enter values into the array\n";
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    int res = maxSumSubArray2(arr,s);
    cout<<"max sub array is:"<<res;
    return 0;
}
// Output:
// enter the size of array
// 5
// enter values into the array
// 2 3 -5 -2 4
// max sub array is:5