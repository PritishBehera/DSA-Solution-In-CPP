#include<bits/stdc++.h>
using namespace std;
void countSort(int arr[],int n){
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    int freq[max+1]={};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=min,j=0;i<=max;i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    cout<<"here is the sorted array\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    int arr[s];
    cout<<"enter only positive values into the array, since count sort works for +ve values\n";
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    countSort(arr,s);
    return 0;
}
// Output:
// enter the size of array
// 7
// enter only positive values into the array, since count sort works for +ve values
// 3 5 8 9 10 3 5
// here is the sorted array
// 3 3 5 5 8 9 10 