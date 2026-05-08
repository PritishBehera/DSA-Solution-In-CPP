#include<bits/stdc++.h>
using namespace std;

void waterTrap(int height[],int n){
    int leftMax[20000],rightMax[20000],totalTrap=0;
    leftMax[0]=INT_MIN;
    cout<<leftMax[0];
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],height[i-1]);
        cout<<leftMax[i]<<",";//printing left max values
    }
    cout<<"\n";
    rightMax[n-1]=INT_MIN;
    cout<<rightMax[n-1];
    for(int j=n-2;j>=0;j--){
        rightMax[j]=max(rightMax[j+1],height[j+1]);
        cout<<rightMax[j]<<",";//printing right max values
    }
    cout<<"\n";
    for(int k=0;k<n;k++){
        int minm=min(leftMax[k],rightMax[k]);
        if(minm<0){
            minm=0;
        }
        int trap=minm-height[k];
        cout<<trap<<",";//printing each indexs trap water values
        if(trap<0){
            continue;
        }
        totalTrap+=trap;//multiply trap with widht value if any, in this case width is 1
    }
    cout<<"\n";
    cout<<"Total Water traped is "<<totalTrap;
}

int main(){
    int s;
    cout<<"enter the size of array\n";
    cin>>s;
    int height[s];//height is the array of diff. water bar
    cout<<"enter values into the array\n";
    for(int i=0;i<s;i++){
        cin>>height[i];
    }
    waterTrap(height,s);
    return 0;
}
// Output:
// enter the size of array
// 7 
// enter values into the array
// 4 2 0 6 3 2 5
// -21474836484,4,4,6,6,6,
// -21474836485,5,5,6,6,6,
// -4,2,4,-2,2,3,-5,
// Total Water traped is 11