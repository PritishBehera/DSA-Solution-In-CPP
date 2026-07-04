#include<bits/stdc++.h>
using namespace std;
void nextGreatEle(vector<int> vec,list<int>&ll){
    int n=vec.size()-1;
    stack<int> st;
    for(int i=n;i>=0;i--){
        while(!st.empty()&& st.top()<vec[i]){
            st.pop();
        }
        if(st.empty()){
            ll.push_front(-1);
        }else{
            ll.push_front(st.top());
        }
        st.push(vec[i]);

    }
}
int main(){
    vector<int> vec={6,8,0,1,3};
    list<int> ll;
    nextGreatEle(vec,ll);
    for(auto itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<" ";
    }
}