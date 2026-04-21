#include<bits/stdc++.h>
using namespace std;

void biToDec(int n){
    int dec=0,pow=1;
    while(n>0){
        int ldig = n%10;
        dec+=ldig*pow;
        pow*=2;
        n=n/10;
    }
    cout<<"Decimal Num is:"<<dec;
}
int main(){
    int n;
    cout<<"Enter a binary number:";
    cin>>n;
    biToDec(n);
    return 0;
}
// Output:
// Enter a binary number:1111
// Decimal Num is:15