#include<bits/stdc++.h>
using namespace std;
int main(){
   string str ="hellO";
   char ch;
   string vow ="aeiouAEIOU";
   int c=0;
   for(int i=0;i<str.length();i++){
        ch=str.at(i);
        int idx = vow.find(ch);
        if(idx>=0){
            c++;
        }
   }
   cout<<c;
}