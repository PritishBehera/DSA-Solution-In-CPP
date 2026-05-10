#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int midx=i;
        for(int j=i;j<n;j++){
            if(arr[midx]>arr[j]){//change > to < for descending order
                midx=j;
            }
        }
        swap(arr[i],arr[midx]);
    }
    cout<<"here is the sorted array:\n";
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
    selectionSort(arr,s);
    return 0;
}
// Output:
// enter the size of array
// 5
// enter values into the array
// 3 5 2 6 2
// here is the sorted array:
// 2 2 3 5 6