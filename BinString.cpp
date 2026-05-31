#include<bits/stdc++.h>
using namespace std;
//this code prints all the possible combination of '0' and '1' with size of 'n' provided that consecutive '1's should not be present there 
void biString(int n,int lastBIN,string ans){
    if(n==0){
        cout<<ans<<"\n";
        return;
    }
    if(lastBIN!=1){
        biString(n-1,0,ans+'0');
        biString(n-1,1,ans+'1');
    }else{
        biString(n-1,0,ans+'0');
    }
}
int main(){
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    string ans;
    biString(n,0,ans);
    return 0;
}
// Output:
// enter the value of n:5
// 00000
// 00001
// 00010
// 00100
// 00101
// 01000
// 01001
// 01010
// 10000
// 10001
// 10010
// 10100
// 10101