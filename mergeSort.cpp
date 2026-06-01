#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &vec,int st,int mid, int en){
    vector<int> temp;
    int i=st;
    int j=mid+1;
    while(i<=mid&&j<=en){
        if(vec[i]<vec[j]){
            temp.emplace_back(vec[i++]);
        }else{
            temp.emplace_back(vec[j++]);
        }
    }
    while(i<=mid){
        temp.emplace_back(vec[i++]);
    }
    while(j<=en){
        temp.emplace_back(vec[j++]);
    }
    for(int i=st,x=0;i<=en;i++){
        vec[i]=temp[x++];
    }
}
void mergeSort(vector<int> &vec, int st, int en){
    if(st>=en){
        return;
    }
    int mid = st+(en-st)/2;
    mergeSort(vec,st,mid);
    mergeSort(vec,mid+1,en);
    merge(vec,st,mid,en);
}
int main(){
    vector<int> vec={1,6,3,2,5};
    mergeSort(vec,0,vec.size()-1);
    for(auto it:vec){
        cout<<it<<" ";
    }
    return 0;
}