#include<bits/stdc++.h>
using namespace std;
bool validPare(vector<char>&vec){
    stack<char> st;
    for(char ch:vec){
        if(ch=='['||ch=='{'||ch=='('){
            st.push(ch);
        }else{
            if(ch=='}'&&st.top()=='{'){
                st.pop();
            }else if(ch==')'&&st.top()=='('){
                st.pop();
            }else if(ch==']'&&st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
    vector<char> vec={'[','{','(',')','}','(',')',']'};
    bool isValid=validPare(vec);
    cout<<isValid;
    return 0;
}