#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> coinz={1,2,5,10,20,50,100,200,500,2000};
    int minChange=0;
    int val=890;//change val according to your intended amount
    vector<int> notes={};
    for(int i= coinz.size()-1;i >= 0 && val > 0;){
        if(val >= coinz[i]){
            val-= coinz[i];
            notes.push_back(coinz[i]);
        }
        if(val>=coinz[i]){
            i++;
        }
        i--;
    }
    for(int it:notes){
        cout<<it<<",";
    }
    cout<<"\nNo. of notes is:"<<(notes.size());
    return 0;
}