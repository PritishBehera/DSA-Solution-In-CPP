#include<bits/stdc++.h>
using namespace std;
void nonrepeatedLatter(string str){
    int freq[26]={0};
    queue<char> qu;
    for(char ch:str){
        int id=ch-97;
        freq[id]++;
        qu.push(ch);
        while(!qu.empty()&&freq[qu.front()-97]>1){
            qu.pop();
        }
    }
    if(qu.empty()){
        cout<<"no any single latter appeared once";
        return;
    }
    cout<<qu.front();
}
int main(){
    string str="aaabccxb";
    nonrepeatedLatter(str);
    return 0;
}