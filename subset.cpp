//dont think)
#include<bits/stdc++.h>
using namespace std;

void subsetPrint(string str,string subset){
    //base
    if(str.size()==0){
        cout<<subset<<endl;
        return;
    }
    //karma
    char ch = str.at(0);
    //recurse call
    subsetPrint(str.substr(1,str.size()-1),subset+ch);
    subsetPrint(str.substr(1,str.size()-1),subset);
}
int main(){
    string str ="abc";
    string subset="";
    subsetPrint(str,subset);
    return 0;
}
// o/p:
// abc
// ab
// ac
// a
// bc
// b
// c