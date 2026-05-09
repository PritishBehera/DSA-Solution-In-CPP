#include<bits/stdc++.h>
using namespace std;
bool duplicate(int nums[],int s){
    unordered_set <int> us;
    for(int i=0;i<s;i++){
        if(us.count(nums[i])){
            return true;
        }
        us.insert(nums[i]);
    }
    return false;
}
int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    int arr[s];
    cout<<"enter values into the array\n";
    for(int i=0;i<s;i++){
        cin>>arr[i];
    }
    bool res = duplicate(arr,s);
    if(res){
        cout<<"Duplicate value exist.";
    }else{
        cout<<"Duplicate value doesn't exist";
    }
    return 0;
}
// Output:
// enter the size of array
// 6
// enter values into the array
// 4 6 7 3 5 8
// Duplicate value doesn't exist