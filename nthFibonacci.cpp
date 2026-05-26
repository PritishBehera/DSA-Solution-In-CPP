#include<bits/stdc++.h>
using namespace std;

void print(int n,int i,int j,int c){
    if(c==n-2){
        return;
    }
    cout<<i+j<<"\n";
    c++;
    print(n,j,i+j,c);
    return ;
}
int print(int n){//call it to find the exact number at nth place if the fibonacci series
    if(n== 0||n==1){
        return n;
    }
    return print(n-1) + print(n-2);
}
int main(){
    int n,i=0,j=1;
    cout<<"enter nth number of fibonacci series:";
    cin>>n;
    cout<<i<<"\n"<<j<<"\n";
    print(n,0,1,0);
    return 0;
}
// Output:
// enter nth number of fibonacci series:5
// 0
// 1
// 1
// 2
// 3