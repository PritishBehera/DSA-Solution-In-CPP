#include<bits/stdc++.h>
using namespace std;
//binary recursion
int binRecursion(vector<int>& vec,int key,int i, int j){
    if(i>j){
        return -1;
    }
    int mid = (i+j)/2;
    int val=vec[mid];
    if(val==key){
        return mid;
    }
    if(val>key){
        j=mid-1;       
    }else{
        i=mid+1;
    }
    return binRecursion(vec,key,i,j);
}
int main(){
    int n;
    cout<<"enter the size of array:";
    cin>>n;
    vector<int> vec(n);
    cout<<"enter values into vector in sorted manner:";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int key;
    cout<<"enter the key to search:";
    cin>>key;
    int r = binRecursion(vec,key,0,n-1);
    cout<< r;
    return 0;
}
// o/p:
// enter the size of array:5 
// enter values:2 4 6 8 11
// enter the key to search:8
// 3