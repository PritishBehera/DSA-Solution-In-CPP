#include<bits/stdc++.h>
using namespace std;

void decToBi(long int n){
    vector<char> li;
    while(n>0){
        int rem =n%2;
        li.emplace_back(static_cast<char>('0'+rem));
        n=n/2;
    };
    reverse(li.begin(),li.end());
    string str(li.begin(),li.end());
    cout<<"Binary num is:"<<str;
}

int main(){
    long int n;
    cout<<"Enter a decimal num:";
    cin>>n;
    decToBi(n);
    return 0;
}
// Output:
// Enter a decimal num:4
// Binary num is:100