#include<bits/stdc++.h>
using namespace std;
//pair can be done using 1 person( simply alone ), add it also one of the case to be pairing
int pairUp(int n){
    //base cases
    if(n==1) return 1;
    if(n==2)return 2;
    //karma
    return pairUp(n-1)+pairUp(n-2)*(n-1);
}
int main(){
    int n;
    cout<<"enter no. of friends to be paired up:";
    cin>>n;
    int res = pairUp(n);
    cout<<"no. of ways can be paired:"<<res;
    return 0;
}
// Output:
// enter no. of friends to be paired up:5
// no. of ways can be paired:26