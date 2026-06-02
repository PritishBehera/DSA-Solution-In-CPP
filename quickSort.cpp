#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &vec,int st,int en){
    int i=st-1;
    int j=st;
    while(j<en){
        if(vec[j]<vec[en]){
            i++;
            swap(vec[i],vec[j]);
        }
        j++;
    }
    i++;
    swap(vec[i],vec[en]);
    return i;
}
void quickSort(vector<int> &vec,int st,int en){
    if(st>=en){
        return;
    }
    int piv = partition(vec,st,en);
    quickSort(vec,st,piv-1);
    quickSort(vec,piv+1,en);
}
int main(){
    vector<int> vec={4,5,2,5,1};
    quickSort(vec,0,vec.size()-1);
    for(int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}