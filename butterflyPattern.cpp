#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int l=0;l<i;l++){
            cout<<"*";
        }
        for(int j=2*(n-i);j>0;j--){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=n;i>=1;i--){
        for(int l=i;l>0;l--){
            cout<<"*";
        }
        for(int j=0;j<2*(n-i);j++){
            cout<<" ";
        }
        for(int k=i;k>0;k--){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
// Output:
// Enter a number:4
// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *