#include<bits/stdc++.h>
using namespace std;
int product(int nums[],int n){
    int maxProd = INT_MIN;
    for(int i=0;i<n;i++){
        int currProd = 1;
        for(int j=i;j<n;j++){
            currProd = nums[j]*currProd;
            maxProd = max(maxProd,currProd);
        }
    }
    return maxProd;
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
    int res = product(arr,s);
    cout<<"max product of sub array is "<<res;
    return 0;
}
// Output:
// enter the size of array
// 4
// enter values into the array
// 2 3 -2 4
// max product of sub array is 6