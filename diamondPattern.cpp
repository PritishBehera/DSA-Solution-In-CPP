#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<< "Enter a number:";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int k=n-i;k>0;k--){
            cout<<" ";
        }
        for(int j=0;j<2*i-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
     for(int i=n;i>=1;i--){
        for(int k=0;k<n-i;k++){
            cout<<" ";
        }
        for(int j=0;j<2*i-1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
// Output:
// Enter a number:4
//    *
//   ***
//  *****
// *******
// *******
//  *****
//   ***
//    *