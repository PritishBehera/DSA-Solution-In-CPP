#include<bits/stdc++.h>
using namespace std;
void expo(int x,int n){
    int a=x,b=n;
    int ans=1;
    while(n>0){
        int dig = n & 1;
        if(dig==1){
            ans*=x;
        }
        x*=x;
        n=n>>1;
    }
    cout<<a<<" to the power "<<b<<" is "<<ans;
}
int main(){
    int x,n;
    cout<<"enter the x and n value for x^n\n";
    cin>>x>>n;
    expo(x,n);
    return 0;
}
// Output:
// enter the x and n value for x^n
// 3 5
// 3 to the power 5 is 243