#include<bits/stdc++.h>
using namespace std;

bool palindrome(char word[]){
    int n= strlen(word);
    int st=0,en=n-1;
    while(st<en){
        if(word[st]!=word[en]){
            return false;
        }
        st++,en--;
    }
    return true;
}
void toUpper(char word[]){
    int n = strlen(word);
    for(int i=0;word[i]!='\0';i++){
        if(word[i]>='a'&&word[i]<='z'){
            word[i]=word[i]-'a'+'A';
        }
    }
}

int main(){
    int s;
    cout<<"enter the size of char array:";
    cin>>s;
    s++;//this is increased because to able to get extra space for "\0" , it ensures end of char array
    char word[s];
    cout<<"enter values to char array:";
    cin>>word;
    toUpper(word);
    bool isPal = palindrome(word);
    if(isPal){
        cout<<"Yes, "<<word<<" is Palindrome.";
    }else{
        cout<<"No, "<<word<<" is not a Palindrome.";
    } 
    return 0;
}