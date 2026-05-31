#include<bits/stdc++.h>
using namespace std;

void findOccurance(vector<int> vec,int key,int i,int n){
    if(i==n){
        return;
    }
    if(vec[i]==key){
        cout<<i<<"\n";
    }
    findOccurance(vec,key,i+1,n);
}
int main(){
    int n;
    cout<<"enter the size of array:";
    cin>>n;
    vector<int> vec(n);
    cout<<"enter values into vector :";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int key;
    cout<<"enter the key for finding its occurances:";
    cin>>key;
    findOccurance(vec,key,0,n);
    return 0;
}
// o/p:
// enter the size of array:6
// enter values into vector :2 3 5 6 3 3
// enter the key for finding its occurances:3
// 1
// 4
// 5