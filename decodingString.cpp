#include<bits/stdc++.h>
using namespace std;
string decodeString(string s) {
    stack<char> st;
    string ans;
    for(char ch:s){
        if(ch==']'){
            string str="";
            while(!st.empty()&&st.top()!='['){
                char val=st.top();
                str.insert(str.begin(),val);
                st.pop();
            }
            st.pop();
            string tem="";
            while(!st.empty()&&isdigit(st.top())){
                tem.insert(tem.begin(),st.top());
                st.pop();
            }
            int num = stoi(tem);
            string temp=str;
            for(int i=0;i<num-1;i++){
                str+=temp;
            }
            for(char ch:str){
                st.push(ch);
            }
        }
        else{
            st.push(ch);
        }
    }
    string temp1;
    while(!st.empty()){
        temp1.insert(temp1.begin(),st.top());
        st.pop();
    }
    ans+=temp1;
    return ans;
}
int main(){
    string s = "ab2[cd2[ef]]gh";
    string ans = decodeString(s);
    cout<<ans;
}