#include<bits/stdc++.h>
using namespace std;
void subArray(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"(";
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<",";
            }
            cout<<") ";
        }
        cout<<"\n";
    }
}
int main(){
    int arr[]={2,4,5,6,7};
    subArray(arr,(sizeof(arr)/sizeof(int)));
}