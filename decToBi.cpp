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
void decToBi2(long int n){
    int pow=1;
    int bi=0;
    while(n>0){
        int rem = n%2;
        bi+=rem*pow;
        pow*=10;
        n=n/2;
    }
    cout<<"\nBinary value:"<<bi;
}

int main(){
    long int n;
    cout<<"Enter a decimal num:";
    cin>>n;
    decToBi(n);
    decToBi2(n);
    return 0;
}
// Output:
// Enter a decimal num:4
// Binary num is:100