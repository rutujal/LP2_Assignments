#include<iostream>
#include<bits/stdc++.h>
#define N 8
using namespace std;


void printSolution(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}



bool isSafe(int row,int col,int backSlashCode[N][N],
                           int slashCode[N][N],
                           bool rowLookup[],
                           bool slashCodeLookup[],
                           bool backSlashCodeLookup[]){
    if(backSlashCodeLookup[backSlashCode[row][col]] || slashCodeLookup[slashCode[row][col]] || rowLookup[row]){
        return false;
    }
    return true;
}
bool solveNQUtil(int board[N][N],int col,int backSlashCode[N][N],int slashCode[N][N],bool rowLookup[],bool slashCodeLookup[],bool backslashCodeLookup[]){
    if(col>=N){
        return true;
    }
    for(int i=0;i<N;i++){
        if(isSafe(i,col,backSlashCode,slashCode,rowLookup,slashCodeLookup,backslashCodeLookup)){
            board[i][col]=1;
            rowLookup[i]=true;
            slashCodeLookup[slashCode[i][col]]=true;
            backslashCodeLookup[backSlashCode[i][col]]=true;

            if(solveNQUtil(board,col+1,backSlashCode,slashCode,rowLookup,slashCodeLookup,backslashCodeLookup)){
                return true;
            }
            board[i][col]=0;
            rowLookup[i]=false;
            slashCodeLookup[slashCode[i][col]]=false;
            backslashCodeLookup[backSlashCode[i][col]]=false;
        }
    }
    return false;

}

bool solveNQ(){
    int board[N][N]={0};

    int backSlashCode[N][N];
    int slashCode[N][N];

    bool rowLookup[N]={false};
    bool slashCodeLookup[2*N-1]={false};
    bool backSlashCodeLookup[2*N-1]={false};

    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            slashCode[r][c]=r+c;
            backSlashCode[r][c]=r-c+7;
        }
    }
    if(solveNQUtil(board,0,backSlashCode,slashCode,rowLookup,backSlashCodeLookup,slashCodeLookup)==false){
        cout<<"solution dors not exist"<<endl;
        return false;
    }
    printSolution(board);
    return true;
}


int main(){
    solveNQ();
    return 0;
}

/*
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
*/