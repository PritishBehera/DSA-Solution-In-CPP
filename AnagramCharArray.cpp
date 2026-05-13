#include<bits/stdc++.h>
using namespace std;

bool isAnagram(char word1[],char word2[]){
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    if(n1!=n2) return false;
    int freq[91]={};
    for(int i=0;word1[i]!='\0';i++){
        freq[word1[i]]++;
    }
    for(int i=0;word2[i]!='\0';i++){
        freq[word2[i]]--;
        if(freq[word2[i]]<0){
            return false;
        }
    }
    return true;
}

void toUppercase(char word[]){
    for(int i=0;word[i]!='\0';i++){
        if(word[i]>='a'&&word[i]<='z'){
            word[i]=word[i]-'a'+'A';
        }
    }
}

int main(){
    int s;
    cout<<"enter the size of 1st word:";
    cin>>s;
    s++;//this is increased because to able to get extra space for "\0" , it ensures end of char array
    char word1[s];
    cout<<"enter the 1st word:";
    cin>>word1;
    int s2;
    cout<<"enter the size of 2nd word:";
    cin>>s2;
    s2++;
    char word2[s2];
    cout<<"enter values to 2nd word:";
    cin>>word2;
    toUppercase(word1);
    toUppercase(word2);
    bool res = isAnagram(word1,word2);
    if(res){
        cout<<word1<<" and "<<word2<<" are anagram to each other.";
    }else
    {
        cout<<word1<<" and "<<word2<<" are NOT anagram to each other.";
    }
    return 0;
}