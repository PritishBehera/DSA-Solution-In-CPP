#include<bits/stdc++.h>
using namespace std;
int primes2toN(int n){
    for(int i=2;i<=n;i++){
        int c=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                c++;
                continue;
            };
            
        }
        if(c==2) cout<<i;
    }
};
int main(){
    int n;
    cout<<"enter the range upto which you need to find the primes number:";
    cin>>n;
    primes2toN(n);
    return 0;
}