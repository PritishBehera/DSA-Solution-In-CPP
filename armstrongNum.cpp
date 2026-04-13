#include<bits/stdc++.h>
using namespace std;
int main(){
    // int n,sum=0;
    // vector<int> v;
    // cin>>n;
    // int c=n;
    // while(n>0){
    //     int va = n%10;
    //     n=n/10;
    //     v.push_back(va);
    // }
    // int l= v.size();
    // for(auto i: v){
    //     // cout<<i<<"\n";
    //     sum+=pow(i,l);
    // }
    // // cout<<sum;
    // if(sum==c){
    //     cout<<"Armstrong";
    // }
    // else{
    //     cout<<"Not armstrong";
    // }
    int n,sum=0;
    cin>>n;
    int c=n;
    int len = to_string(n).size();
    while(n>0){
        int d= n%10;
        n=n/10;
        sum+=pow(d,len);
    }
    if(c==sum){
        cout<<"Armstrong Number";
    }else{
        cout<<"Not a Armstrong Number";
    }
    return 0;
}

// Output:  n=371
// Armstrong Number