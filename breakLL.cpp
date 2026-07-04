#include<bits/stdc++.h>
using namespace std;
void printLL(list<int> li){
    for(auto it=li.begin();it!=li.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<"\n";
}
void breakLL(int m,int n,list<int>&li){
    list<int> cut;
    auto first=li.begin();
    advance(first,m);
    auto last=first;
    advance(last,n);
    cut.splice(cut.begin(),li,first,last);
    printLL(cut);
}
int main(){
    list<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);
    li.push_back(5);
    li.push_back(6);
    li.push_back(7);
    printLL(li);
    int M=2,N=2;//change M and N accr. to your requirement
    breakLL(M,N,li);
    printLL(li);
    return 0;
}