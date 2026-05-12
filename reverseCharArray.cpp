#include<bits/stdc++.h>
using namespace std;

void reverse(char word[]){
    int n= strlen(word);
    int st=0,en=n-1;
    while(st<=en){
        swap(word[st],word[en]);
        st++,en--;
    }
    cout<<"Reverse will be "<<word;
}

int main(){
    int s;
    cout<<"enter the size of char array:";
    cin>>s;
    s++;//this is increased because to able to get extra space for "\0" , it ensures end of char array
    char word[s];
    cout<<"enter values to char array:";
    cin>>word;
    reverse(word);
    return 0;
}
// Output:
// enter the size of char array:14
// enter values to char array:olleH
// Reverse will be Hello