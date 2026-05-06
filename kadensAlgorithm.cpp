#include<bits/stdc++.h>
using namespace std;
int kadensWay(int arr[],int n){//time complexity:O(n)-linear time complexuty
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        maxSum=max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
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
    int res = kadensWay(arr,s);
    cout<<"max sub array is:"<<res;
    return 0;
}
// Output:
// enter the size of array
// 6
// enter values into the array
// 2 3 -5 -2 4 5
// max sub array is:9