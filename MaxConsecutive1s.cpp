#include<bits/stdc++.h>
using namespace std;
//if you  interest in any numbers frequency then just change 1 to that number nad update the size of freq vector to that number
int max1s(vector<int> nums,int n){
    vector<int> freq(2);
    int maxFq=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            freq[1]++;
        }else{
            maxFq=max(maxFq,freq[1]);
            freq[1]=0;
        }
    }
    maxFq=max(maxFq,freq[1]);
    return maxFq;
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
    int res = max1s(nums,s);
    cout<<"maximum no. of 1's is "<<res;
    return 0;
}
// Output:
// enter the size of array
// 6
// enter values into the array
// 1 1 0 1 1 1
// maximum no. of 1's is 3