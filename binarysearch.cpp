#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int start,int end,int ser){
    int mid=(start+end)/2;
    if(arr[mid]==ser){
        return mid;
    }
    else if(arr[mid]>ser){
        end=mid;
        binary(arr,start,end,ser);
    }
    else if(arr[mid]<ser){
        start=mid+1;
        binary(arr,start,end,ser);
    }else{
        return -1;
    }
}
int main(){
    int n;
    cout<<"enter the size if array\n";
    cin>>n;
    int arr[n];
    cout<<"enter the values into array in sorted manner\n";
    for(int it=0;it<n;it++){
        cin>>arr[it];
    }
    int ser;
    cout<<"enter the value of serching item\n";
    cin >>ser;
    int res= binary(arr,0,n-1,ser);
    if(res==-1){
        cout<<ser<<" it doesn't exist in the given array";
    }
    else{
        cout<<ser<< " it exist with 0-based index "<<res;
    }
    return 0;
}
// Output:
// enter the size if array
// 6
// enter the values into array in sorted manner
// 3 5 7 9 44 67
// enter the value of serching item
// 67
// 67 it exist with 0-based index 5