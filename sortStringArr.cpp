#include<bits/stdc++.h>
using namespace std;

void merge(string arr[],int st,int mid,int en){
    int i=st,j=mid+1;
    vector<string> ans;
    while(i<=mid&&j<=en){
        string str1=arr[i],str2=arr[j];
        if(str1<str2){
            ans.push_back(str1);
            i++;
        }else{
            ans.push_back(str2);
            j++;
        }
    }
    while(i<=mid){
        ans.push_back(arr[i++]);
    }
    while(j<=en){
        ans.push_back(arr[j++]);
    }
    for(int i=st,x=0;i<=en;i++){
        arr[i]=ans[x++];
    }
}
void mergeSort(string arr[],int st,int en){
    if(st>=en){
        return;
    }
    int mid = st+(en-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,en);
    merge(arr,st,mid,en);
}
int main(){
    string arr[]={"sun","earth","mars","mercury"};
    int n= sizeof(arr)/sizeof(string);
    mergeSort(arr,0,n-1);
    for(auto it:arr){
        cout<<it<<" ";
    }
    return 0;
}