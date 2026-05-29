#include<bits/stdc++.h>
using namespace std;
int ways(int n){
    if(n==0||n==1){
        return 1;
    }
    return ways(n-1)+ways(n-2);
}
int main(){
    int n;
    cout<<"enter the size of of n in '2xn' size area of floor:";
    cin>>n;
    int res= ways(n);
    cout<<res;
    return 0;
}
// Output:
// enter the size of of n in '2xn' size area of floor:4
// 5