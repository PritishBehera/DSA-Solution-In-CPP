#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int n= s.length();
    vector<char> vec;
    for(int i=0;i<n;i++){
        char curr = s.at(i);
        if(curr=='('||curr=='{'||curr=='['){
            vec.push_back(curr);
        }else{
            if(vec.empty()) return false;
            char top = vec.back();
            if((curr==')'&&top=='(')||(curr=='}'&&top=='{')||(curr==']'&&top=='[')){
                vec.pop_back();
            }else{
                return false;
            }
        }
    }
    return vec.empty();
}

int main(){
    string str;
    cout<<"enter a string only containing '(','{','[',']','}',')'\n";
    cin>>str;
    bool res = isValid(str);
    if(res){
        cout<<"Yes,"<<str<<" is a valid parentheses";
    }else{
        cout<<"Sorry,"<<str<<" is not a valid parentheses";
    }
    return 0;
}