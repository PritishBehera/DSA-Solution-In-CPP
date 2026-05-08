#include<bits/stdc++.h>
using namespace std;

void buySell(int arr[],int n){
    int bestBuy[100000];
    bestBuy[0]=INT_MAX;
    int maxProf=0;
    for(int i=0;i<n;i++){
        if(i!=0){
            bestBuy[i]=min(arr[i-1],bestBuy[i-1]);
        }
        int currProf=arr[i]-bestBuy[i];
        maxProf=max(currProf,maxProf);
    }

    if(maxProf>0){
        cout<<"Max Profit is "<<maxProf;
    }
    else{
        cout<<"No Profit";
    }
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
    buySell(arr,s);
    return 0;
}
// Output:
// enter the size of array
// 6
// enter values into the array
// 7 1 5 3 6 4
// Max profit is 5 7