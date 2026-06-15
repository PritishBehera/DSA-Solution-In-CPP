#include<bits/stdc++.h>
using namespace std;

void print(int sudoku[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isSafe(int sudoku[9][9],int dig,int row,int col){
    //horizontal
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==dig){
            return false;
        }
    }
    //verticle
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==dig){
            return false;
        }
    }
    //3x3 area
    int stRow=(row/3)*3;
    int stCol=(col/3)*3;
    for(int i=stRow;i<=stRow+2;i++){
        for(int j=stCol;j<=stCol+2;j++){
            if(sudoku[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[9][9],int row,int col){
    if(row==9){
        print(sudoku);
        return true;
    }
    int neRow=row;
    int neCol=col+1;
    if(neCol==9){
        neRow=row+1;
        neCol=0;
    }
    if(sudoku[row][col]!=0){
        return sudokuSolver(sudoku,neRow,neCol);
    }
    for(int dig=1;dig<=9;dig++){
        if(isSafe(sudoku,dig,row,col)){
            sudoku[row][col]=dig;
            if(sudokuSolver(sudoku,neRow,neCol)){
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    return false;
}
int main(){
    int sudoku[9][9] = {
    {0, 0, 8, 0, 0, 0, 0, 0, 0},
    {4, 9, 0, 1, 5, 7, 0, 0, 2},
    {0, 0, 3, 0, 0, 4, 1, 9, 0},
    {1, 8, 5, 0, 6, 0, 0, 2, 0},
    {0, 0, 0, 0, 2, 0, 0, 6, 0},
    {9, 6, 0, 4, 0, 5, 3, 0, 0},
    {0, 3, 0, 0, 7, 2, 0, 0, 4},
    {0, 4, 9, 0, 3, 0, 0, 5, 7},
    {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };
    bool a =sudokuSolver(sudoku,0,0);
    cout<<a;
    return 0;
}