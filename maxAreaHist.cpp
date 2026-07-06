#include<bits/stdc++.h>
using namespace std;

void maxAreaHistogram(vector<int>&vec){
    vector<int> pse;
    vector<int> nse;
    stack<int> st;
    int n=vec.size();
    //pse
    for(int i=0;i<n;i++){
        while(!st.empty()&&vec[i]<=vec[st.top()]){
            st.pop();
        }
        if(st.empty()){
            pse.push_back(-1);
        }else{
            pse.push_back(st.top());
        }
        st.push(i);
    }
    st= stack<int>();
    //nse
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&vec[i]<=vec[st.top()]){
            st.pop();
        }
        if(st.empty()){
            nse.insert(nse.begin(),n);
        }
        else{
            nse.insert(nse.begin(),(st.top()));
        }
        st.push(i);
    }
    int area,maxArea=INT_MIN;
    for(int i=0;i<n;i++){
        area=vec[i]*(nse[i]-pse[i]-1);
        maxArea=max(maxArea,area);
    }
    cout<<maxArea;
}
int main(){
    vector<int> vec={2,1,5,6,2,3};
    maxAreaHistogram(vec);
    return 0;
}