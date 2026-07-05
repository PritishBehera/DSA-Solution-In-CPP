#include<bits/stdc++.h>
using namespace std;
bool duplicateParenthesis(string str){
    stack<int> st;
    for(char ch:str){
        if(ch!=')'){
            st.push(ch);
        }else{
            if(st.top()=='('){
                return false;
            }
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
            continue;
        }
    }
    return st.empty();
}
int main(){
    string str="((a+b)+c)";
    bool isValid=duplicateParenthesis(str);
    cout<<isValid;
    return 0;
}