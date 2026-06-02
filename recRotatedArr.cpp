#include<bits/stdc++.h>
using namespace std;

int sort(int arr[],int st, int en, int tar){
    if(st>en) return -1;
    int mid =st+(en-st)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[st]<arr[mid]){
        if(arr[st]<=tar && tar<arr[mid]){
            return sort(arr,st,mid-1,tar);
        }else{
            return sort(arr,mid+1,en,tar);
        }
    }else{
        if(arr[mid]<tar&& tar<=arr[en]){
            return sort(arr,mid+1,en,tar);
        }else{
            return sort(arr,st,mid-1,tar);
        }
    }
}
int main(){
    int arr[]={4,5,7,1,2,3};
    int tar = 2;
    int n= sizeof(arr)/sizeof(int);
    int res = sort(arr,0,n-1,tar);
    cout<<"index: "<<res;
    return 0;
}