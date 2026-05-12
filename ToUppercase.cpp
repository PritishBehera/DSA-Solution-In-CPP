#include<bits/stdc++.h>
using namespace std;

void toUppercase(char word[]){
    for(int i=0;word[i]!='\0';i++){
        if(word[i]>='a'&&word[i]<='z'){
            word[i]=word[i]-'a'+'A';
        }
    }
    cout<<"the uppercase will be "<<word;
}

int main(){
    int s;
    cout<<"enter the size of char array:";
    cin>>s;
    cin.ignore();
    s++;//this is increased because to able to get extra space for "\0" , it ensures end of char array
    char word[s];
    cout<<"enter values to char array:";
    cin.getline(word,s,'*');
    toUppercase(word);
    return 0;
}