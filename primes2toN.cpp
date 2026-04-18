#include<bits/stdc++.h>
using namespace std;
void primes2toN(int n){
    if(n==1){ cout<<"No primes N=1";}
    for(int i=2;i<=n;i++){
        int c=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                c++;
                continue;
            };
            
        }
        if(c==2) cout<<i<<",";
    }
};
int main(){
    int n;
    cout<<"enter the range upto which you need to find the primes number:";
    cin>>n;
    primes2toN(n);
    return 0;
}
// Output:
// enter the range upto which you need to find the primes number:9
// 2,3,5,7,