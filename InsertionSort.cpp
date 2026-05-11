#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[curr]){// change > to < for descending order array
                swap(arr[j],arr[curr]);
            }
            curr=j;
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
    cout<<"enter values into the array\n";
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    insertionSort(arr,s);
    return 0;
}
// Output:
// enter the size of array
// 5
// enter values into the array
// 4 2 5 1 7
// here is the sorted array
// 1 2 4 5 7 