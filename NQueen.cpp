#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<char>> board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"------------------------\n";
}

bool isSafe(vector<vector<char>> board,int row,int j){
    int n=board.size();
    //horizontal
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    //vertical
    for(int i=0;i<=row;i++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //left diagonal
    for(int k=row,l=j;k>=0&&l>=0;k--,l--){
        if(board[k][l]=='Q'){
            return false;
        }
    }
    //right diagonal
    for(int k=row,l=j;k>=0&&l<n;k--,l++){
        if(board[k][l]=='Q'){
            return false;
        }
    }
    return true;
}

void nQueen(vector<vector<char>> board,int row){
    int n=board.size();
    //base
    if(row==n){
        printBoard(board,n);
        return;
    }
    //kaam
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
            board[row][j]='Q';
            nQueen(board,row+1);
            board[row][j]='.';
        }
    }
}

int main(){
    vector<vector<char>> board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char> newRow;
        for(int j=0;j<n;j++){
            newRow.emplace_back('.');
        }
        board.emplace_back(newRow);
    }
    nQueen(board,0);
    return 0;
}