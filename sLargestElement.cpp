#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
      int la= nums[0], sla=INT_MIN;
      bool isslaUsed= false;
      for (auto it: nums){
        if(it>la){
            sla=la;
            la=it;
            isslaUsed=true;
        }else if(it<la&&it>sla){
            sla=it;
            isslaUsed=true;
        }
      }
      if(isslaUsed==false) return -1;
      return sla;
    }
};
int main(){
    vector<int> nums;
    int n,x;
    cout<<"enter the size of array:";
    cin>>n;
    cout<<"enter the values:";
    for(int i=0;i<n;i++){
        cin>>x;
        nums.emplace_back(x);
    }
    Solution obj;
    cout<<obj.secondLargestElement(nums);
    return 0;
}
// Output:
// enter the size of array:5
// enter the values:8 8 5 7 3
// 7